#include <stdio.h>
#include <stdlib.h>
#include "MyHeader.h"


VSpace newVSpace(int max)
{
	VSpace vs;
	
	vs.max = max % 2 == 0 ? max: max + 1;
	vs.count = 0;
	vs.data = (Data*)malloc(sizeof(Data) * vs.max);
	vs.avail = vs.max / 2;
	
	int i;
	for (i = 0; i < vs.avail; ++i)
	{
		vs.data[i].elem = EMPTY;
		vs.data[i].link = -1;
	}
	
	for (; i < vs.max - 1; ++i)
	{
		vs.data[i].elem = EMPTY;
		vs.data[i].link = i + 1;
	}
	vs.data[i].elem = EMPTY;
	vs.data[i].link = -1;

	
	return vs;
}

int allocSpace(VSpace *vs)
{
	int retVal = vs->avail;
	vs->avail = vs->data[retVal].link;
	
	return retVal;	 
}

int hash(int val, int max)
{
	return (val % (max/2));
}

bool addElement(VSpace *vs, int elem)
{
    // Check packing density
    if (vs->count >= vs->max / 2)
    {
        // Reallocate if packing density is 80% or more
        vs->max *= 2;
        vs->data = (Data*)realloc(vs->data, sizeof(Data) * vs->max);
        
        // Initialize the new spaces
        for (int i = vs->max/2; i < vs->max; ++i)
        {
            vs->data[i].elem = EMPTY;
            vs->data[i].link = -1;
        }

        // Rehash the existing elements
        for (int i = 0; i < vs->max/2; ++i)
        {
            if (vs->data[i].elem != EMPTY && vs->data[i].elem != DELETED)
            {
                int rehashedElem = vs->data[i].elem;
                vs->data[i].elem = EMPTY; // Empty the current spot
                vs->count--; // Decrement the count as the element will be added back after rehashing
                addElement(vs, rehashedElem); // Recursive call to add element with new max size
            }
        }
    }
    
    int loc = hash(elem, vs->max);

    if(vs->data[loc].elem == elem)
    {
        return false;
    }

    if(vs->data[loc].elem == EMPTY || vs->data[loc].elem == DELETED)
    {
        vs->data[loc].elem = elem;
        vs->count = vs->count + 1;
        return true;
    } else
    {
        int newLoc = allocSpace(vs);
		if(newLoc == -1)
		{
			return false;
		}

        while(vs->data[loc].link != -1)
        {
            loc = vs->data[loc].link;

            if(vs->data[loc].elem == elem)
            {
                return false;
            }
        }

        vs->data[loc].link = newLoc;
        vs->data[newLoc].elem = elem;
        vs->data[newLoc].link = -1;
		vs->count = vs->count + 1;
        return true;
    }
}

bool removeElement(VSpace *vs, int elem)
{

	int loc = hash(elem, vs->max);

	if (vs->data[loc].elem == elem)
	{
		vs->data[loc].elem = DELETED;
		return true;
	}
	return false;

}

void visualize(VSpace vs)
{
	int i, half = vs.max/2;
	printf("%5s | %5s | %5s %10s %5s | %5s | %5s \n", "INDEX", "DATA", "LINK", "", "INDEX", "DATA", "LINK");
	printf("---------------------            --------------------- \n");
	for(i = 0; i < half; ++i)
	{
		printf("%5d | %5d | %5d %10s %5d | %5d | %5d \n",
			i, vs.data[i].elem, vs.data[i].link, "",
			i + half, vs.data[i+half].elem, vs.data[i+half].link);
	}
	printf("\n");
}


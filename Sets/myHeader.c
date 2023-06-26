#include <stdio.h>
#include <stdlib.h>
#include "myHeader.h"

Set newSet()
{
	Set s;
	int i;
	
	for (i = 0; i < MAX; i++)
	{
		s.elems[i] = false;
	}
	s.count = 0;
	
	return s;
}

bool addElement(Set *s, int item)
{
	if (item >= 0 && item < MAX)
	{
		if (!(s->elems[item]))
		{
			s->count = s->count + 1;
		}
		s->elems[item] = true;
		return true;
	}
	return false;
}

bool removeElement(Set *s, int item)
{
	if (item >= 0 && item < MAX)
	{
		if (!(s->elems[item]))
		{
			return false;
		}
		s->elems[item] = false;
		s->count = s->count - 1;
		return true;
	}
	return false;
}

void displaySet(Set s)
{
    int i;
    
    for (i = 0; i < MAX; i++)
    {
        if (s.elems[i])
        {
            printf("%i ", i);
        }
    }
}

Set unionSet(Set a, Set b)
{
    Set s = newSet();
    int i;
    
    for (i = 0; i < MAX; i++)
    {
        if (a.elems[i] || b.elems[i])
        {
            s.elems[i] = true;
            s.count = s.count + 1;
        }
    }
    return s;
}

Set intersectionSet(Set a, Set b)
{
	Set s = newSet();
	int i;
	
	for (i = 0; i < MAX; i++)
	{
		if (a.elems[i] == true && b.elems[i] == true)
		{
			s.elems[i] = true;
			s.count = s.count + 1;
		}
	}
	return s;
}

Set differenceSet(Set a, Set b)
{
	Set s = newSet();
	int i;
	
	for (i = 0; i < MAX; i++)
	{
		if (a.elems[i] && !b.elems[i])
		{
			s.elems[i] = true;
			s.count = s.count + 1;
		}
	}
	return s;
}

Set symmetricDiffSet(Set a, Set b)
{
    return unionSet(differenceSet(a, b), differenceSet(b, a));
}

int cardinality(Set s)
{
	return s.count;
}

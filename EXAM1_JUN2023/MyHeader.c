#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyHeader.h"

int allocSpace(VSpace *vs) {
	int loc = vs->avail;
	
	if(loc != -1) {
		vs->avail = vs->data[loc].pos;
	}
	
	return loc;
}

void freeSpace(VSpace *vs, int loc) {
	if(loc != -1 && loc < MAX_SPACE) {
		vs->data[loc].pos = vs->avail;
		vs->avail = loc;
	}
}

void displayPokemon(Pokemon p) {
	printf("{%d | %s - ", p.pokeID, p.pokeName);
	displayType(p.pokeType.mainType);
	printf("}\n");
}

void displayPokemonDetail(Pokemon p) {
	printf("%10s: %d\n", "ID", p.pokeID);
	printf("%10s: %s\n", "Name", p.pokeName);
	printf("");
}

void displayType(int type) {
	int i;
	String typeNames[18] = {"Normal", "Fire", "Water", "Grass", 
					"Electric", "Ice", "Fighting", "Poison",
					"Ground", "Flying", "Psychic", "Bug",
					"Rock", "Ghost", "Dark", "Dragon",
					"Steel", "Fairy"};
	
	printf("[");
	for (i = 0; i < 18; i++)
	{
		if ((type >> i) % 2)
		{
			printf("%s ", typeNames[i]);
		}
	}
	printf("] ");
}

VSpace newVSpace() {
	VSpace vs;
	int i;
	
	for(i = MAX_SPACE - 1; i >= 0; --i) {
		vs.data[i].dataDetail.pokeID = -1;	// will tag it as empty
		vs.data[i].pos = i-1;
	}
	vs.avail = MAX_SPACE - 1;
	
	return vs;
}

Tile newTile() {
	Tile t;
	
	t.start = 0;
	t.end = 0;
	
	return t;
}

Deck newDeck() {
	Deck d;
	
	d.stack = newStackList();
	d.space = newVSpace();
	
	return d;
}

StackPokemonList newDiscard(int size) {
	StackPokemonList list;
	
	list.max = size;
	list.count = 0;
	list.pokeList = malloc(sizeof(Pokemon) * list.max);
	
	return list;
}

StackList newStackList() {
	return -1;	
}

void initPokedex(Pokedex *p) {
	*p = NULL;
}

GameUser newGameUser(String playerName) {
	GameUser user;
	
	user.playerDeck = newDeck();
	user.playerTile = newTile();
	user.playerDiscard = newDiscard(MAX_POKEMON);
	
	strcpy(user.playerName, playerName);
	
	return user;
}

void displayPokemonArrayList(PokemonList pokeList) {
    printf("{\n");
    for(int i = 0; i < pokeList.count; i++) {
        displayPokemon(pokeList.pokeList[i]);
    }
    printf("}\n");
}

void displayPokemonStackArrayList(StackPokemonList pokeList) {
    printf("{\n");
    for(int i = 0; i < pokeList.count; i++) {
        displayPokemon(pokeList.pokeList[i]);
    }
    printf("}\n");
}

void displayPokemonLinkedList(Pokedex p) {
    printf("{\n");
    while(p != NULL) {
        displayPokemon(p->dataInfo);
        p = p->link;
    }
    printf("}\n");
}

void displayPokemonCircularArray(Tile t) {
    printf("{\n");
    for(int i = t.start; i != t.end; i = (i + 1) % MAX_POKEMON) {
        displayPokemon(t.list[i]);
    }
    printf("}\n");
}

void displayPokemonDeck(VSpace vs, StackList list) {
    printf("{\n");
    int i = list;
    while(i != -1 && i < MAX_SPACE && vs.data[i].dataDetail.pokeID != -1) {
        displayPokemon(vs.data[i].dataDetail);
        i = vs.data[i].pos;
    }
    printf("}\n");
}

void displayGameUser(GameUser user) {
	printf("Player Name: %s\n", user.playerName);
	printf("Pokemon on Deck\n");
	displayPokemonDeck(user.playerDeck.space, user.playerDeck.stack);
	printf("Pokemon on Tile\n");
	displayPokemonCircularArray(user.playerTile);
	printf("Pokemon on Graveyard\n");
	displayPokemonArrayList(user.playerDiscard);
}

Type newType(int type) {
	Type t;
	
	t.mainType = type;
	t.resistantTo = t.strongAgainst = t.vulnerableTo = t.weakAgainst = 0;
	
	return t;
}

void initStat(Stat s, int hp, int attack, int defense, int sa, int sd, int speed, int oad) {
	s[0] = hp;
	s[1] = attack;
	s[2] = defense;
	s[3] = sa;
	s[4] = sd;
	s[5] = speed;
	s[6] = oad;
} 

Pokemon newPokemon(int pokeID, String pokeName, Type pokeType, Stat pokeStats) {
	Pokemon p;
	
	p.pokeID = pokeID;
	strcpy(p.pokeName, pokeName);
	p.pokeType = pokeType;
	memcpy(p.pokeStats, pokeStats, sizeof(int) * 7);
	
	return p;
}

void addPokemon(Pokedex *dex, Pokemon p) {
	Pokedex temp = malloc(sizeof(NodePM));
	
	if(temp != NULL) {
		temp->dataInfo = p;
		temp->link = *dex;
		*dex = temp;
	}
}

// Resurrects a Pokemon by ID, adding it to the player's tile
void resurrect(GameUser *user, int pokemonID) {
    // Search through the discard pile for the Pokemon with the given ID
    for(int i = 0; i < user->playerDiscard.count; i++) {
        if(user->playerDiscard.pokeList[i].pokeID == pokemonID) {
            // If the Pokemon is found, add it to the front of the tile (assuming start of tile is at index 0)
            for(int j = user->playerTile.end; j > user->playerTile.start; j--) {
                user->playerTile.list[j] = user->playerTile.list[j-1]; // Shift other Pokemon to the right
            }
            user->playerTile.list[user->playerTile.start] = user->playerDiscard.pokeList[i]; // Add resurrected Pokemon to front
            user->playerTile.end++; // Update end of tile

            // Remove the Pokemon from the discard pile by shifting others to fill the gap
            for(int j = i; j < user->playerDiscard.count - 1; j++) {
                user->playerDiscard.pokeList[j] = user->playerDiscard.pokeList[j+1];
            }
            user->playerDiscard.count--; // Update discard count

            break;
        }
    }
}

// Summons the highest rated Pokemon from the deck to the middle of the tile
void summon(GameUser *user) {
    // Find the Pokemon with the highest rating in the deck
    int highestRating = -1;
    int highestRatingIndex = -1;
    for(int i = 0; i < MAX_SPACE; i++) {
        if(user->playerDeck.space.data[i].dataDetail.pokeStats[6] > highestRating) { // Assume 6th index is rating
            highestRating = user->playerDeck.space.data[i].dataDetail.pokeStats[6];
            highestRatingIndex = i;
        }
    }
    if(highestRatingIndex != -1) { // If a highest rated Pokemon is found
        // Calculate the middle index of the tile
        int middleIndex = user->playerTile.start + (user->playerTile.end - user->playerTile.start) / 2;

        // Shift the right half of the tile to the right to make space
        for(int j = user->playerTile.end; j > middleIndex; j--) {
            user->playerTile.list[j] = user->playerTile.list[j-1];
        }
        // Add the highest rated Pokemon to the middle of the tile
        user->playerTile.list[middleIndex] = user->playerDeck.space.data[highestRatingIndex].dataDetail;
        user->playerTile.end++; // Update end of tile

        // Remove the summoned Pokemon from the deck
        freeSpace(&user->playerDeck.space, highestRatingIndex);
    }
}

void addPokemonToStack(StackPokemonList *list, Pokemon p) {
    if (list->count < list->max) {
        list->pokeList[list->count++] = p;
    } else {
        printf("Stack is full. Cannot add more Pokemon.\n");
    }
}

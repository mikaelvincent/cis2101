#include <stdio.h>
#include <stdlib.h>
#include "MyHeader.h"

int main(int argc, char *argv[]) {
	Pokedex p;
	GameUser user1 = newGameUser("Godwin Monserate");
	
	initPokedex(&p);
	addPokemon(&p, newPokemon(1, "Balbasaur", newType(136), (Stat){1,1,1,1,1,1,1}));
	addPokemon(&p, newPokemon(2, "Ivysaur", newType(136), (Stat){2,2,2,2,2,2,2}));
	addPokemon(&p, newPokemon(3, "Venusaur", newType(136), (Stat){3,3,3,3,3,3,3}));
	
	printf("Pokedex\n");
	displayPokemonLinkedList(p);
	
	system("PAUSE");
	system("CLS");
	
	// Add pokemon to GameUser's discard stack
	addPokemonToStack(&user1.playerDiscard, newPokemon(4, "Charmander", newType(2), (Stat){39,52,43,60,50,65,100}));
	addPokemonToStack(&user1.playerDiscard, newPokemon(5, "Charmeleon", newType(2), (Stat){58,64,58,80,65,80,100}));
	addPokemonToStack(&user1.playerDiscard, newPokemon(6, "Charizard", newType(2), (Stat){78,84,78,109,85,100,100}));
	
	// Resurrect a pokemon
	resurrect(&user1, 5); // Resurrect Charmeleon
	
	// Add pokemon to GameUser's deck
	int deckPos = allocSpace(&user1.playerDeck.space);
	if(deckPos != -1) {
		user1.playerDeck.space.data[deckPos].dataDetail = newPokemon(7, "Squirtle", newType(4), (Stat){44,48,65,50,64,43,100});
		user1.playerDeck.stack = deckPos; // Assuming stack is only 1 card deep for this example
	}

	// Summon a pokemon from deck
	summon(&user1);

	printf("Player\n");
	displayGameUser(user1);
	
	system("PAUSE");
	system("CLS");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stdio.h"
#include "list.h"

int main() {
    srand(time(NULL));
    // empty list
    struct Pokemon *poke_list = NULL; 
      
    // testing print_list

    // printing empty list
    print_list(poke_list);
    // creating a linked list 
    printf("Pokemon Showdown!!!\n");
    printf("inserting pokemon contestants...\n");
    struct Pokemon *poke0 = insert_front(poke_list, "Charmander", abs(rand()/10000000));
    struct Pokemon *poke1 = insert_front(poke0, "Bulbasaur", abs(rand()/10000000));
    struct Pokemon *poke2 = insert_front(poke1, "Squirtle", abs(rand()/10000000));
    struct Pokemon *poke3 = insert_front(poke2, "Charizard", abs(rand()/10000000));
    struct Pokemon *poke4 = insert_front(poke3, "Pikachu", abs(rand()/10000000));
    struct Pokemon *poke5 = insert_front(poke4, "MewTwo", abs(rand()/10000000));
    printf("printing linked list of contestants...\n");
    // printing filled list
    print_list(poke5);
    printf("\n");

    // testing remove_Pokemon

    // removing a contestant 
    printf("removing a contestant from the list\n");
    printf("removing Charizard\n");
    poke_list = remove_Pokemon(poke5, poke3->name, poke3->hp);
    printf("contestants left...\n");
    print_list(poke_list);
    printf("\n");

    // removing a contestant
    printf("removing a contestant from the list\n");
    printf("removing MewTwo\n");
    poke_list = remove_Pokemon(poke_list, poke5->name, poke5->hp);
    printf("contestants left...\n");
    print_list(poke_list);
    printf("\n");

    // removing a contestant
    printf("removing a contestant from the list\n");
    printf("removing Charmander\n");
    poke_list = remove_Pokemon(poke_list, poke0->name, poke0->hp);
    printf("contestants left...\n");
    print_list(poke_list);
    printf("\n");

    // removing a contestant not on the list
    printf("removing a contestant not on the list\n");
    printf("removing Ditto\n");
    poke_list = remove_Pokemon(poke_list, "Ditto", 10);
    printf("contestants left...\n");
    print_list(poke_list); 
    printf("\n");

    // Freeing list 
    printf("freeing list...\n");
    printf("it started to rain; no showdown today :(\n");
    poke_list = free_list(poke_list);

    // printing empty list
    printf("contestants left...\n");
    print_list(poke_list);     

    return 0;  
}
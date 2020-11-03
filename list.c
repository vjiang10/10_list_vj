#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct Pokemon *poke (char *n, int h) {

    struct Pokemon *np;

    np = malloc(sizeof(struct Pokemon));

    strncpy(np->name, n, sizeof(np->name)-1);
    np->hp = h;
    np->next = NULL;

    return np;
}

void poke_print (struct Pokemon *poke) {
    printf("%s has %d healthpoints\n", poke->name, poke->hp);
}

void poke_damage (struct Pokemon *poke, int damage) {
    int n = poke->hp;
    if (n < damage) {
        poke->hp = 0;
        printf("%s faints\n", poke->name);
    }
    else {
        poke->hp -= damage;
        printf("%s has %d healthpoints left\n", poke->name, poke->hp);
    }
}

// start of 10_list assignment 
void print_list(struct Pokemon *poke) {
    while(poke) {
        poke_print(poke);
        poke = poke->next;
    }
}

struct Pokemon *insert_front(struct Pokemon *p, char *n, int h) {
    struct Pokemon *np = poke(n, h);
    np->next = p;
    return np;  
}

struct Pokemon *free_list(struct Pokemon *poke) {
    struct Pokemon *remover;

    while (poke) {
        printf("freeing: %s\n", poke->name);
        remover = poke->next;
        free(poke);
        poke = remover;       
    }
    return poke;
}

struct Pokemon *remove_Pokemon(struct Pokemon *front, char *n, int h) {
    struct Pokemon *first = front;
    struct Pokemon *before = front;
    if (!strcmp(front->name, n) && front->hp == h) {
        free(front);
        return front->next;
    }
    
    while (front) {
        if (!strcmp(front->name, n) && front->hp == h) {
            before->next = front->next;
            free(front);
            return first;
        }
        before = front;
        front = front->next;
    }
    return first;
}

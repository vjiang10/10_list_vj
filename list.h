#ifndef LIST_H
#define LIST_H

struct Pokemon {
    char name[256];
    int hp;
    struct Pokemon *next;
};  

struct Pokemon *poke(char *n, int h);

void poke_print(struct Pokemon *poke);

void poke_damage(struct Pokemon *poke, int damage);

void print_list(struct Pokemon *poke);

struct Pokemon *insert_front(struct Pokemon *poke, char *n, int h);

struct Pokemon *free_list(struct Pokemon *poke);

struct Pokemon *remove_Pokemon(struct Pokemon *front, char *n, int h);

#endif
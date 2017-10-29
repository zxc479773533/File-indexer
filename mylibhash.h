/*
* My Hash table library
* AUTHOR: Yue Pan zxc479773533@gmail.com
*/

#ifndef __HASH_H
#define __HASH_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHLEN 512

// the hash node struct
typedef struct HashNode{
    int count;
    char str[512];
    struct HashNode *next;
} HashNode;

// input:a string
// output:hash value
int HashFunc(char *str) {
    int value = 0;
    while (*str != '\0')
        value += *(str++);
    if (value >= HASHLEN)
        value %= HASHLEN;
    return value;
}

// input:Hash table
// output:none
void InitHash(HashNode **HashTable) {
    int i;
    for (i = 0; i < HASHLEN; i++) {
        HashTable[i] = (HashNode *)malloc(sizeof(HashNode));
        HashTable[i]->count = 0;
        HashTable[i]->next = NULL;
    }
}

// input:Hash table, string
// output:status
int InsertHash(HashNode **HashTable, char *str) {
    int states = 0;
    int index = HashFunc(str);
    HashNode *p = HashTable[index]->next;
    while (p != NULL) {
        if (strcmp(str, p->str) == 0) {
            p->count++;
            break;
        }
        p = p->next;
    }
    if (p == NULL) {
        HashNode *q = (HashNode *)malloc(sizeof(HashNode));
        if (q == NULL)
            return -1;
        q->count = 1;
        strcpy(q->str, str);
        q->next = HashTable[index]->next;
        HashTable[index]->next = q;
        states = 1;
    }
    return states;
}

// input:Hash table, the database file
// output:none
void SaveHash(HashNode **HashTable, FILE *fp) {
    int i;
    for (i = 0; i < HASHLEN; i++) {
        HashNode *p = HashTable[i]->next;
        while (p != NULL) {
            HashNode *q = p;
            fprintf(fp, "%s:%d\n", p->str, p->count);
            p = p->next;
            free(q);
        }
    }
}

#endif // !__HASH_H
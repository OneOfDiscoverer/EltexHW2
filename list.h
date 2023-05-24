#ifndef _LIST_H
#define _LIST_H

#ifndef STR_LEN
#define STR_LEN 256
#endif

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct book 
{
    void* pointer;
    char name[STR_LEN];
    char protorype[STR_LEN];
}typedef book;

struct list
{
    void *ptr;
    book bk;
}typedef list;

static list* head = 0;

list* getAt(int id);
void pushBack(void *ptr);
int remove_at(int num);
#endif
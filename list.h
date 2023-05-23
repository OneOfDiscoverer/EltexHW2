#ifndef _LIST_H
#define _LIST_H

#define STR_LEN 16

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct book 
{
    char name[256];
    char protorype[256];
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
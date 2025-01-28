#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __LIST_H__
#define __LIST_H__

typedef struct Element* listtype;

struct Element {
    struct Element *prev;
    char *name;
    const char *type;
};

const char* integer = "int";
const char* character = "char";
const char* block = "block";

void initlist(listtype* h, listtype* t);
void addlist(listtype* t, char* name, const char* type);
void print(listtype h, listtype t);
void deleteblock(listtype* t);
listtype searchID(listtype h, listtype t, char* name);
listtype searchIDblock(listtype t, char* name);

#endif

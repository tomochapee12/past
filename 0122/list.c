#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void initlist(listtype* h,listtype* t){
  struct Element *tmp;
  
/* dummy cell */
  tmp = (listtype)malloc(sizeof(struct Element));
  if (tmp == NULL){
    exit(1);
  }
  
  tmp->name ="";
  tmp->prev = NULL;
  tmp->type = block;
  
  *h = *t = tmp;
}

void addlist(listtype* t, char* name, const char* type){
  struct Element *tmp;
  
  tmp = (listtype)malloc(sizeof(struct Element));
  if (tmp == NULL){
    exit(1);
  }
  
  tmp->name = name;
  tmp->type = type;
  tmp->prev = *t;
  
  *t = tmp;
}

void print(listtype h, listtype t){
  listtype tmp;
  
  for(tmp = t; tmp != h; tmp = tmp->prev){
    printf("%s\n", tmp->name);
  }
}

void deleteblock(listtype* t){
  listtype tmp;
  listtype tmp1;
  
  tmp = *t;
  while( tmp->type != block ) {
    tmp1 = tmp->prev;
    free(tmp);
    tmp = tmp1;
  }
  *t = tmp->prev;
  free(tmp);
}

listtype searchID(listtype h, listtype t, char* name){
  listtype tmp;
  
  for(tmp = t; tmp != h; tmp = tmp->prev){
    if (strcmp(tmp->name, name)== 0){
      return tmp;
    }
  }
  return NULL;
}

listtype searchIDblock(listtype t,char* name){
  listtype tmp;
  
  for(tmp = t; tmp->type != block; tmp = tmp->prev){
    if (strcmp(tmp->name, name) == 0){
      return tmp;
    }
  }
  return NULL;
}

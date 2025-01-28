#include <stdio.h>

struct Element {
  struct Element *prev;
  char *e;
};

void initlist(struct Element** h, struct Element** t){
  struct Element *tmp;
  
/* dummy cell */
  tmp = (struct Element*)malloc(sizeof(struct Element));
  if (tmp == NULL){
    exit(1);
  }
  
  tmp->e ="";
  tmp->prev = NULL;
  
  *h = *t = tmp;
}

void addlist(struct Element** t,char* e){
  struct Element *tmp;
  
  tmp = (struct Element*)malloc(sizeof(struct Element));
  if (tmp == NULL){
    exit(1);
  }
  
  tmp->e = e;
  tmp->prev = *t;
  
  *t = tmp;
}

void print(struct Element* h,struct Element* t){
  struct Element* tmp;
  
  for(tmp = t; tmp != h; tmp = tmp->prev){
    printf("%s\n", tmp->e);
  }
}

int main(void){
  struct Element *h, *t;
  
  initlist(&h, &t);
  
  addlist(&t, "abc");
  addlist(&t, "bcd");
  addlist(&t, "cde");
  addlist(&t, "def");
  addlist(&t, "efg");
  
  print(h, t);
  return 0;
}

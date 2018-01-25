#ifndef LIST_H
#define LIST_H
#include <stdbool.h>
#include <stdlib.h>



typedef struct List{
  size_t capacity;
  size_t size;
  void **items;
}List;

List *List_new(void);

void List_free(List **selfPtr);
void * List_get(List *self,int index);
void List_set(List *self,int index,void *ref);
void List_add(List *self,void *ref);
void List_insert(List *self,int index,void *ref);
void List_clear(List *self);
void List_print(List * list);

bool List_remove(List *self,void *ref);
bool List_isEmpty(List *self);
bool List_contains(List *self,void *ref);

int List_count(List *self);
int List_indexOf(List *self,void *ref);
void List_removeAt(List *self,int index);


List * List_filter_by_rating(List * oldList,float rating);





#endif

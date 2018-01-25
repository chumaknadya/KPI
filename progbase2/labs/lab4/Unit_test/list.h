
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>



typedef struct List List;

List *List_new(void);

void List_free(List **selfPtr);
void * List_get(List *self,int index);
void List_set(List *self,int index,void *ref);
void List_add(List *self,void *ref);
void List_insert(List *self,int index,void *ref);


bool List_remove(List *self,void *ref);
bool List_isEmpty(List *self);
bool List_contains(List *self,void *ref);

int List_count(List *self);
int List_indexOf(List *self,void *ref);
void List_removeAt(List *self,int index);


//List * List_filter_by_rating(List * oldList,float rating);

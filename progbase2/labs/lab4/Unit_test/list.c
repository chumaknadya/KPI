#include "list.h"

#define throw(MSG) assert(0 && MSG)

struct List {
  size_t capacity;
  size_t size;
  void **items;
};
static const int initialCapacity = 4;
static void _ensureCapacity(List *self, size_t min);

List *List_new(void) {
  List *self = (List *)malloc(sizeof(List));
  self->capacity = initialCapacity;
  self->size = 0;
  self->items = (void **)malloc(0);
  _ensureCapacity(self, 0);
  return self;
}

void List_free(List **selfPtr) {
  if (selfPtr == NULL) {
    throw("Null point on free()");
  }
  List *self = *selfPtr;
  free(self->items);
  free(self);
  *selfPtr = NULL;
}

void *List_get(List *self, int index) {
  if (index < 0 || index >= self->size) {
    throw("Index out of bounds");
  }
  return self->items[index];
}

void List_set(List *self, int index, void *ref) {
  if (ref == NULL) {
    throw("NULL reference");
  }
  if (index < 0 || index >= self->size) {
    throw("Index out of bounds");
  }
  self->items[index] = ref;
}

void List_add(List *self, void *ref) {
  if (ref == NULL) {
    throw("NULL reference");
  }
  if (self->size <= self->capacity)  {
    _ensureCapacity(self, self->size + 1);
  }
  List_set(self, self->size++, ref);
}

void List_insert(List *self, int index, void *ref) {
  if (ref == NULL) throw("NULL reference");
  if (index > self->size) throw("Argument out of range");
  // problems
  if (self->size >= self->capacity - 1) {
      _ensureCapacity(self, self->size + 1);
  }
  self->size++;
  for(int i = self->size -1;i>= index;i--) {
    self->items[i+1] =self->items[i];
  }
  List_set(self,index,ref);
  //self->items[index] = ref;
}

int List_indexOf(List *self, void *ref) {
  if (ref == NULL) {
    throw("NULL reference");
  }
  for (int i = 0; i < self->size; i++) {
    if (self->items[i] == ref) {
      return i;
    }
  }
  return -1;
}

bool List_contains(List *self, void *ref) {
  if (ref == NULL) {
    throw("NULL reference");
  }
  return List_indexOf(self, ref) >= 0;
}

bool List_remove(List *self, void *ref) {
  if (ref == NULL) {
    throw("NULL reference");
  }
  int index = List_indexOf(self, ref);
  if (index >= 0)  {
    List_removeAt(self, index);
    return true;
  }
  return false;
}

void List_removeAt(List *self, int index) {
  if (index < 0 || index >= self->size) throw("Index out of bounds");
  for (int i = index;i < self->size-1; i++) {
    self->items[i] = self->items[i+1];
  }
  self->size--;
}

bool List_isEmpty(List *self) {
  return self->size == 0;
}

int List_count(List *self) {
  return self->size;
}


  static void _ensureCapacity(List *self, size_t min) {
  if (self->size <= min)
  {
    int newCapacity = self->size == 0 ? initialCapacity : self->size * 2;
    if (newCapacity < min) newCapacity = min;
    self->capacity = newCapacity;
    size_t newSize = sizeof(void *) * self->capacity;
    self->items = (void **)realloc(self->items, newSize);
  }
}


/* List * List_filter_by_rating(List * oldList,float rating) {
   List * list = List_new();
   for (int i = 0; i < oldList->size; i++) {
     if (Get_rating(oldList->items[i]) <= rating)
      List_add(list,oldList->items[i]);
    }
    return list;
 }*/

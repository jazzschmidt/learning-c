#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void assert(char* msg, char expression) {
  static int assert_nr = 0;
  ++assert_nr;

  if(!expression) {
    fprintf(stderr, "[ERROR] Assertion %d failed: %s\n", assert_nr, msg);
  }
}

int main(int argc, char const *argv[]) {
  intlist list = il_create();
  assert("Size is 0", list.size == 0);

  il_push(&list, 123);
  assert("Size is 1", list.size == 1);

  il_push(&list, 456);
  assert("Size is 2", list.size == 2);

  il_pop(&list);
  assert("Size is 1", list.size == 1);

  return 0;
}

intlist il_create() {
  return (intlist){.size=0};
}

long il_push(intlist* list, int value) {
  list->elements = realloc(list->elements, ++list->size * sizeof(int));
  return list->size;
}

int il_get(intlist* list, long index) {
  return 0;
}

void il_pop(intlist* list) {
  
}

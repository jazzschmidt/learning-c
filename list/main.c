#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void assert(char* msg, long actual, char expression) {
  static int assert_nr = 0;
  ++assert_nr;

  if(!expression) {
    fprintf(stderr, "[ERROR] Assertion %d failed\n", assert_nr);
    fprintf(stderr, "[ERROR] Expected: %s\n", msg);
    fprintf(stderr, "[ERROR] Actual:   %ld\n", actual);
  }
}

int main(int argc, char const *argv[]) {
  intlist list = il_create();
  assert("Size is 0", list.size, list.size == 0);

  il_push(&list, 123);
  assert("Size is 1", list.size, list.size == 1);

  int first = il_get(&list, 0);
  assert("First element is 123", first, first == 123);

  il_push(&list, 456);
  assert("Size is 2", list.size, list.size == 2);

  int last = il_get(&list, 1);
  assert("Last element is 456", last, last == 456);

  il_pop(&list);
  assert("Size is 1", list.size, list.size == 1);

  return 0;
}

intlist il_create() {
  return (intlist){.size=0};
}

long il_push(intlist* list, int value) {
  list->elements = realloc(list->elements, ++list->size * sizeof(int));
  int *ptr = list->elements + (list->size-1);
  *ptr = value;

  return list->size;
}

int il_get(intlist* list, long index) {
  int *ptr = list->elements;
  ptr += index;

  return *ptr;
}

void il_pop(intlist* list) {
  list->elements = realloc(list->elements, --list->size * sizeof(int));
}

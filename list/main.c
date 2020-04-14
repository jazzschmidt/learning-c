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

  int item1 = il_get(&list, 0);
  assert("First element is 123", item1, item1 == 123);

  il_push(&list, 456);
  assert("Size is 2", list.size, list.size == 2);

  int item2 = il_get(&list, 1);
  assert("Second element is 456", item2, item2 == 456);

  il_pop(&list);
  assert("Size is 1", list.size, list.size == 1);

  int last = il_get(&list, list.size-1);
  assert("Last element is the first one", last, last == item1);

  return 0;
}

/**
 * Creates an empty list
 */
intlist il_create() {
  return (intlist){.size=0};
}

/**
 * Appends a value to a list and returns its index
 *
 * @return index of the item
 */
long il_push(intlist* list, int value) {
  list->elements = realloc(list->elements, ++list->size * sizeof(int));
  int *ptr = list->elements + (list->size-1);
  *ptr = value;

  return list->size;
}

/**
 * Retrieves a value by its index
 *
 * @return item of the list
 */
int il_get(intlist* list, long index) {
  int *ptr = list->elements;
  ptr += index;

  return *ptr;
}

/**
 * Removes the last element
 */
void il_pop(intlist* list) {
  list->elements = realloc(list->elements, --list->size * sizeof(int));
}

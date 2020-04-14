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
  // Create an empty list
  intlist list = il_create();

  { // List is initially empty
    assert("Size is 0", list.size, list.size == 0);
  }

  { // The item is added to the list
    int index = il_push(&list, 123);
    int item = il_get(&list, 0);

    assert("Size is 1", list.size, list.size == 1);
    assert("First index is 0", index, index == 0);
    assert("First element is 123", item, item == 123);
  }

  { // Another item is added to the list
    int index = il_push(&list, 456);
    int item2 = il_get(&list, 1);

    assert("Size is 2", list.size, list.size == 2);
    assert("Second index is 1", index, index == 1);
    assert("Second element is 456", item2, item2 == 456);
  }

  { // Last element is removed and thus last = first
    il_pop(&list);

    assert("Size is 1", list.size, list.size == 1);

    int first = il_get(&list, 0);
    int last = il_get(&list, list.size-1);

    assert("First item is 123", first, first == 123);
    assert("Last element is the first one", last, last == first);

    int deleted = il_get(&list, 1);
    assert("Deleted item is not 456", deleted, deleted != 456);
  }

  { // Removed element is overwritten when pushing a new one
    int index = il_push(&list, 789);
    int item = il_get(&list, index);

    assert("Index is 1", index, index == 1);
    assert("Element is 789", item, item == 789);
  }

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
  int index = list->size;
  list->elements = realloc(list->elements, ++list->size * sizeof(int));
  int *ptr = list->elements + (index);
  *ptr = value;

  return index;
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
  --list->size;
  *(list->elements + list->size) = 0;
  list->elements = realloc(list->elements, list->size * sizeof(int));
}

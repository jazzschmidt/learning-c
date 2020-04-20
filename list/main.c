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

void assertEquals(char *msg, long actual, long expected) {
  assert(msg, actual, actual == expected);
}

void assertNotEquals(char *msg, long actual, long expected) {
  assert(msg, actual, actual != expected);
}

int main(int argc, char const *argv[]) {
  // Create an empty list
  intlist list = il_create();

  { // List is initially empty
    assertEquals("Size is 0", list.size, 0);
  }

  { // The item is added to the list
    int index = il_push(&list, 123);
    int item = il_get(&list, 0);

    assertEquals("Size is 1", list.size,  1);
    assertEquals("First index is 0", index, 0);
    assertEquals("First element is 123", item, 123);
  }

  { // Another item is added to the list
    int index = il_push(&list, 456);
    int item2 = il_get(&list, 1);

    assertEquals("Size is 2", list.size, 2);
    assertEquals("Second index is 1", index, 1);
    assertEquals("Second element is 456", item2, 456);
  }

  { // Last element is removed and thus last = first
    il_pop(&list);

    assertEquals("Size is 1", list.size, 1);

    int first = il_get(&list, 0);
    int last = il_get(&list, list.size-1);

    assertEquals("First item is 123", first, 123);
    assertEquals("Last element is the first one", last, first);

    int deleted = il_get(&list, 1);
    assertNotEquals("Deleted item is not 456", deleted, 456);
  }

  { // Removed element is overwritten when pushing a new one
    int index = il_push(&list, 789);
    int item = il_get(&list, index);

    assertEquals("Index is 1", index, 1);
    assertEquals("Element is 789", item, 789);
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
  int* elementsPtr = realloc(list->elements, ++list->size * sizeof(int));

  if(elementsPtr != NULL) {
    list->elements = elementsPtr;
  }

  *(list->elements + index) = value;

  return index;
}

/**
 * Retrieves a value by its index
 *
 * @return item of the list
 */
int il_get(intlist* list, long index) {
  return *(list->elements + index);
}

/**
 * Removes the last element
 */
void il_pop(intlist* list) {
  *(list->elements + list->size - 1) = 0;
  int* elementsPtr = realloc(list->elements, list->size * sizeof(int));

  if(elementsPtr != NULL) {
    list->elements = elementsPtr;
  }

  list->size -= 1;
}

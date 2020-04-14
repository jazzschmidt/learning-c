#include <stdio.h>
#include "list.h"

void assert(char* msg, char expression) {
  if(!expression) {
    fprintf(stderr, "[ERROR] Assertion failed: %s\n", msg);
  }
}

int main(int argc, char const *argv[]) {
  intlist list = il_create();

  assert("Size is 0", list.size == 0);

  return 0;
}

intlist il_create() {
  return (intlist){.size=0};
}

long il_add(intlist* list, int value) {
  return 0L;
}

int il_get(intlist* list, long index) {
  return 0;
}

void il_remove(intlist* list, long index) {

}

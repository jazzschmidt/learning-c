#include <stdio.h>
#include <string.h>
#include "pointer.h"

#define MAX_STRING 80

int test_swap() {
  char str1[MAX_STRING], str2[MAX_STRING];
  strcpy(str1, "Hello");
  strcpy(str2, "world");

  strswap(str1, str2);

  if(strcmp(str1, "world") != 0 || strcmp(str2, "Hello") != 0) {
    return 1;
  } else {
    return 0;
  }
}

int test_replace() {
  char actual[MAX_STRING], expected[MAX_STRING];
  strcpy(actual, "UWUWU");
  strcpy(expected, "ETETE");

  strreplace(actual, 'U', 'E');
  strreplace(actual, 'W', 'T');

  if(strcmp(actual, expected) != 0) {
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char const *argv[]) {
  if(test_swap() != 0) {
    printf("Swapping did not success!\n");
    return 1;
  }

  if(test_replace() != 0) {
    printf("Replacing did not success!\n");
    return 1;
  }

  return 0;
}




void strswap(char *str1, char *str2) {
  char str_tmp[MAX_STRING];

  strcpy(str_tmp, str1);
  strcpy(str1, str2);
  strcpy(str2, str_tmp);
}

void strreplace(char *string, char find, char replace) {
  while(*string) {
    if(*string == find) {
      *string = replace;
    }

    ++string;
  }
}

#include <stdio.h>
#include <string.h>
#include "pointer.h"

#define MAX_STRING 80

int main(int argc, char const *argv[]) {
  char str1[MAX_STRING], str2[MAX_STRING];
  strcpy(str1, "Hello");
  strcpy(str2, "world");

  strswp(str1, str2);

  if(strcmp(str1, "world") != 0 || strcmp(str2, "Hello")) {
    printf("Swapping did not success!\n");

    return 1;
  } else {
    printf("Swapping did success!\n");

    return 0;
  }
}




void strswp(char *str1, char *str2) {
  char str_tmp[MAX_STRING];

  strcpy(str_tmp, str1);
  strcpy(str1, str2);
  strcpy(str2, str_tmp);
}

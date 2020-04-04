#include <stdio.h>
#include <string.h>
#include "pointer.h"

int main(int argc, char const *argv[]) {
  char str1[80], str2[80];
  strcpy(str1, "Hello\0");
  strcpy(str2, "world\0");

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
  int str1_len = strlen(str1);
  char str_tmp[str1_len];

  strcpy(str_tmp, str1);
  strcpy(str1, str2);
  strcpy(str2, str_tmp);
}

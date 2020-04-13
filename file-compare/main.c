#include <stdio.h>
#include <stdlib.h>
#include "file-compare.h"

const char *prog_name;

int main(int argc, char const *argv[]) {
  atexit(exit_handler);

  prog_name = argv[0];

  if(argc != 3) {
    fprintf(stderr, "Not sufficient arguments!\n");
    print_usage();
    exit(1);
  }

  char *filename1 = (char *)argv[1];
  char *filename2 = (char *)argv[2];

  FILE *file1 = fopen(filename1, "r");
  FILE *file2 = fopen(filename2, "r");

  if(file1 == NULL) {
    fprintf(stderr, "File %s could not be opened", filename1);
  }
  if(file2 == NULL) {
    fprintf(stderr, "File %s could not be opened", filename2);
  }

  int line = 0;
  int different = 0;
  while(!feof(file1) && !feof(file2)) {
    char c1 = fgetc(file1);
    char c2 = fgetc(file2);

    if(c1 != c2) {
      different = 1;
      break;
    }

    if(c1 == '\n') {
      ++line;
    }
  }

  if(different) {
    printf("First difference found on line %d:\n", line);
  } else {
    printf("No difference found");
  }


  fclose(file1);
  fclose(file2);

  return different;
}

void print_usage() {
  printf("Compares two files for equal content. Exits on the first different line.\n");
  printf("Returns 0 if files are equal, 1 otherwise.");
  printf("USAGE: %s [file1] [file2]\n", prog_name);
}

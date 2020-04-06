#include <stdio.h>
#include <stdlib.h>
#include "file-compare.h"

const char *prog_name;

int main(int argc, char const *argv[]) {
  prog_name = argv[0];

  if(argc != 2) {
    fprintf(stderr, "Not sufficient arguments!\n");
    print_usage();
    exit(1);
  }

  char *filename1 = (char *)argv[1];
  char *filename2 = (char *)argv[2];

  FILE *file1 = fopen(filename1, "r");
  FILE *file2 = fopen(filename1, "r");

  if(file1 == NULL) {
    fprintf(stderr, "File %s could not be opened", file1);
  }
  if(file2 == NULL) {
    fprintf(stderr, "File %s could not be opened", file2);
  }

  while(!feof(file1) && !feof(file2)) {
    
  }

  fclose(file1);
  fclose(file2);
}

void print_usage() {
  printf("Compares two files for equal content. Exits on the first different line.\n");
  printf("USAGE: %s [file1] [file2]\n", prog_name);
}

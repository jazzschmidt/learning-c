#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char input[80];
  const char char_c = 'e';
  short occurrences = 0;

  printf("Input: ");
  gets(input);

  for(int i = 0; i < strlen(input); ++i) {
    char current = input[i];

    if(char_c == current)
      occurrences++;
  }

  // Multiply by 100 to simply calculate percentage without floating numbers
  const short percentage = (occurrences * 100 / strlen(input) * 100) / 100;

  printf("Input contains %i occurences (%i%%) of %c\n", occurrences, percentage, char_c);

  return 0;
}

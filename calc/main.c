#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

#define TRUE 1
#define FALSE 0

const int ARG_NUM1 = 1;
const int ARG_OPERAND = 2;
const int ARG_NUM2 = 3;

int main(int argc, char const *argv[]) {
  if(is_valid_args(argc, argv) == FALSE) {
    print_usage(argv[0]);
    exit(1);
  }

  char operand = *argv[ARG_OPERAND];
  double num1 = atof(argv[ARG_NUM1]);
  double num2 = atof(argv[ARG_NUM2]);

  printf("%.2f\n", calculate(num1, num2, operand));

  return 0;
}



int is_valid_args(int argc, char const *argv[]) {
  if(argc != 4) {
    printf("ERROR: Insufficient amount of arguments!\n");
    return FALSE;
  }

  char operand = *argv[ARG_OPERAND];
  switch (operand) {
    case '+': case '-':
    case 'x': case '/':
      break;
    default:
      printf("ERROR: Unsupported operand: %c\n", operand);
      return FALSE;
  }

  return TRUE;
}

void print_usage(char const prog_name[]) {
  printf("Performs simple calculations.\n");
  printf("USAGE: %s num1 operand num2\n\n", prog_name);
  printf("OPERANDS: + - / x\n\n");
  printf("EXAMPLE: %s 3 + 4\n\n", prog_name);
}

double calculate(double num1, double num2, char operand) {
  switch (operand) {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case 'x': return num1 * num2;
    case '/': return num1 / num2;
    default: return 0;
  }
}

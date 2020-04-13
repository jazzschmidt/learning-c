#include <stdio.h>

enum Weekday {
  Sunday    = 0b1, // 1
  Monday    = 0b10, // 2
  Tuesday   = 0b100, // 4
  Wednesday = 0b1000, // 8
  Thursday  = 0b10000, // 16
  Friday    = 0b100000, // 32
  Saturday  = 0b1000000 // 64
};

int main(int argc, char const *argv[]) {
  int weekend = Saturday|Sunday;

  printf("You can relax on:\n");

  if(weekend & Sunday) { printf("\tSunday\n"); }
  if(weekend & Monday) { printf("\tMonday\n"); }
  if(weekend & Tuesday) { printf("\tTuesday\n"); }
  if(weekend & Wednesday) { printf("\tWednesday\n"); }
  if(weekend & Thursday) { printf("\tThursday\n"); }
  if(weekend & Friday) { printf("\tFriday\n"); }
  if(weekend & Saturday) { printf("\tSaturday\n"); }

  return 0;
}

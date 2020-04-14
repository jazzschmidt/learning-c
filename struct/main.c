#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

int main(int argc, char const *argv[]) {
  struct Point p1 = createPoint(20, 40);
  struct Point p2 = createPoint(30, 15);

  switchPointXY(&p1);
  switchPointXY(&p2);

  validatePointXY(&p1, 40, 20);
  validatePointXY(&p2, 15, 30);

  return 0;
}

struct Point createPoint(int x, int y) {
  return (struct Point){ .x=x, .y=y };
}

void switchPointXY(struct Point* point) {
  int xTmp = point->x;
  point->x = point->y;
  point->y = xTmp;
}

void validatePointXY(struct Point* point, int x, int y) {
  if(point->x != x || point->y != y) {
    fprintf(stderr, "%s\n", "ERROR: Struct values were not switched!");
    exit(1);
  }
}

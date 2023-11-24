#include <ATX2.h>
#define xxplace() (get_place() & 7) - 1
#define xxpart()   get_place() & 8

bool cans[7] = {true, true, true, true, true, true, true};
// bool cans[7] = {1, 0, 1, 0, 0, 0, 0};

void take_can(short idx) {
  cans[idx - 1] = false;
}

short get_closest_can() {
  char closest_left = -1;
  char closest_right = -1;
  for (int i=0; i<xxplace(); i++) {
    if (cans[i]) closest_left = i;
  }
  for (int i=xxplace(); i<7; i++) {
    if (cans[i]) closest_right = i;
  }
  closest_left++; closest_right++;
  if ((xxplace() - closest_left < closest_right - xxplace()) || !closest_right) return closest_left;
  if ((xxplace() - closest_left > closest_right - xxplace()) || !closest_left ) return closest_right;
  return xxpart() ? closest_right : closest_left ;
}

char read_can() {
  return (analog(11) < 300) + (analog(10) < 300) * 2 + (analog(9) < 300) * 4;
}

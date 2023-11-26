#include <ATX2.h>
#define xxplace()  get_place() & 0b0111
#define xxpart()   get_place() & 0b1000

// bool cans[7] = {true, true, true, true, true, true, true};
bool cans[7] = {1, 0, 0, 0, 0, 0, 1};

void take_can(short idx) {
  cans[idx - 1] = 0;
}

char get_closest_can() {
  if (!xxplace()) return 1;
  char closest_left = -1;
  char closest_right = -1;
  for (char i=1; i<(xxplace() - 1); i++) {
    if (cans[i]) { closest_left = i; }
  }
  for (char i=(xxplace() - 1); i<7; i++) {
    if (cans[i]) closest_right = i;
  }
  closest_left++; closest_right++;
  // Edge case for bonus can
  if (!closest_left && !closest_right) return 69;
  if (!closest_left) return closest_right;
  if (!closest_right) return closest_left;
  if ((xxplace() - closest_left < closest_right - xxplace())) return closest_left;
  if ((xxplace() - closest_left > closest_right - xxplace())) return closest_right;
  char out = xxpart() ? closest_right : closest_left ;
  return out == 0 ? 1 : out ;
}

char read_can() {
  return (analog(11) < 300) + (analog(10) < 300) * 2 + (analog(9) < 300) * 4;
}

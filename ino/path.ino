#include <ATX2.h>

#define NORTH 0
#define EAST  1
#define SOUTH 2
#define WEST  3

#define BONUS_CAN_X 4
#define BONUS_CAN_Y 1
#define CAN1_X 5
#define CAN1_Y 1
#define CAN2_1_X 6
#define CAN2_1_Y 2
#define CAN2_2_X 7
#define CAN2_2_Y 3
#define CAN3_X 8
#define CAN3_Y 4
#define CAN4_1_X 7
#define CAN4_1_Y 5
#define CAN4_2_X 6
#define CAN4_2_Y 6
#define CAN5_1_X 5
#define CAN5_1_Y 7
#define CAN5_2_X 4
#define CAN5_2_Y 8
#define CAN6_1_X 3
#define CAN6_1_Y 9
#define CAN6_2_X 2
#define CAN6_2_Y 10
#define CAN7_1_X 1
#define CAN7_1_Y 11
#define CAN7_2_X 0
#define CAN7_2_Y 12

int direction = NORTH;
int x = 3;
int y = 0;

int points[144][2][2] = {{{3, 1}, {5, 1}}, {{3, 1}, {6, 2}}, {{3, 1}, {7, 3}}, {{3, 1}, {8, 4}}, {{3, 1}, {7, 5}}, {{3, 1}, {6, 6}}, {{3, 1}, {5, 7}}, {{3, 1}, {4, 8}}, {{3, 1}, {3, 9}}, {{3, 1}, {2, 10}}, {{3, 1}, {1, 11}}, {{3, 1}, {0, 12}}, {{5, 1}, {6, 2}}, {{5, 1}, {7, 3}}, {{5, 1}, {8, 4}}, {{5, 1}, {7, 5}}, {{5, 1}, {6, 6}}, {{5, 1}, {5, 7}}, {{5, 1}, {4, 8}}, {{5, 1}, {3, 9}}, {{5, 1}, {2, 10}}, {{5, 1}, {1, 11}}, {{5, 1}, {0, 12}}, {{6, 2}, {5, 1}}, {{6, 2}, {7, 3}}, {{6, 2}, {8, 4}}, {{6, 2}, {7, 5}}, {{6, 2}, {6, 6}}, {{6, 2}, {5, 7}}, {{6, 2}, {4, 8}}, {{6, 2}, {3, 9}}, {{6, 2}, {2, 10}}, {{6, 2}, {1, 11}}, {{6, 2}, {0, 12}}, {{7, 3}, {5, 1}}, {{7, 3}, {6, 2}}, {{7, 3}, {8, 4}}, {{7, 3}, {7, 5}}, {{7, 3}, {6, 6}}, {{7, 3}, {5, 7}}, {{7, 3}, {4, 8}}, {{7, 3}, {3, 9}}, {{7, 3}, {2, 10}}, {{7, 3}, {1, 11}}, {{7, 3}, {0, 12}}, {{8, 4}, {5, 1}}, {{8, 4}, {6, 2}}, {{8, 4}, {7, 3}}, {{8, 4}, {7, 5}}, {{8, 4}, {6, 6}}, {{8, 4}, {5, 7}}, {{8, 4}, {4, 8}}, {{8, 4}, {3, 9}}, {{8, 4}, {2, 10}}, {{8, 4}, {1, 11}}, {{8, 4}, {0, 12}}, {{7, 5}, {5, 1}}, {{7, 5}, {6, 2}}, {{7, 5}, {7, 3}}, {{7, 5}, {8, 4}}, {{7, 5}, {6, 6}}, {{7, 5}, {5, 7}}, {{7, 5}, {4, 8}}, {{7, 5}, {3, 9}}, {{7, 5}, {2, 10}}, {{7, 5}, {1, 11}}, {{7, 5}, {0, 12}}, {{6, 6}, {5, 1}}, {{6, 6}, {6, 2}}, {{6, 6}, {7, 3}}, {{6, 6}, {8, 4}}, {{6, 6}, {7, 5}}, {{6, 6}, {5, 7}}, {{6, 6}, {4, 8}}, {{6, 6}, {3, 9}}, {{6, 6}, {2, 10}}, {{6, 6}, {1, 11}}, {{6, 6}, {0, 12}}, {{5, 7}, {5, 1}}, {{5, 7}, {6, 2}}, {{5, 7}, {7, 3}}, {{5, 7}, {8, 4}}, {{5, 7}, {7, 5}}, {{5, 7}, {6, 6}}, {{5, 7}, {4, 8}}, {{5, 7}, {3, 9}}, {{5, 7}, {2, 10}}, {{5, 7}, {1, 11}}, {{5, 7}, {0, 12}}, {{4, 8}, {5, 1}}, {{4, 8}, {6, 2}}, {{4, 8}, {7, 3}}, {{4, 8}, {8, 4}}, {{4, 8}, {7, 5}}, {{4, 8}, {6, 6}}, {{4, 8}, {5, 7}}, {{4, 8}, {3, 9}}, {{4, 8}, {2, 10}}, {{4, 8}, {1, 11}}, {{4, 8}, {0, 12}}, {{3, 9}, {5, 1}}, {{3, 9}, {6, 2}}, {{3, 9}, {7, 3}}, {{3, 9}, {8, 4}}, {{3, 9}, {7, 5}}, {{3, 9}, {6, 6}}, {{3, 9}, {5, 7}}, {{3, 9}, {4, 8}}, {{3, 9}, {2, 10}}, {{3, 9}, {1, 11}}, {{3, 9}, {0, 12}}, {{2, 10}, {5, 1}}, {{2, 10}, {6, 2}}, {{2, 10}, {7, 3}}, {{2, 10}, {8, 4}}, {{2, 10}, {7, 5}}, {{2, 10}, {6, 6}}, {{2, 10}, {5, 7}}, {{2, 10}, {4, 8}}, {{2, 10}, {3, 9}}, {{2, 10}, {1, 11}}, {{2, 10}, {0, 12}}, {{1, 11}, {5, 1}}, {{1, 11}, {6, 2}}, {{1, 11}, {7, 3}}, {{1, 11}, {8, 4}}, {{1, 11}, {7, 5}}, {{1, 11}, {6, 6}}, {{1, 11}, {5, 7}}, {{1, 11}, {4, 8}}, {{1, 11}, {3, 9}}, {{1, 11}, {2, 10}}, {{1, 11}, {0, 12}}, {{0, 12}, {5, 1}}, {{0, 12}, {6, 2}}, {{0, 12}, {7, 3}}, {{0, 12}, {8, 4}}, {{0, 12}, {7, 5}}, {{0, 12}, {6, 6}}, {{0, 12}, {5, 7}}, {{0, 12}, {4, 8}}, {{0, 12}, {3, 9}}, {{0, 12}, {2, 10}}, {{0, 12}, {1, 11}}};
char *steps[] = {"1ff", "0frfrfrf", "0ffrfrfrfrf", "0fffrfrfrfrfrf", "0ffffrfrfrfrf", "0fffffrfrfrf", "1fflfrfffff", "1flfrffffff", "0ffffffff", "0ffffflfrffff", "0ffffffflffrfff", "0ffffffflfffrffff", "0frf", "0ffrfrf", "0fffrfrfrf", "0ffffrfrf", "0fffffrf", "0ffffff", "3frfffffff", "3ffrffffffff", "0ffffflfffrffff", "3frffffffflfffrfff", "3frffffffflffffrffff", "3flf", "0frf", "0ffrfrf", "0fffrf", "0ffff", "3frfffff", "3ffrffffff", "3fffrfffffff", "0fffflffffrffff", "3ffrfffffflfffrfff", "3ffrfffffflffffrffff", "3fflflf", "3flf", "0frf", "0ff", "3frfff", "3ffrffff", "3fffrfffff", "3ffffrffffff", "3frffflffffrffff", "3fffrffffflfffrfff", "3fffrffffflffffrffff", "3ffflflflf", "3fflflf", "3flf", "3frf", "3ffrff", "3fffrfff", "3ffffrffff", "3fffffrfffff", "3ffrfflffffrffff", "3ffffrfffflfffrfff", "3ffffrfffflffffrffff", "3fflflflflf", "3flflflf", "2ff", "2flf", "3frf", "3ffrff", "3fffrfff", "3ffffrffff", "3frflffffrffff", "3fffrffflfffrfff", "3fffrffflffffrffff", "3flflflflflf", "2ffff", "2ffflf", "2fflff", "2flf", "3frf", "3ffrff", "3fffrfff", "3ffffrffff", "3ffrfflfffrfff", "3ffrfflffffrffff", "2ffffff", "2ffffflf", "2fffflff", "2ffflfff", "2fflff", "2flf", "3frf", "3ffrff", "3fffrfff", "3frflfffrfff", "3frflffffrffff", "2ffffffflf", "2fffffflff", "2ffffflfff", "2fffflffff", "2ffflfff", "2fflff", "2flf", "3frf", "3ffrff", "3fffrfff", "3ffffrffff", "2fffffffflff", "2ffffffflfff", "2fffffflffff", "2ffffflfffff", "2fffflffff", "2ffflfff", "2fflff", "2flf", "3frf", "3ffrff", "3fffrfff", "2ffflfffrffffff", "2fffflffffrffff", "2flflflflflflflfffff", "2flflflflflflffffff", "2flflflflflfffff", "2fffflffff", "2ffflfff", "2fflff", "2flf", "3frf", "3ffrff", "2fflffrfffffffflff", "2fflffrffffffflfff", "2fflffrfffffflffff", "2fflffrffffflfffff", "2fflffrfffflffff", "2flflflflflfffff", "2flflflflffff", "2ffflfff", "2fflff", "2flf", "3frf", "2ffflfffrfffffffflff", "2ffflfffrffffffflfff", "2ffflfffrfffffflffff", "2ffflfffrffffflfffff", "2ffflfffrfffflffff", "2fflffrfffflffff", "2fflffrffflfff", "2fffflffff", "2ffflfff", "2fflff", "2flf"};

int m[5] = {400, 400, 400, 400, 400};

bool b(int x) { return analog(x) < m[x]; }
bool w(int x) { return analog(x) > m[x]; }

void cross() {
  while(1) {
         if (b(1) && b(3)) fd(30);
    else if (b(1) && w(3)) fd2(50, 20);
    else if (w(1) && b(3)) fd2(20, 50);
    else if (w(1) && w(3)) break;
  } ao();
  switch (direction) {
    case 0: y++; break;
    case 1: x++; break;
    case 2: y--; break;
    case 3: x--; break;
  }
}

void FF() {
  fd(30); while(w(2)); ao();
}

void FFF() {
  fd(30); delay(500);
}

void LL() {
  fd2(-50, 20); while(b(2)); while(w(2)); while(b(2)); ao();
  direction--;
  if (direction == -1) direction = 3;
}

void RR() {
  fd2(20, -40); while(b(2)); while(w(2)); while(b(2)); ao();
  direction++;
  direction %= 4;
}

void UU() {
  fd2(20, -40); while(b(2)); while(w(2)); while(b(2)); while(w(2)); while(b(2)); ao();
  direction += 2;
  direction %= 4;
}

void set_dir(int new_dir) {
  switch (direction - new_dir) {
    case -3: FF(); LL(); break;
    case -2: FF(); UU(); break;
    case -1: FF(); RR(); break;
    case  0:             break;
    case  1: FF(); LL(); break;
    case  2: FF(); UU(); break;
    case  3: FF(); RR(); break;
  }
}

const char* get_path_str(int start_x, int start_y, int end_x, int end_y) {
  if (start_x == end_x && start_y == end_y) return "";
  int i;
  for (i=0; i<144; i++) {
    if (
      points[i][0][0] == start_x &&
      points[i][0][1] == start_y &&
      points[i][1][0] == end_x   &&
      points[i][1][1] == end_y
    ) break;
  }
  return steps[i];
}

void follow_path_str(char* path) {
  setTextSize(7);
  // Note to self: x - 48 is used to convert number char to int. (eg '0' -> 0)
  // https://simple.m.wikipedia.org/wiki/File:ASCII-Table-wide.svg
  set_dir(path[0] - 48);
  for (int i=1; path[i] != 0; i++) {
    char weijogopgrwaid[] = {path[i], '\0'};
    glcd(1, 1, weijogopgrwaid);
    delay(1000);
    switch (path[i]) {
      case 'f': cross(); break;
      case 'l': FFF(); LL(); break;
      case 'r': FFF(); RR(); break;
      case   0: "what";
    }
  }
}

// yEs, vEry rEadAbLE
void go_to(int xi, int yi) {follow_path_str(get_path_str(x, y, xi, yi));}

void start() {
  FF();
  cross();
}

void setup() {
  glcd(1, 1, get_path_str(3, 1, 2, 10));
  delay(1000);
  OK();
  start();
  go_to(2, 10);
}

void loop() {
}
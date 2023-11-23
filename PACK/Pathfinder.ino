#define NORTH 0
#define EAST  1
#define SOUTH 2
#define WEST  3

// Save memory, it's almost full :[
char xplace = 0;

int strlen(char* str) {
  int i;
  for (i=0; str[i]!='\0'; i++); 
  return i;
}

void to_place(short place) {
  short pos1x, pos1y, pos2x, pos2y;
  switch (place) {
    case 1:
      pos1x = 5; pos1y = 1;
      pos2x = 6; pos2y = 2; break;
    case 2:
      pos1x = 7; pos1y = 3;
      pos2x = 8; pos2y = 4; break;
    case 3:
      pos1x = 8; pos1y = 4;
      pos2x = 7; pos2y = 5; break;
    case 4:
      pos1x = 6; pos1y = 6;
      pos2x = 5; pos2y = 7; break;
    case 5:
      pos1x = 4; pos1y = 8;
      pos2x = 3; pos2y = 9; break;
    case 6:
      pos1x = 2; pos1y = 10;
      pos2x = 1; pos2y = 11; break;
    case 7:
      pos1x = 0; pos1y = 12;
      pos2x = 0; pos2y = 12; break;
  }
  if (
    strlen(
      get_path_str(get_x(), get_y(), pos1x, pos1y)
    ) >
    strlen(
      get_path_str(get_x(), get_y(), pos2x, pos2y)
    )
  ) {
    go_to(pos2x, pos2y);
    // glcd(1, 1, "%d", get_dir());
    if (place <= 2) { set_dir(SOUTH); }
    else { set_dir(EAST); }
    xplace = place | 0b1000;
  } else {
    go_to(pos1x, pos1y);
    if (place <= 2) { set_dir(EAST); }
    else { FF(75); set_dir(NORTH); }
    xplace = place;
  }
}

void to_can(short can) {
  short pos1x, pos1y, pos2x, pos2y;
  switch (can) {
    // Special Case
    case 1:
      go_to(5, 1); set_dir(SOUTH); return;
    case 2:
      pos1x = 6; pos1y = 2;
      pos2x = 7; pos2y = 3; break;
    // Special Case
    case 3:
      go_to(8, 4); set_dir(EAST); return;
    case 4:
      pos1x = 7; pos1y = 5;
      pos2x = 6; pos2y = 6; break;
    case 5:
      pos1x = 5; pos1y = 7;
      pos2x = 4; pos2y = 8; break;
    case 6:
      pos1x = 3; pos1y = 9;
      pos2x = 2; pos2y = 10; break;
    case 7:
      pos1x = 1; pos1y = 11;
      pos2x = 0; pos2y = 12; break;
  }
  if (
    strlen(
      get_path_str(get_x(), get_y(), pos1x, pos1y)
    ) >
    strlen(
      get_path_str(get_x(), get_y(), pos2x, pos2y)
    )
  ) {
    go_to(pos2x, pos2y);
    if (can == 2) { set_dir(SOUTH); }
    else { set_dir(EAST); }
  } else {
    go_to(pos1x, pos1y);
    if (can == 2) { set_dir(EAST); }
    else { FF(75); set_dir(NORTH); }
  }
}

short get_place() { return xplace; }

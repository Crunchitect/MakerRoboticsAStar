#define NORTH 0
#define EAST  1
#define SOUTH 2
#define WEST  3

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
    follow_path_str(get_path_str(get_x(), get_y(), pos2x, pos2y))
    if (place <= 2) { set_dir(SOUTH); }
    else { set_dir(EAST); }
  } else {
    follow_path_str(get_path_str(get_x(), get_y(), pos1x, pos1y))
    if (place <= 2) { set_dir(NORTH); }
    else { set_dir(EAST); ]
  }
}
#include <ATX2.h>

#define NORTH 0
#define EAST  1
#define SOUTH 2
#define WEST  3

#define NumSensorFront 5
uint16_t PinsFront[NumSensorFront] = {0, 1, 2, 3, 4};
uint16_t MaxFront[NumSensorFront] = {900, 900, 900, 900, 900};
uint16_t MinFront[NumSensorFront] = {200, 200, 200, 200, 200};

#define NumSensorBack 3
uint16_t PinsBack[NumSensorBack] = {5, 6, 7};
uint16_t MaxBack[NumSensorBack] = {900, 900, 900};
uint16_t MinBack[NumSensorBack] = {200, 200, 200};

uint32_t _lastPosition;
float Present_Position = 0;
float Errors = 0;
float Previous_Errors = 0;
float Power_Motor = 0;
int LeftMotorSpeed, RightMotorSpeed;
int BaseSpeed; float Kp, Kd;

void grab() {
  FF(75);
  CrossFront();
  fd(30); while(analog(0) > 550);
  servo(1, 30);
  bk(30); while(analog(0) < 550); while(analog(0) > 550); while(analog(0) < 550);
  ao();
  // FF(75);
}

void drop() {
  FF(250);
  ao();
  servo(1, 100);
  ao(); delay(50);
  BB(350);
  ao();
}

void start() {
  servo(1, 100);
  CrossFront();
}

void get_next_can() {
  to_can(get_closest_can());
  take_can(get_closest_can());
  grab();
}

void setup() {
  InitMotor();
  OK();
  BaseSpeed = 100; Kp = 2.4; Kd = 100;
  start();
  // glcdClear();
  take_can(1);
  to_can(1);
  grab();
  to_place(read_can());
  drop();
  get_next_can();
  to_place(read_can());
  drop();
}

void loop() {
  
}

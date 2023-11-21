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
  CrossFront();
  fd(30); while(analog(2) > 550);
  servo(1, 30);
  bk(30); while(analog(2) < 550);
  bk(30); while(analog(2) > 550);
  bk(30); while(analog(2) < 550);
  FF(75);
}

void start() {
  servo(1, 100);
  // FF(150);
  CrossFront();
  // FF(75);
}

void setup() {
  InitMotor();
  OK();
  BaseSpeed = 100; Kp = 2.6; Kd = 100;
  start();
  glcdClear();
  delay(100);
  go_to(5, 1);
  set_dir(SOUTH);
  grab();
  // go_to(5, 7);
  // set_dir(EAST);
  to_place(4);
  servo(1, 100);
}

void loop() {
  
}

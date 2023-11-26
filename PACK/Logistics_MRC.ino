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
  fd(30); while(analog(0) > 550); ao(); delay(100);
  servo(1, 30);
  bk(30); while(analog(0) < 550); while(analog(0) > 550); while(analog(0) < 550);
  FF(15);
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

void deliver_a_can(int cann) {
  to_can(get_closest_can());
  take_can(get_closest_can());
  grab();
  // to_place(read_can());
  to_place(cann);
  ao(); delay(250);
  drop();
}

void setup() {
  InitMotor();
  OK();
  BaseSpeed = 100; Kp = 2.4; Kd = 100;
  start();
  glcdClear();
  deliver_a_can(3);
  deliver_a_can(2);
  deliver_a_can(1);
  deliver_a_can(4);
  deliver_a_can(5);
  deliver_a_can(6);
  deliver_a_can(7);
}

void loop() {}

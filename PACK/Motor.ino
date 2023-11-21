#define pwmA 6
#define dirA 5
#define pwmB 7
#define dirB 4

void InitMotor(){
  pinMode(dirA, OUTPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(dirB, OUTPUT);
  pinMode(pwmB, OUTPUT);
}

void Motors(int LeftSpeed, int RightSpeed){
  if(LeftSpeed >= 0){
    digitalWrite(dirA, LOW);
    analogWrite(pwmA, LeftSpeed);
  } else {
    digitalWrite(dirA, HIGH);
    LeftSpeed = LeftSpeed * (-1);
    analogWrite(pwmA, LeftSpeed);
  }
  if(RightSpeed >= 0){
    digitalWrite(dirB, LOW);
    analogWrite(pwmB, RightSpeed);
  } else {
    digitalWrite(dirB, HIGH);
    RightSpeed = RightSpeed * (-1);
    analogWrite(pwmB, RightSpeed);
  }
}
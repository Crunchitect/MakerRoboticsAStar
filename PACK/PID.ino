int ReadLineFront(){
  bool onLine = false;
  long avg = 0;
  long sum = 0;
  for(int i = 0; i<NumSensorFront; i++){
    long value = map(analog(PinsFront[i]), MinFront[i], MaxFront[i], 0, 1000);
    if(value > 200) onLine = true;
    if(value > 50){
      avg += (long)value * (i * 1000);
      sum += value;
    }
  }
  if(!onLine){
    if(_lastPosition < (NumSensorFront - 1) * 1000 / 2) return 0;
    else return (NumSensorFront - 1) * 1000;
  }
  _lastPosition = avg / sum;
  return _lastPosition;
}

void PidFront(int BaseSpeed, float Kp, float Kd){
  Present_Position = ReadLineFront() / 40;
  Errors = 50 - Present_Position;
  Power_Motor = (Kp * Errors) + (Kd * (Errors - Previous_Errors));
  Previous_Errors = Errors;
  RightMotorSpeed = BaseSpeed + Power_Motor;
  LeftMotorSpeed = BaseSpeed - Power_Motor;
  LeftMotorSpeed = constrain(LeftMotorSpeed, -255, 255);
  RightMotorSpeed = constrain(RightMotorSpeed, -255, 255);
  Motors(LeftMotorSpeed, RightMotorSpeed);
}

int ReadLineBack(){
  bool onLine = false;
  long avg = 0;
  long sum = 0;
  for(int i = 0; i<NumSensorBack; i++){
    long value = map(analog(PinsBack[i]), MinBack[i], MaxBack[i], 0, 1000);
    if(value > 200) onLine = true;
    if(value > 50){
      avg += (long)value * (i * 1000);
      sum += value;
    }
  }
  if(!onLine){
    if(_lastPosition < (NumSensorBack - 1) * 1000 / 2) return 0;
    else return (NumSensorBack - 1) * 1000;
  }
  _lastPosition = avg / sum;
  return _lastPosition;
}

void PidBack(int BaseSpeed, float Kp, float Kd){
  Present_Position = ReadLineBack() / 20;
  Errors = 50 - Present_Position;
  Power_Motor = (Kp * Errors) + (Kd * (Errors - Previous_Errors));
  Previous_Errors = Errors;
  RightMotorSpeed = BaseSpeed - Power_Motor;
  LeftMotorSpeed = BaseSpeed + Power_Motor;
  LeftMotorSpeed = constrain(LeftMotorSpeed, -255, 255);
  RightMotorSpeed = constrain(RightMotorSpeed, -255, 255);
  Motors(-LeftMotorSpeed, -RightMotorSpeed);
}
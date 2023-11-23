int state;
int Pins;
void CrossFront(){
  state = 0;
  while(1){
    PidFront(BaseSpeed, Kp, Kd);
    if(analog(0) > 550 && analog(4) > 550) break;
  }
  ao(); delay(10);
}

void CrossBack(){
  // state = 1;
  while(1){
    PidBack(BaseSpeed, Kp, Kd);
    if(analog(5) > 550 && analog(7) > 550) break;
  }
  ao(); delay(10);
}

void FF(int x){
  Motors(BaseSpeed, BaseSpeed); delay(x);
}

void BB(int x){
  Motors(-BaseSpeed, -BaseSpeed); delay(x);
}

void UU(int x){
  FF(x);
  RR(0);
  RR(0);
}

void RR(int x){
  if(state == 0) {Pins = 4; FF(x);}
  else if(state == 1) {Pins = 7; BB(x);}
  Motors(BaseSpeed, -BaseSpeed); delay(60);
  Motors(BaseSpeed, -BaseSpeed); while(analog(Pins) < 550);
  Motors(BaseSpeed, -BaseSpeed); while(analog(Pins) > 550);
}

void LL(int x){
  if(state == 0) {Pins = 0; FF(x);}
  else if(state == 1) {Pins = 5; BB(x);}
  Motors(-BaseSpeed, BaseSpeed); delay(60);
  Motors(-BaseSpeed, BaseSpeed); while(analog(Pins) < 550);
  Motors(-BaseSpeed, BaseSpeed); while(analog(Pins) > 550);
}

void ST(){
  ao(); while(1);
}
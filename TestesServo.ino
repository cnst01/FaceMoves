#include <Servo.h>
#include <FaceMoves.h>
Servo S;
Servo EyeX;
Servo EyeY;
Servo EsqLid;
Servo DirLid;
Servo EsqEyeBrown;

void setup() {
  // put your setup code here, to run once:
  EyeX.attach(3);
  EyeY.attach(4);
  EsqLid.attach(8);
  DirLid.attach(11);
  Serial.begin(9600);
  EyeX.write(30);
  EyeY.write(50);
  EsqLid.write(15);
  DirLid.write(40);
}

/*
eixo y dos olhos varia de 40 a 100
eixo x 1 a 60
esq fechado = 40 aberto = 15
dir fechado = 1 aberto = 40

*/

void facemoves(int l, int r, int x, int y){
  l = int(((l-100)*7/20) + 15);
  r = int(r*2/5);
  x = int(x*3/5);
  y = int(y*3/5) + 40;
  EyeX.write(l);
  EyeY.write(r);
  EsqLid.write(x);
  DirLid.write(y);
}

void move_to_default(){
  Serial.println("default");
  facemoves(1,1,50,0);
  // EyeX.write(30);
  // EyeY.write(50);
  // EsqLid.write(15);
  // DirLid.write(40);
}

void blink(int e){
  if(e == 0){
    Serial.println("2 eyes blinking");
    EsqLid.write(40);
    DirLid.write(1);
    delay(100);
    move_to_default(); 
  }
  if(e == 1){
    Serial.println("Left eye blinking");
    EsqLid.write(40);
    delay(100);
    EsqLid.write(15);
  }
  if(e == 2){
    Serial.println("Right eye blinking");
    DirLid.write(1);
    delay(100);
    DirLid.write(40);
  }
}
void look_up(){    //eixo y dos olhos varia de 40 a 100
  EyeY.write(100);
}

void look_down(){
  EyeY.write(25);
}

void loop() {
  while(Serial.available() != 0){}
  String move = Serial.readString();
  move.trim();
  if(move == "blink"){
    blink(0);
  }
  else if(move == "blink_left"){
    blink(1);
  }
  else if(move == "blink_right"){
    blink(2);
  }
  else if(move == "look_up"){
    look_up();
  }
  else if(move == "look_down"){
    look_down();
  }
  else if(move == "default"){
    move_to_default();
  }
}




#include <Servo.h>
int relay[4]={2,3,4,5};
int swich[4]={8,9,10,11};
int cnt=0; // 카운터
int n;
void servowind(); // 함수 인식
Servo servo; // 서보 클래스 호출

void setup() {
Serial.begin(9600);
// 스위치와 릴레이 핀모드 선언
for(int i=0;i<4;i++){
  pinMode(relay[i],OUTPUT);
  pinMode(swich[i],INPUT);
  }
// 서보 핀 선언
servo.attach(7);
servo.write(90);
}

void loop() {

for(int i=0;i<4;i++)
digitalWrite(relay[i],HIGH);
/*
n=random(4);
Serial.print(n);
digitalWrite(relay[n],LOW);
delay(20);
while (true){
  if(digitalRead(swich[n])==0){
   cnt++;
   digitalWrite(relay[n],HIGH);
   break;
    }
}
delay(1000);
servowind();
//Serial.println(cnt);
*/
}



void servowind(){
if(cnt>5){ // 카운터가 5가 되면
  cnt=0; // 0으로 초기화 하고
  servo.write(180); // 배식기를 45도 회전하고
  delay(172);
  servo.write(90); // 멈춰라
  delay(1000);
  }
}

#include <SoftwareSerial.h>

void FORWARD();
void LEFT();
void RIGHT();
void BACK();
void STOP();

int ENA = 10;
int ENB = 5;
int IN1 = 9;
int IN2 = 8;
int IN3 = 7;
int IN4 = 6;
char bt= '\0';
char TxBuffer[128];

SoftwareSerial BTSerial(2, 3);
void setup() {
  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BTSerial.available()) {
    bt = BTSerial.read();
    //sprintf(TxBuffer, "data received %c(%#X)\n", bt, bt);
    //Serial.print(TxBuffer);
  }

  switch (bt) {
    case 'f':
      FORWARD();
      break;
    case'l':
      LEFT();
      break;
    case'r':
      RIGHT();
      break;
    case'b':
      BACK();
      break;
    case's':
      STOP();
      break;

  }

}
void STOP() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}


void FORWARD() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 250);
  analogWrite(ENB, 250);
}
void LEFT() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 210);
  analogWrite(ENB, 210);
}
void RIGHT() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 210);
  analogWrite(ENB, 210);
}
void BACK() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 250);
  analogWrite(ENB, 250);
}

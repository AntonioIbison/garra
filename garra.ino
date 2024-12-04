#include <Servo.h>
#define S0 8
#define S1 9
#define S2 12
#define S3 11
#define OutSensor 10

int red = 0;
int green = 0;
int blue = 0;

Servo servoA;
Servo servoB;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OutSensor, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  servoA.attach(5);
  servoB.attach(6);
}

void loop() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  red = pulseIn(OutSensor, LOW);

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  green = pulseIn(OutSensor, LOW);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blue = pulseIn(OutSensor, LOW);

  String corPredominante = "";

  if (red < 140 || green < 100 || blue < 100) {
  if (red < green && red < blue) {
    corPredominante = "vermelho";
  } else if (green < red && green < blue) {
    corPredominante = "verde";
  } else if (blue < red && blue < green) {
    corPredominante = "azul";
  }
  }

  if (corPredominante == "vermelho") {
    desceB();
    delay(2000);
    desceB();
    delay(2000);
    sobeB();
    delay(2000);
    sobeB();
    delay(2000);
  }
  else if (corPredominante == "verde") {
    desceB();
    delay(2000);
    sobeB();
    delay(2000);
  }
  else if (corPredominante == "azul") {
    sobeB();
    delay(2000);
    desceB();
    delay(2000);
  }

}

void abre() {
  servoA.write(150);
}

void fecha() {
  servoA.write(100);
}

void sobeA() {
  servoB.write(150);
}

void desceA() {
  servoB.write(90);
}

void sobeB() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(400);
  pararMotor();
}

void desceB() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  delay(400);
  pararMotor();
}

void pararMotor() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  delay(200);
}
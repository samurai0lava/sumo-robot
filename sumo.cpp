//strategie 1
#include <Ultrasonic.h>

#define mtr1speed 255
#define mtr2speed 255

Ultrasonic ultrasonic(10, 11);
int distance;
int I = A5;
int motorRIGHTPin1 = 2;
int motorRIGHTPin2 = 5;
int motorLEFTPin1 = 7;
int motorLEFTPin2 = 4;
int motorRIGHTspeed = 3;
int motorLEFTspeed = 6;
int defensiveThreshold = 20;
int offensiveThreshold = 10;

void setup() {
  pinMode(motorRIGHTPin1, OUTPUT);
  pinMode(motorRIGHTPin2, OUTPUT);
  pinMode(motorLEFTPin1, OUTPUT);
  pinMode(motorLEFTPin2, OUTPUT);
  pinMode(motorRIGHTspeed, OUTPUT);
  pinMode(motorLEFTspeed, OUTPUT);
  Serial.begin(9600);
 

}
void moveForward() {
  pinMode(motorRIGHTPin1, OUTPUT);
  pinMode(motorRIGHTPin2, OUTPUT);
  pinMode(motorLEFTPin1, OUTPUT);
  pinMode(motorLEFTPin2, OUTPUT);
  pinMode(motorRIGHTspeed, OUTPUT);
  pinMode(motorLEFTspeed, OUTPUT);
  pinMode(I, INPUT);
}

void moveBackward() {
  digitalWrite(motorRIGHTPin1, LOW);
  digitalWrite(motorRIGHTPin2, HIGH);
  digitalWrite(motorLEFTPin1, LOW);
  digitalWrite(motorLEFTPin2, HIGH);
  digitalWrite(motorRIGHTspeed, 123);
  digitalWrite(motorLEFTspeed, 126);
}
void  Stop() {
  // Turn left
  digitalWrite(motorRIGHTPin1, LOW);
  digitalWrite(motorRIGHTPin2, LOW);
  digitalWrite(motorLEFTPin1, LOW);
  digitalWrite(motorLEFTPin2, LOW);
  analogWrite(motorRIGHTspeed, 0);
  analogWrite(motorLEFTspeed, 0);
}
void turn() {

  // Turn left
  digitalWrite(motorRIGHTPin1, LOW);
  digitalWrite(motorRIGHTPin2, HIGH);
  digitalWrite(motorLEFTPin1, HIGH);
  digitalWrite(motorLEFTPin2, LOW);
  analogWrite(motorRIGHTspeed, 120);
  analogWrite(motorLEFTspeed, 120);
}


void chargeForward() {
  digitalWrite(motorRIGHTPin1, HIGH);
  digitalWrite(motorRIGHTPin2, LOW);
  digitalWrite(motorLEFTPin1, HIGH);
  digitalWrite(motorLEFTPin2, LOW);
  analogWrite(motorRIGHTspeed, mtr1speed);
  analogWrite(motorLEFTspeed, mtr2speed);
}

void loop() {
  int circle = analogRead(I);
  distance = ultrasonic.read();
  Serial.println(distance);
  if (distance > 55) {
    turn();
  }
  else if (circle < 10 )  // <  650 means white line
  {

    for (int pos = 0; pos <= 150; pos += 1) {
      moveBackward();
      delay(5);
    }

  }
  while (distance <= 55 )  {
    chargeForward();
    distance = ultrasonic.read();
    circle = analogRead(I);
    if ( circle < 10) {
      break;
    }
    
  }

}


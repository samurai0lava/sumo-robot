
//strategie 1
#include <Ultrasonic.h>

#define mtr1speed 255
#define mtr2speed 255

Ultrasonic ultrasonic(12, 13);
int distance;



int motor1Pin1 = 2;
int motor1Pin2 = 3;
int motor2Pin1 = 4;
int motor2Pin2 = 5;
int motor1speed = ?;
int motor2speed = ?;

int defensiveThreshold = 20;  
int offensiveThreshold = 10;  

void setup() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(motor1speed, OUTPUT);
  pinMode(motor2speed, OUTPUT);
}
void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(motor1speed, 200);
  analogWrite(motor2speed, 200);
}

void moveBackward() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  analogWrite(motor1speed, 200);
  analogWrite(motor2speed, 200);
}

void turnRandomDirection() {
  // Randomly choose left or right turn
  if (random(2) == 0) {
    // Turn left
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
  } else {
    // Turn right
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
  }
}

void chargeForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(motor1speed, mtr1speed);
  analogWrite(motor2speed, mtr2speed);
}
void strategy1(){
  if (distance > 0) {
    if (distance <= defensiveThreshold) {
      // Perform defensive action
      moveBackward();
      delay(500);
      turnRandomDirection();
      delay(1000);
    } else if (distance <= offensiveThreshold) {
      // Perform offensive action
      chargeForward();
      delay(1000);
    } else {
      // Default movement
      moveForward();
    }
  }
}


void loop() {
  distance = ultrasonic();
  strategy1();
  
  
}


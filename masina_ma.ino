#include <NewPing.h>

//senzor ultrasonic
#define TRIGGER_PIN 11
#define ECHO_PIN 12
#define MAX_DISTANCE 200
#define COLL_DIST 30


//pini masina
#define forward 22//11
#define backward 30//10
#define left 42//7
#define right 38//6
#define turbo 24//12

//atentie la conexiuni placuta masina

#define light_sensor A0


//declarare variabile
unsigned int distance = 0, light_val = 0;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  pinMode(forward, OUTPUT);
  pinMode(backward, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(turbo, OUTPUT);

  pinMode(light_sensor, INPUT);

  Serial.begin(9600);
}



void loop() {
  delay(50);

  unsigned int distance = sonar.ping_cm();//Serial.print(distance);Serial.println("cm");
  light_val = analogRead(light_sensor); //Serial.println(light_val);



  if (light_val >= 150)
  {
    if (distance < COLL_DIST)
      changePath();
    moveForward();
  }
  else
    stopMove();

}

void moveForward()
{
  digitalWrite(forward, HIGH);
}

void stopMove()
{
  digitalWrite(forward,LOW);
  digitalWrite(left,LOW);
  digitalWrite(right,LOW);
}

void rotateRight()
{
  digitalWrite(right,HIGH);
  digitalWrite(forward,HIGH);
  delay(100);
  stopMove();
}

void changePath()
{
  stopMove();
  rotateRight();
}

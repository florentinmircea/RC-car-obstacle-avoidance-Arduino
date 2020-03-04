//#include <NewPing h>
#include <Servo.h>

//motor servo
Servo servo_ultra;

//ultrasonic sensor front
#define TRIGGER_PIN 11
#define ECHO_PIN 12


#define MAX_DISTANCE 200
#define COLL_DIST 70


//car connections
#define forward 13//11
#define backward 30//10
#define left 42//7
#define right 38//6
#define turbo 24//12

//check carefully car connections

#define light_sensor A0


//declarare variabile
unsigned int distance = 0, light_val = 0;
long duration, cm;
int ok=0;
//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


void setup() {
  servo_ultra.attach (8);
  pinMode(forward, OUTPUT);
  pinMode(backward, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(turbo, OUTPUT);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(light_sensor, INPUT);

  Serial.begin(9600);
}


void moveBackward()
{
  digitalWrite(backward, HIGH);
}
void brake()
{
  uint32_t period = 600L;       // 1 SEC

  for ( uint32_t tStart = millis();  (millis() - tStart) < period;  ) {
    moveBackward();
  }
  digitalWrite(backward, LOW);
}

long read_distance()
{
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(ECHO_PIN, INPUT);
  duration = pulseIn(ECHO_PIN, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
// Divide by 74 or multiply by 0.0135
  
 // Serial.print(inches);
  //Serial.print("in, ");
   // Serial.println(cm);
//  Serial.print("cm");
//  Serial.println();
//  
  delay(250);
  return cm;
}

int detect_front()
{

    servo_ultra.write(90);//front
    unsigned int distance = read_distance();
    Serial.print(distance);Serial.println("cm");

    if (distance < COLL_DIST)
      return 0;
    else
      return 1;
}
int detect_left()
{

    servo_ultra.write(180);//left
    delay(700);
    unsigned int distance = read_distance();
    Serial.print(distance);Serial.println("cm");

    if (distance < COLL_DIST)
      return 0;
    else
      return 1;
}
int detect_right()
{

    servo_ultra.write(0);//left
    delay(700);
    unsigned int distance = read_distance();
    Serial.print(distance);Serial.println("cm");

    if (distance < COLL_DIST)
      return 0;
    else
      return 1;
}
int detect_back()
{
    //back
    unsigned int distance = 0;
    Serial.print(distance);Serial.println("cm");

    if (distance < COLL_DIST)
      return 0;
    else
      return 1;
}
void moveForward()
{
   analogWrite(forward, 51*3);
  Serial.println("F");
}

void stopMove()
{
  digitalWrite(forward,LOW);
  digitalWrite(left,LOW);
  digitalWrite(right,LOW);
}

void rotateRight()
{
 digitalWrite(right, HIGH);
 delay(1000);
}
void rotateLeft()
{
  digitalWrite(left, HIGH);
  delay(1000);
 
}

void loop() 
{
while(ok==0)
{
  while(detect_front()==1)
  {
    moveForward();
  }
  brake();
  stopMove();
  delay(2000);
  if(detect_left()==1)
  {
    rotateLeft();
    uint32_t period =700L; 
    for ( uint32_t tStart = millis();  (millis() - tStart) < period;  ) {
    digitalWrite(forward, HIGH);
    }
    brake();
    delay(100);
    stopMove();
    rotateRight();
     period =300L; 
    for ( uint32_t tStart = millis();  (millis() - tStart) < period;  ) {
    digitalWrite(backward, HIGH);
    }
    brake();
    delay(100);
    stopMove();
     rotateLeft();
    period = 700L; 
    for ( uint32_t tStart = millis();  (millis() - tStart) < period;  ) {
    digitalWrite(forward, HIGH);
    }
     brake();
    delay(100);
    stopMove();





    rotateLeft();
    period =700L; 
    for ( uint32_t tStart = millis();  (millis() - tStart) < period;  ) {
    digitalWrite(forward, HIGH);
    }
    brake();
    delay(100);
    stopMove();
    rotateRight();
    period =300L; 
    for ( uint32_t tStart = millis();  (millis() - tStart) < period;  ) {
    digitalWrite(backward, HIGH);
    }
    brake();
    delay(100);
    stopMove();
    rotateLeft();
    period = 800L; 
    for ( uint32_t tStart = millis();  (millis() - tStart) < period;  ) {
    digitalWrite(forward, HIGH);
    }
    brake();
    delay(100);
    stopMove();
    delay(1000);
  }
  else if(detect_right()==1)
  {
    rotateRight();
    uint32_t period =700L; 
    for ( uint32_t tStart = millis();  (millis() - tStart) < period;  ) {
    digitalWrite(forward, HIGH);
    }
    brake();
    delay(100);
    stopMove();
    rotateLeft();
    period =300L; 
    for ( uint32_t tStart = millis();  (millis() - tStart) < period;  ) {
    digitalWrite(backward, HIGH);
    }
    brake();
    delay(100);
    stopMove();
    rotateRight();
    period = 700L; 
    for ( uint32_t tStart = millis();  (millis() - tStart) < period;  ) {
    digitalWrite(forward, HIGH);
    }
    brake();
    delay(100);
    stopMove();
    rotateRight();
    period =700L; 
    for ( uint32_t tStart = millis();  (millis() - tStart) < period;  ) {
    digitalWrite(forward, HIGH);
    }
    brake();
    delay(100);
    stopMove();
    rotateLeft();
    period =300L; 
    for ( uint32_t tStart = millis();  (millis() - tStart) < period;  ) {
    digitalWrite(backward, HIGH);
    }
    brake();
    delay(100);
    stopMove();
    rotateRight();
    period = 800L; 
    for ( uint32_t tStart = millis();  (millis() - tStart) < period;  ) {
    digitalWrite(forward, HIGH);
    }
    brake();
    delay(100);
    stopMove();
    delay(1000);
  }
    
    while(detect_front()==1)
    {
      moveForward();
    }
    brake();
    stopMove();
 
  //ok=1;
}
  
}

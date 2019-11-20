//pini masina
byte forward = 22;//11
byte backward = 30;//10
byte left = 42;//7
byte right = 38;//6
byte turbo = 24;//12
//atentie la conexiuni placuta masina
byte light_sensor = A0 ;
float value=0; 

int ms=0;
int s=0;
int m=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(forward, OUTPUT);
  pinMode(backward, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(turbo,OUTPUT);
  
  pinMode(light_sensor,INPUT);

  Serial.begin(9600);
}



void loop() {
  // put your main code here, to run repeatedly:
  //value=analogRead(light_sensor);
  //Serial.println(value);
  digitalWrite(turbo,HIGH);
  //digitalWrite(forward,HIGH);
  //if(value>=150)
    //digitalWrite(forward,HIGH);
  //else
    //digitalWrite(forward,LOW);
  
}

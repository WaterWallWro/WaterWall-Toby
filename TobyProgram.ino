//normal 72  grdos, 
//45 gira a la derecha y 135 gira a la izquierda

#include <Servo.h>

int pos = 0; // en que posicion está
int normal=72;
int derecha=52;
int izquierda=92;
int imanD=6;
int imanI=7;
int puerto=1;
int t = 1;



Servo servo_9;

int voltajeMotor = 255;
int motorPin = 3;


void izq(int t)
{
  servo_9.write(izquierda);
  Serial.println("izq");
  delay(t*1000);
}

void avanzar(int t)
{
   servo_9.write(normal);
  Serial.println("avanzo");
   delay(t*1000);
  
}


void der(int t)
{
  servo_9.write(derecha);
  Serial.println("doblo derecha");
   delay(t*1000);
}

 
void setup()
{
  pinMode(motorPin, OUTPUT);
  pinMode(imanD,INPUT);
  pinMode(imanI,INPUT);
  servo_9.attach(9);
  Serial.begin(9600);
  //servo_9.write(90);               
} 

void loop()
{
  digitalWrite(motorPin, HIGH);
  while(t<5){
  puerto=digitalRead(imanI);//veo si llego un iman de la izquierda
  if (puerto==0)// se pone en cero si llego al puerto
  {
    t++; //si llego al puerto aunmenta un segundo el tiempo de giro
  }
  Serial.println(puerto);
  avanzar(t);
  der(t);
  Serial.print("t= ");
  Serial.println(t);
  
  }

  t=1;
  delay(500);
  puerto=1;
  while(puerto!=0)
  {
  Serial.println(puerto);
  der(t);
  puerto=digitalRead(imanI);
  Serial.println("Estoy girando a la derecha"); 
  }
  while(t<5){
  puerto=digitalRead(imanD);//veo si llego un iman de la izquierda
  if (puerto==0)
  {
    t++;
  }
  Serial.println(puerto);
  avanzar(t);
  izq(t);
  Serial.print("t= ");
  Serial.println(t);
  
  }t=1;
  delay(500);
  puerto=1;
  while(puerto!=0)
  {
  Serial.println(puerto);
  izq(t);
  puerto=digitalRead(imanD);
  Serial.println("Estoy girando a la izquierda"); 
  }
  digitalWrite(motorPin, LOW);
  delay(7000);
}
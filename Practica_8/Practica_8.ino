/*
  Control del color emitido por un led RGB mediante los valores que registra
  el sensor de temperatura TEMP35.

*/
int red = 6;
int green = 10;
int blue = 9;

int valorRed;
int valorGreen;
int valorBlue;


const int pot2 = A1;

const int tempPin= A5;
const float baseTemp = 26.00;

void setup(){
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop(){
 valorGreen = map(analogRead(pot2),0,1023,0,255);
 
 int tempVal = analogRead(tempPin);
 float voltage = (tempVal/1024.0)*5.0;
 float temperatura = (voltage - .5)* 100;
 
 int temp = temperatura;
 valorRed = map(temp,22,30,0,255);
 valorBlue = map(temp,22,30,255,0);
 
 analogWrite(red, valorRed);
 analogWrite(green, valorGreen);
 analogWrite(blue, valorBlue);
 delay(100);
 
 Serial.print("Valor del sensor: ");
 Serial.print(tempVal);
 Serial.print(" voltatge: ");
 Serial.print(voltage);
 Serial.print(" Temperatura: ");
 Serial.println(temp);
 
 
}


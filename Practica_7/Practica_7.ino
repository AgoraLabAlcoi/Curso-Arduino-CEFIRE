/*
  Control del color emitido por un led RGB mediante tres potenciometros 
  que controlan la componente RGB del Led independientemente.

*/

int red = 6;
int green = 10;
int blue = 9;

int valorRed;
int valorGreen;
int valorBlue;

const int pot1 = A0;
const int pot2 = A1;
const int pot3 = A2;

void setup(){
  
 pinMode(red, OUTPUT);
 pinMode(green, OUTPUT);
 pinMode(blue, OUTPUT);
}

void loop(){
 valorRed = map(analogRead(pot1),0,1023,0,255);
 valorGreen = map(analogRead(pot2),0,1023,0,255);
 valorBlue = map(analogRead(pot3),0,1023,0,255);
 
 analogWrite(red, valorRed);
 analogWrite(green, valorGreen);
 analogWrite(blue, valorBlue);
 
 
  
}


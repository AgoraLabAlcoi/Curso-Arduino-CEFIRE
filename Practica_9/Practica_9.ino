/*
  Control del color emitido por un led RGB mediante los valores de 
  temperatura que registra el sensor TEMP35. Instalamos una LCD para
  visualizar datos de temperatura y sensacion luminica mediante una LDR

*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int rangoTemp=22;

int red = 6;
int green = 10;
int blue = 9;

int valorRed;
int valorGreen;
int valorBlue;

const int tempPin= A5;
const int sensorLlum = A0;
const float baseTemp = 26.00;

void setup(){
   pinMode(red, OUTPUT);
   pinMode(green, OUTPUT);
   pinMode(blue, OUTPUT);
   
   lcd.begin(16, 2);
   lcd.print("Temp: "); 
   
   
}

void loop(){
  
   int tempPrint = medirTemp();
   int llumPrint = medirLlum();
   
   if(tempPrint < rangoTemp){
     analogWrite(red, 0);
     analogWrite(green, 150);
     analogWrite(blue, 255);
   }
   
   if(tempPrint > rangoTemp + 2){
     analogWrite(red, 150);
     analogWrite(green, 150);
     analogWrite(blue, 150);
   }
   
   if(tempPrint > rangoTemp + 4){
     analogWrite(red, 255);
     analogWrite(green, 150);
     analogWrite(blue, 100);
   }
   
   if(tempPrint > rangoTemp + 6){
     analogWrite(red, 255);
     analogWrite(green, 0);
     analogWrite(blue, 0);
   }
   
   lcd.setCursor(7,0);
   lcd.print(tempPrint);
   lcd.setCursor(9,0);
   lcd.print("C.");
   lcd.setCursor(0,1);
   lcd.print("Sens. llum:");
   lcd.setCursor(12,1);
   lcd.print(llumPrint);

}

float medirTemp(){

      int tempVal = analogRead(tempPin);
      float voltage = (tempVal/1024.0)*5.0;
      float temperatura = (voltage - .5)* 100;
      
      delay(400);
      return temperatura;
}

int medirLlum(){
 int llum = analogRead(sensorLlum)/10; 
 return llum;
}

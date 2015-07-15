
import processing.serial.*;
import cc.arduino.*;

color off = color(0, 0, 0);
color on = color(255, 0, 0);
int[] valores = {Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW,
Arduino.LOW, Arduino.LOW, Arduino.LOW, Arduino.LOW}; //vector con 10 posiciones

Arduino arduino;

void setup()
{
   size(290, 100);
   arduino = new Arduino(this, Arduino.list()[0], 57600);
  
   //pines del 2 al 9
   for(int i=2; i<10; i++)
   {
      arduino.pinMode(valores[i], Arduino.OUTPUT);
   } 
}

void draw()
{
   background(off);
   stroke(on);
   int valor = 0;
   for(int i = 2; i< 10; i++)
   {
      if(valores[i] == Arduino.LOW)
      {
         fill(off);
         rect(valor * 30 + 30, 40, 20, 20);  //(x, y, ancho, alto) 
      }else
      {
         fill(on);
         rect(valor * 30 + 30, 40, 20, 20); 
      }
      valor++;
   } 
}

void mousePressed()
{
   //Determinamos la posición donde activaremos las salidas
   int pin = ((mouseX - 270)/30) + 9;
   if(mouseY < 40 || mouseY > 60 || mouseX > 260)
   {
      textSize(50);
      fill(255);
      text("ERROR", 60, 70);
   }else
   {
      if(valores[pin] == Arduino.LOW)
      {
         valores[pin] = Arduino.HIGH;
         arduino.digitalWrite(pin, Arduino.HIGH); 
      }else
      {
         valores[pin] = Arduino.LOW;
         arduino.digitalWrite(pin, Arduino.LOW); 
      }
   } 
}

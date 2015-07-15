import processing.serial.*;
import cc.arduino.*;

int sensor = 0;
int valor;

int[] valores;

Arduino arduino;

void setup()
{
   size(256, 256);
   arduino = new Arduino(this, Arduino.list()[0], 57600);
   valores = new int[width]; 
}

/* Calculamos el valor recibido en voltios*/
float calcularVoltaje(int bits)
{
    float v = 5.0 * (bits/255.0);
    return v/4;
}

/*Desplazamos los valores del array*/
void desplazarArray()
{
   for(int i = 1; i < width; i++)
   {
      valores[i-1] = valores[i]; 
   }
}

/*Representar valores*/
void representarValores(int v)
{
   textAlign(RIGHT);
   text(v/4, 200, 30); //bits
   text(calcularVoltaje(v) + "V", 200, 60); 
}

/*Almacenamos el valor leido en la última posición del array*/
void almacenarValor(int val)
{
   val = arduino.analogRead(sensor);
   valores[width-1] = val/4;
   representarValores(val); 
}

/*Dibujar array*/
void dibujarGrafico()
{
   stroke(255);
   for(int i=1; i<width; i++)
   {
      point(i, 255 - valores[i]);
   } 
}

void draw()
{
   background(0);
   desplazarArray();
   almacenarValor(valor);
   dibujarGrafico(); 
}

#include <Servo.h>

Servo myservo;  // Crea el objeto servo para controlarlo
int potpin=A0;  // usamos el pin analógico 0 para leer el potenciómetro
int val;  // variable para leer los datos del pin A0

void setup()
{
 	Serial.begin(9600);
 	myservo.attach(11);   // enlazamos el pin 11 al objeto servo
}

void loop()
{
  	val= analogRead(potpin);     // lee el valor del potenciómetro (valor entre 						0 y 1023)
 	val = map(val,0,1023,0,179);  // lo convierte a un valor entre 0 y 179
  
   	Serial.print("Valor: ");
 	Serial.println(val);                   //  imprime el dato en la ventana serial del 						ordenador
  	myservo.write(val);         // envia al servo el nuevo valor
  	delay(20);          // espera 15 milisegundos
}

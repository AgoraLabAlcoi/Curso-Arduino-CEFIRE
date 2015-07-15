/*
    Control de un motor DC mediante un transistor y un pulsador
*/

const int pulsadorPin = 2; 		//declaramos una constante y le asignamos el pin 2
const int motorPin = 9; 		//declaramos una constante y le asignamos el pin 9
int pulsadorEstado = 0; 	 // declaramos una variable para leer el estado del pulsador

void setup()
{ 
   pinMode(motorPin, OUTPUT);
   pinMode(pulsadorPin, INPUT);
}


void loop()
{
   pulsadorEstado = digitalRead(pulsadorPin);  	// leemos el estado del pin 2 y lo almacenamos en la variable 								pulsadorEstado  
   if (pulsadorEstado == HIGH){         // si el pulsador está pulsado, activamos el pin del motor
      digitalWrite(motorPin, HIGH);
   } else {
      digitalWrite(motorPin, LOW); 
   }
}

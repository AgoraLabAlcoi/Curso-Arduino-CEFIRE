int ledPin1 = 12;
int ledPin2 = 11;
int ledPin3 = 10;
int estado1 = HIGH;
int estado2 = HIGH;
int estado3 = HIGH;
int valor = 0;

void setup()
{
   Serial.begin(9600);
   pinMode(ledPin1, OUTPUT);
   pinMode(ledPin2, OUTPUT);
   pinMode(ledPin3, OUTPUT); 
}

void loop()
{
   valor = Serial.read(); //lee el valor del puerto
   if(valor != -1)
   {
      switch(valor)
      {
         case'1':
            estado1 = !estado1;
            break;
         case'2':
            estado2 = !estado2;
            break;
         case'3':
            estado3 = !estado3;
           break; 
      }
   }
  digitalWrite(ledPin1, estado1);
  digitalWrite(ledPin2, estado2);
  digitalWrite(ledPin3, estado3); 
}

 /*
  Intermitencia
  Enciende un LED durante medio segundo y lo apaga. Repite la accion en los 5 leds 
  
 */
 

 int ledPin [] = {8, 9, 10, 11, 12};
 int temps = 500; 
 int botoPin = 7;
 int boto = 0;


 void setup() { 
   
  for (int i = 0; i < 5; i++){
    pinMode(ledPin[i], OUTPUT); 
  }
  
  pinMode(botoPin, INPUT);
  
  for (int i = 0; i < 5; i++){
     digitalWrite(ledPin[i], LOW);
  } 
 }


 void loop() {
   boto = digitalRead(botoPin);
   
   if(boto == 1){
       secuencia();
   }else{
       for (int i = 0; i < 5; i++){
         digitalWrite(ledPin[i], LOW);
       } 
   }
 }
 
 
 void secuencia(){
   for(int i = 0; i < 5; i++){
     digitalWrite(ledPin[i], HIGH);
     delay(temps);
     digitalWrite(ledPin[i], LOW);
   }
   
 }

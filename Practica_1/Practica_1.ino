 /*
  Intermitencia
  Enciende un LED durante medio segundo y lo apaga 
  al tiempo que enciende un segundo LED durante medio segundo y lo apaga.
 */
 

 int led1 = 8;
 int led2 = 9;


 void setup() {                
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);  
 }


 void loop() {
  digitalWrite(led1, HIGH);   // enciende el LED
  delay(500);               // espera durante medio segundo
  digitalWrite(led1, LOW);    // apaga el LED
  digitalWrite(led2, HIGH);   
  delay(500);               
  digitalWrite(led2, LOW);   
  

 }

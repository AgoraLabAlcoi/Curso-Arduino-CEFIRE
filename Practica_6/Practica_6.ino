/*
 El mismo codigo de la practica 5 pero implementando la funcion millis() y descartando el uso de delay()
 */
 
int ledPin [] = {8, 9, 10, 11, 12};

const int pot = A0;
const int botoPin = 7;

int boto = 0;
int botoAntes = 0;
int temps = 0;
int estado = 0;
int sensorTilt = 5;

boolean secuenciaCompleta = false;

unsigned long tiempo;

void setup(){
       for (int i = 0; i < 5; i++){
          pinMode(ledPin[i], OUTPUT); 
        }
        pinMode(botoPin, INPUT);
        tiempo = millis();
}

void loop(){
        boto = digitalRead(botoPin);
        temps = (analogRead(pot))/4;
        
        if((boto == HIGH) && (botoAntes == LOW)){
            estado = 1 - estado;
            delay(10); 
         }
         botoAntes = boto;
         
         if(estado == 1){
            boolean golpe = digitalRead(sensorTilt);
            if (golpe == false){
               for (int i = 0; i < 5; i++){
                   digitalWrite(ledPin[i], LOW);
               }
              secuenciaInv();
              if(secuenciaCompleta == true){
                  tiempo = millis();
              }
            }else{
               for (int i = 0; i < 5; i++){
                   digitalWrite(ledPin[i], LOW);
               }
              secuencia();
            if(secuenciaCompleta == true){
                  tiempo = millis();
            }
            }
            
           
            
         }else{
               for (int i = 0; i < 5; i++){
                   digitalWrite(ledPin[i], LOW);
               }
     
        }

}

void secuencia(){
         if(millis()-tiempo < (temps * 1)){
           secuenciaCompleta = false;
          digitalWrite(ledPin[0], HIGH);
        }else{
           if(millis()-tiempo > (temps * 1)){
             digitalWrite(ledPin[0], LOW);
           }
        }
        if((millis()-tiempo < (temps * 2)) && (millis()-tiempo > (temps * 1))){
          digitalWrite(ledPin[1], HIGH);
        }else{
           if(millis()-tiempo > (temps * 2)){
             digitalWrite(ledPin[1], LOW);
           }
        }
        if((millis()-tiempo < (temps * 3)) && (millis()-tiempo > (temps * 2))){
          digitalWrite(ledPin[2], HIGH);
        }else{
           if(millis()-tiempo > (temps * 3)){
             digitalWrite(ledPin[2], LOW);
           }
        }
         if((millis()-tiempo < (temps * 4)) && (millis()-tiempo > (temps * 3))){
          digitalWrite(ledPin[3], HIGH);
        }else{
           if(millis()-tiempo > (temps * 4)){
             digitalWrite(ledPin[3], LOW);
           }
        }
        if((millis()-tiempo < (temps * 5)) && (millis()-tiempo > (temps * 4))){
          digitalWrite(ledPin[4], HIGH);
        }else{
           if(millis()-tiempo > (temps * 5)){
             digitalWrite(ledPin[4], LOW);
             secuenciaCompleta = true;
           }
        } 
}

void secuenciaInv(){
         if(millis()-tiempo < (temps * 1)){
           secuenciaCompleta = false;
          digitalWrite(ledPin[4], HIGH);
        }else{
           if(millis()-tiempo > (temps * 1)){
             digitalWrite(ledPin[4], LOW);
           }
        }
        if((millis()-tiempo < (temps * 2)) && (millis()-tiempo > (temps * 1))){
          digitalWrite(ledPin[3], HIGH);
        }else{
           if(millis()-tiempo > (temps * 2)){
             digitalWrite(ledPin[3], LOW);
           }
        }
        if((millis()-tiempo < (temps * 3)) && (millis()-tiempo > (temps * 2))){
          digitalWrite(ledPin[2], HIGH);
        }else{
           if(millis()-tiempo > (temps * 3)){
             digitalWrite(ledPin[2], LOW);
           }
        }
         if((millis()-tiempo < (temps * 4)) && (millis()-tiempo > (temps * 3))){
          digitalWrite(ledPin[1], HIGH);
        }else{
           if(millis()-tiempo > (temps * 4)){
             digitalWrite(ledPin[1], LOW);
           }
        }
        if((millis()-tiempo < (temps * 5)) && (millis()-tiempo > (temps * 4))){
          digitalWrite(ledPin[0], HIGH);
        }else{
           if(millis()-tiempo > (temps * 5)){
             digitalWrite(ledPin[0], LOW);
             secuenciaCompleta = true;
           }
        } 
}

/*
    Creación de sonido mediante la funcion tone() y una LDR
*/

int luz;        //será el valor de entrada de la LDR
int sonido;     //será el valor de la frecuencia del altavoz
int ldr = A5;     //conectaremos la LDR al pin A5
int altavoz = 5;  //conectaremos el altavoz al pin 5

void setup()
{
    pinMode(altavoz,OUTPUT);
    Serial.begin(9600); //interesa ver los valores de la LDR
}
void loop()
{
    luz=analogRead(ldr);
    Serial.print("luz recibida: ");
    Serial.print(luz);
    Serial.print('\t');
    sonido=map(luz,200,450,3000,200);
    sonido=constrain(sonido,200,3000); //obligamos a que no salga de esos valores
    Serial.print("frecuenca sonido: ");
    Serial.println(sonido);
    tone(altavoz,sonido,200);
    delay(250); //damos tiempo a que suene la nota y a una pequeña pausa
}

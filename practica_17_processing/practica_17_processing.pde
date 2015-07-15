
import procesing.serial.*;

Serial port;

void setup()
{
   size(255, 255);
   port = new Serial(this, Serial.list()[0], 9600); //establecemos la misma velocidad en el Arduino 
}

void draw()
{
   background(0); 
}

void keyReleased()
{
   port.write(key); 
}

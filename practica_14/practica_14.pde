
import processing.serial.*;
import cc.arduino.*;

int led1 = 9;
int led2 = 10;
Arduino arduino;

void setup()
{
   size(512, 512);
   arduino = new Arduino(this, Arduino.list()[0], 57600); 
}

void draw()
{
    background(constrain(mouseX/2, 0, 255));
    arduino.analogWrite(led1, constrain(mouseX/2, 0, 255));
    arduino.analogWrite(led2, constrain(mouseX/2, 0, 255));
}

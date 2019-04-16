#include <wiringPi.h>
#include <stdio.h>

#define LEDpin
#define buttonPin 09
int main(){
    int programRunning = 1;
    int currentScan = 0;
    int value;


    if(wiringPiSetup() == -1){
        prinln("Wiring setup has failed.");
        return 0;
    }else{
        pinMode(buttonPin, INPUT); //sets the pin of the button to the input
        pinMode(LEDpin, OUTPUT);    //sets the pin of the LED to output
        while(programRunning){
            //delay(1000);
            value = digitalRead(buttonPin);
            if(value == 1){
                digitalWrite(LEDpin, 1);
                currentScan = 1;
            }
            while(currentScan){
                //read all data and send to memory wherever
                value = digitalRead(buttonPin);
                if(value == 1){
                    currentScan = 0;
                }
            }
        }
    }

    return 0;
}
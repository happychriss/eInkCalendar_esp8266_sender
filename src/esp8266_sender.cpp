
#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial swSer(14, 12, false, 256);
void SerialKeyWait();

void setup() {
    Serial.begin(115200);
    // SerialKeyWait();
    swSer.begin(9600);
    Serial.println("\nSoftware serial test started");
//
//    for (char ch = ' '; ch <= 'z'; ch++) {
//        swSer.write(ch);
//    }
//    swSer.println("");

}

void loop() {
int count=0;
    while(1) {

        for (char ch = ' '; ch <= 'z'; ch++) {
            swSer.write(64);
        }


           if (count > 10) {
                Serial.println("X");
                count = 0;
            }
            count++;

            delay(500);
        }



}
void SerialKeyWait() {// Wait for Key

//    Serial.setDebugOutput(true);


    Serial.println("Hit a key to start...");
    Serial.flush();

    while (true) {
        int inbyte = Serial.available();
        delay(500);
        if (inbyte > 0) break;
    }
}

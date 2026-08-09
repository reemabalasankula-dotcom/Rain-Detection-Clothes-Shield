#include <Servo.h>

#define RAIN_SENSOR_AO A0
#define SERVO_PIN 7

Servo shieldServo;

void setup() {
    pinMode(RAIN_SENSOR_AO, INPUT);
    shieldServo.attach(SERVO_PIN);
    Serial.begin(115200);
}

void loop() {
    int rainValue = analogRead(RAIN_SENSOR_AO);

    Serial.print("Rain Sensor Value: ");
    Serial.println(rainValue);

    if (rainValue < 1200) {
        Serial.println("Rain Detected! Closing the shield.");
        shieldServo.write(0);
    }
    else {
        Serial.println("No Rain. Opening the shield.");
        shieldServo.write(90);
    }

    delay(2000);
}
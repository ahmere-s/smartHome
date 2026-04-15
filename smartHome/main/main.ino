#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //Location, columns, rows

Servo servo1Door; //Pin 9
Servo servo2Window; //Pin 10

//Analog
const int sensorGas = A0;

//Digital
const int sensorBuzzer = 3;
const int yellowLED = 12;
const int whiteLED = 13;
const int buttonSwitch1 = 4;
const int buttonSwitch2 = 5;
const int relayModule = 12;
const int sensorMotion = 2; 

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Working...");

  pinMode(sensorMotion, INPUT);
  pinMode(buttonSwitch1, INPUT_PULLUP);
  pinMode(buttonSwitch2, INPUT_PULLUP);

  pinMode(yellowLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);
  pinMode(relayModule, OUTPUT);
  pinMode(sensorBuzzer, OUTPUT);

  servo1Door.attach(9);
  servo2Window.attach(10);
}

void loop(){

}

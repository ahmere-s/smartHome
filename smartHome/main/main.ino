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
const int relayModule = 7;
const int sensorMotion = 2; 

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1, 0);
  lcd.print("Welcome, Guest!");
  lcd.setCursor(2, 1);      //setCursor() takes (column, row) NOT vice versa.
  lcd.print("System Ready.");
  delay(4000);
  lcd.clear();

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
  //Get/read current state of all sensors
  int gasValue = analogRead(sensorGas);
  int pin4Butt = digitalRead(buttonSwitch1);
  int pin5Butt = digitalRead(buttonSwitch2);
  int motionSense = digitalRead(sensorMotion);

  //Here I will begin to order sensor logic based on priority and security purposes
  lcd.setCursor(0, 0);    // Dont have to clear the first row since printing something new will replace old characters. 
  lcd.print("Gas Level: ");
  lcd.setCursor(11, 0);
  lcd.print(gasValue);
  delay(1000);

  if (gasValue > 400){
    
  }
  else {
    
  }

  //if (motionSense == HIGH){} else {}
  





}

#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //Location, columns, rows

Servo servo1Door; //Pin 10
Servo servo2Window; //Pin 9

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
bool isWindowOpen = false;
bool isDoorOpen = false;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1, 0);
  lcd.print("Welcome, Guest!");
  lcd.setCursor(1, 1);      //setCursor() takes (column, row) NOT vice versa.
  lcd.print("System Prep...");
  delay(5000);
  lcd.clear();

  pinMode(sensorMotion, INPUT);
  pinMode(buttonSwitch1, INPUT_PULLUP);
  pinMode(buttonSwitch2, INPUT_PULLUP);

  pinMode(yellowLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);
  pinMode(relayModule, OUTPUT);
  pinMode(sensorBuzzer, OUTPUT);

  servo1Door.attach(10);
  delay(1000);             
  servo2Window.attach(9);            

  servo2Window.write(0);
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

  if (gasValue >= 350){
    tone(sensorBuzzer, 1000);   //pin, frequency, duration(removed)
    if (!isWindowOpen){servo2Window.write(90); isWindowOpen = true;}
  }
  else {
    noTone(sensorBuzzer);
    if (isWindowOpen){servo2Window.write(0); isWindowOpen = false;}  //Only move if window is already open.
  }

  if (motionSense == HIGH){
    digitalWrite(whiteLED, LOW);
    digitalWrite(yellowLED, HIGH);

    tone(sensorBuzzer, 500);
  }
  else {
    digitalWrite(yellowLED, LOW);
    digitalWrite(whiteLED, HIGH);

    if(gasValue < 350){noTone(sensorBuzzer);}
  }
  





}

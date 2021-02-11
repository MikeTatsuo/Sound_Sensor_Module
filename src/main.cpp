#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define DIGITAL_PIN 2
#define ANALOG_PIN A0

void setup() {
  pinMode(DIGITAL_PIN, INPUT_PULLUP);
  pinMode(ANALOG_PIN, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("*** Sound Sensor ***");

  lcd.setCursor(0, 3);
  lcd.print("Level:");
}

void loop() {
  lcd.setCursor(0, 2);
  if (digitalRead(DIGITAL_PIN)){
    lcd.print("***SOUND DETECTED***");
    delay(1000);
  } else {
    lcd.print("                    ");    
  }

  lcd.setCursor(7, 3);
  lcd.print(analogRead(ANALOG_PIN));
  lcd.print("  ");
}

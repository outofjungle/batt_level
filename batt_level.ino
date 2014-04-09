#include <LiquidCrystal.h>
#include<stdlib.h>

#define R1 20000.0
#define R2 10000.0

float Vin, Vout;
float weight;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

char Vin_buffer[8];
char Vout_buffer[8];

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  weight = (R1 + R2)/(R2);
}

void loop() {
  Vout = analogRead(A1) * (5.0/1023.0);
  Vin = weight * Vout;

  dtostrf(Vin, 2, 2, Vin_buffer);
  dtostrf(Vout, 2, 2, Vout_buffer);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Vin: ");
  lcd.print(Vin_buffer);
  lcd.setCursor(0, 1);
  lcd.print("Vout: ");
  lcd.print(Vout_buffer);
  
  Serial.print("Vin: ");
  Serial.print(Vin_buffer);
  Serial.print(", Vout: ");
  Serial.println(Vout_buffer);

  delay(1000);
}

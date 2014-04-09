#include <LiquidCrystal.h>
#define R1 20000.0
#define R2 10000.0

float Vin, Vout;
float weight;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  weight = (R1 + R2)/(R2);
  lcd.print("hello, world!");
}

void loop() {
  Vout = analogRead(A1) * (5.0/1023.0);
  Vin = weight * Vout;

  Serial.print("Vin: ");
  Serial.print( Vin );
  Serial.print(", Vout: ");
  Serial.println( Vout );

  delay(1000);
}

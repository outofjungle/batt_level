#define R1 20000.0
#define R2 10000.0

float Vin, Vout;
float weight;
void setup() {
  Serial.begin(9600);
  weight = (R1 + R2)/(R2);
}

void loop() {
  Vout = analogRead(A1) * (5.0/1023.0);
  Serial.println( Vin );
  Vin = weight * Vout;

  Serial.print("Vin: ");
  Serial.print( Vin );
  Serial.print(", Vout: ");
  Serial.println( Vout );

  delay(1000);
}

#define MQ2pin 34 // Analog pin A0 connected to sensor's AOUT
#d
float sensorValue;

void setup() {
  Serial.begin(9600);
  Serial.println("Gas sensor warming up...");
  delay(20000); // Allow 20 seconds for the sensor to heat up
}

void loop() {
  sensorValue = analogRead(MQ2pin); // Read analog value from A0
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);

  // Basic threshold for smoke detection (adjust as needed)
  if (sensorValue > 2500) {
    Serial.print(" | Smoke/Gas Detected!");
  }
  Serial.println("");
  delay(1000); // Wait 1 second before next reading
}

#include"DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11 // Corrected type definition for clarity
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("DHT setup is done..");
}

void loop() {
  // Read humidity and temperature
  float humidity = dht.readHumidity(); // Corrected object name
  float temperature = dht.readTemperature(); // Corrected object name

  // Check if any reads failed and exit early (return)
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000); // Wait a bit before retrying
    return;
  }

  // Print readings
  // Use Serial.print/println for standard Arduino IDE, or Serial.printf if supported
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t"); // Tab for spacing
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C"); // Celsius

  delay(3000);
}

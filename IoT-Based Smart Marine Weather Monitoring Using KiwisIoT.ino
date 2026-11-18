#include <ESP8266WiFi.h>
#include <KiwisIoT.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// WiFi Credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Topic ID
const char* topic = "YOUR_TOPIC_ID";

// Sensor Pins
#define WIND_PIN D5
#define RAIN_PIN D6

// BME280
Adafruit_BME280 bme;

// KiwisIoT
KiwisIoT kiwisiot(ssid, pass, topic);

// Wind Speed Variables
volatile unsigned long windPulses = 0;

unsigned long previousMillis = 0;
unsigned long lastWindTime = 0;

float windSpeed = 0;

// Replace this with your anemometer's
// calibrated pulses-per-second conversion.
const float WIND_FACTOR = 1.0;

void ICACHE_RAM_ATTR countWindPulse() {
  windPulses++;
}

void setup() {

  Serial.begin(115200);

  Wire.begin(D2, D1);

  pinMode(WIND_PIN, INPUT_PULLUP);
  pinMode(RAIN_PIN, INPUT);

  attachInterrupt(
    digitalPinToInterrupt(WIND_PIN),
    countWindPulse,
    FALLING
  );

  if (!bme.begin(0x76)) {
    Serial.println("BME280 Not Found!");

    while (true) {
      delay(1000);
    }
  }

  kiwisiot.begin();

  lastWindTime = millis();

  Serial.println("Marine Weather Monitoring Started");
}

void loop() {

  kiwisiot.run();

  if (millis() - previousMillis >= 5000) {

    previousMillis = millis();

    // Read BME280
    float temperature = bme.readTemperature();

    float humidity = bme.readHumidity();

    float pressure = bme.readPressure() / 100.0F;

    // Calculate Wind Speed
    noInterrupts();

    unsigned long pulses = windPulses;
    windPulses = 0;

    interrupts();

    float elapsedSeconds =
      (millis() - lastWindTime) / 1000.0;

    lastWindTime = millis();

    float windSpeed =
      (pulses / elapsedSeconds) * WIND_FACTOR;

    // Rain Detection
    int rainStatus = digitalRead(RAIN_PIN);

    String rainCondition =
      (rainStatus == LOW) ? "RAIN" : "NO RAIN";

    Serial.println("\n--- MARINE WEATHER DATA ---");

    Serial.print("Temperature: ");
    Serial.println(temperature);

    Serial.print("Humidity: ");
    Serial.println(humidity);

    Serial.print("Pressure: ");
    Serial.println(pressure);

    Serial.print("Wind Speed: ");
    Serial.println(windSpeed);

    Serial.print("Rain Status: ");
    Serial.println(rainCondition);

    // Send data to KiwisIoT
    kiwisiot.send("0", String(temperature, 2));
    kiwisiot.send("1", String(humidity, 2));
    kiwisiot.send("2", String(pressure, 2));
    kiwisiot.send("3", String(windSpeed, 2));
    kiwisiot.send("4", rainCondition);
  }
}
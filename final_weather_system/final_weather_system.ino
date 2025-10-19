
#define BLYNK_TEMPLATE_ID "TMPL3g9pQasBB"
#define BLYNK_TEMPLATE_NAME "Weather Monitoring System"
#define BLYNK_AUTH_TOKEN "VpB_R4zbnzt7ZdxoT70s7Lj8WzUc1jRq"

// ====== LIBRARIES ======
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

// ====== WIFI / BLYNK CREDENTIALS ======
char auth[] = BLYNK_AUTH_TOKEN;              
char ssid[] = "Malavika's S25 Ultra";
char pass[] = "ntehotspot";

// ====== LCD SETUP ======
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Use 0x3F if 0x27 doesn’t work

// ====== DHT11 SETUP ======
#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// ====== RAIN SENSOR SETUP ======
#define RAIN_SENSOR D6
#define LED_PIN D7

// ====== VARIABLES ======
float temperature, humidity;
int rainState;
String rainStatus;

BlynkTimer timer;

// ====== FUNCTION TO READ SENSORS ======
void sendSensorData() {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  rainState = digitalRead(RAIN_SENSOR);

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("❌ DHT Sensor Error!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DHT Error!");
    return;
  }

  // ====== DETECT RAIN ======
  if (rainState == HIGH) {  // Change to LOW if your sensor is inverted
    rainStatus = "Raining";
    digitalWrite(LED_PIN, HIGH);
  } else {
    rainStatus = "No Rain";
    digitalWrite(LED_PIN, LOW);
  }

  // ====== Serial Monitor Output ======
  Serial.println("=== Weather Data ===");
  Serial.print("Temp: "); Serial.print(temperature); Serial.println(" °C");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.println(" %");
  Serial.print("Rain: "); Serial.println(rainStatus);
  Serial.println("--------------------");

  // ====== LCD Display ======
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature, 1);
  lcd.print("C ");
  lcd.print("H:");
  lcd.print(humidity, 0);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print(rainStatus);

  // ====== Send Data to Blynk ======
  Blynk.virtualWrite(V0, temperature);   // Temperature
  Blynk.virtualWrite(V1, humidity);      // Humidity
  Blynk.virtualWrite(V2, rainStatus);    // Rain status text
}

void setup() {
  Serial.begin(9600);

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Weather Station");
  lcd.setCursor(0, 1);
  lcd.print("Connecting...");
  delay(2000);

  // Initialize DHT11
  dht.begin();

  // Rain sensor and LED
  pinMode(RAIN_SENSOR, INPUT);
  pinMode(LED_PIN, OUTPUT);

  // Connect to WiFi and Blynk
  Blynk.begin(auth, ssid, pass);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WiFi Connected");
  delay(1000);
  lcd.clear();

  // Send data every 2 seconds
  timer.setInterval(2000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}


#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 7, 6, 5, 4, 3);

int sensorPin = A0;    
int buzzerPin = 9;      
int ledPin = 10;        
float limitTemp = 30.0; 

float maxTemp = -1000.0;
float minTemp = 1000.0;

unsigned long startMillis;        
unsigned long lastAverageMillis;  
float sumTemp = 0;
int sampleCount = 0;
float avgTemp = 0;

// Sukuriame savo „°“ simbolį
byte degreeSymbol[8] = {
  0b00111,
  0b00101,
  0b00111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};


float readTemperatureC() {
  int reading = analogRead(sensorPin);
  float voltage = reading * 4.68 / 1024.0;
  return (voltage - 0.5) * 100; 
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

  lcd.createChar(0, degreeSymbol);

  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);


  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Smart Thermometer");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(4000); // rodo 4 sek.
  lcd.clear();

  startMillis = millis();
  lastAverageMillis = millis();
}

void loop() {
  float temperatureC = readTemperatureC();
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  unsigned long currentMillis = millis();
  unsigned long elapsedSeconds = (currentMillis - startMillis) / 1000;

  sumTemp += temperatureC;
  sampleCount++;

  if (currentMillis - lastAverageMillis >= 10000) {
    if (sampleCount > 0) {
      avgTemp = sumTemp / sampleCount;
    }

    Serial.print("10s average: ");
    Serial.println(avgTemp);

    sumTemp = 0;
    sampleCount = 0;
    lastAverageMillis = currentMillis;
  }

  if (temperatureC > maxTemp) maxTemp = temperatureC;
  if (temperatureC < minTemp) minTemp = temperatureC;

  if (temperatureC > limitTemp) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  }

  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(temperatureC, 1);
  lcd.write(byte(0));  
  lcd.print("C ");
  lcd.print(temperatureF, 1);
  lcd.print("F");

  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(elapsedSeconds);
  lcd.print("s ");
  lcd.print("Avg:");
  lcd.print(avgTemp, 1);

  Serial.print("Now: ");
  Serial.print(temperatureC);
  Serial.print(" C | ");
  Serial.print(temperatureF);
  Serial.print(" F | Avg(10s): ");
  Serial.println(avgTemp);

  delay(1000); 
}

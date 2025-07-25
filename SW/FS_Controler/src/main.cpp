#include <Arduino.h>

const int relay1 = 32; // Pin des ersten Relays
const int relay2 = 33; // Pin des zweiten Relays

const int pwmPin = 13; // Pin für PWM-Ausgabe zum Motor
const int pwmFrequency = 5000; // Frequenz für PWM
const int pwmResolution = 8; // Auflösung für PWM (8 Bit)

void setup() {
  // Initialisiere serielle Kommunikation
  Serial.begin(115200);
  
  // Setze die Pins für die Relais als Ausgänge
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  
  // Setze den PWM-Pin als Ausgang
  pinMode(pwmPin, OUTPUT);  
  // Konfiguriere die PWM-Einstellungen
  ledcSetup(0, pwmFrequency, pwmResolution);
  // Verbinde den PWM-Kanal mit dem Pin
  ledcAttachPin(pwmPin, 0);
  // Setze die Relais initial auf LOW (aus)
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
}

void loop() {

  // Beispiel: Schalte das erste Relais ein und das zweite aus
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  Serial.println("Relais 1 eingeschaltet, Relais 2 ausgeschaltet");
  
  // Beispiel: Setze die PWM-Ausgabe auf 128 (50% Duty Cycle)
  ledcWrite(0, 128);
  Serial.println("PWM-Ausgabe auf 50% gesetzt");
  
  delay(2000); // Warte 2 Sekunden
  
  // Beispiel: Schalte das erste Relais aus und das zweite ein
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  Serial.println("Relais 1 ausgeschaltet, Relais 2 eingeschaltet");
  
  // Setze die PWM-Ausgabe auf 255 (100% Duty Cycle)
  ledcWrite(0, 255);
  Serial.println("PWM-Ausgabe auf 100% gesetzt");
  
  delay(2000); // Warte erneut 2 Sekunden
  
}


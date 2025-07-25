#include <Arduino.h>

void setMotor(int duty);
void TestLichtschranke();
u_int16_t getWinkel();

/* Beispiel zum Ansteuern der Basis vom Flying Schlumpf-Projekt
 * Dieses Beispiel steuert den Motor an, der die Basis des Flying Schlumpf-Projekts antreibt.
 * Der Motor wird über PWM angesteuert. Der Winkel der Position der Drehscheibe wird über ein Reedschalter ermittelt. 
 * Schließt der Reedschalter, steht der Winkel auf 0′ anschließend wird mit einer Drehscheibe mit einer Lichtschranke Impulse pro 
 * 4° Drehung-Winkel erzeugt.
 * 
 * Dieses Beispiel ist für das ESP32-Board ausgelegt und verwendet die Arduino-Framework-Bibliothek.
*/ 

// Definitionen für den Motor-PWM
const int pwmMotor = 19;          // GPIO 19, Steuerung des Motors
const int pwmChannelMotor = 0;    // Kanal für den Motor
const int pwmFreqMotor = 6000;    // PWM-Frequenz für den Motor
const int pwmResolutionMotor = 8; // 10 Bit (0-1023)

const int lichtschranke = 34; // Lichtschranke, misst die Drehung des Motors in 4° Schritten
const int reedschalter =18; // Reedschalter zum Finden des Nullpunktes der Drehung

int winkel = 0; // Aktueller Winkel des Motors, wird von der Lichtschranke bestimmt

// Methode, die von dem Event aufgerufen wird, wenn der Reedschalter betätigt wird
void IRAM_ATTR onReedSwitchTriggered()
{
  // Hier könnte eine Logik implementiert werden, die den Motor auf den Nullpunkt zurücksetzt
  winkel = 0; // Setzt den Winkel auf 0, wenn der Reedschalter betätigt wird
}

// Methode, um bei einem Lichtschrankenereignis den Winkel um 4° zu erhöhen
void IRAM_ATTR onLichtschrankeTriggered()
{
  //Entprellen des Signals
  static unsigned long lastInterruptTime = 0;
  unsigned long interruptTime = millis();
  if (interruptTime - lastInterruptTime < 100) // Entprellzeit von 50 ms
  {
    return; // Wenn die Entprellzeit noch nicht abgelaufen ist, wird die Funktion abgebrochen
  }
  lastInterruptTime = interruptTime; // Aktualisiert die Zeit des letzten Interrupts
  // Erhöht den Winkel um 4°
  winkel += 4; 
  if (winkel >= 360) // Wenn der Winkel 360° erreicht, wird er auf 0 zurückgesetzt
  {
    winkel = 0; // Setzt den Winkel auf 0, wenn er 360° erreicht
  }
}

void setup()
{
  Serial.begin(115200);
  pinMode(lichtschranke, INPUT); // Lichtschranke als Eingang

  ledcSetup(pwmChannelMotor, pwmFreqMotor, pwmResolutionMotor);
  ledcAttachPin(pwmMotor, pwmChannelMotor);
  ledcWrite(pwmChannelMotor, 0);

  pinMode(reedschalter, INPUT_PULLUP); // Reedschalter als Eingang

  // Negative Flanke des Reedschalters wird verwendet, um den Nullpunkt zu finden
  attachInterrupt(reedschalter, onReedSwitchTriggered, FALLING);

  // Negative Flanke der Lichtschranke wird verwendet, um den Winkel zu erhöhen
  attachInterrupt(lichtschranke, onLichtschrankeTriggered, RISING);

  setMotor(128); // Setzt den Motor auf eine Anfangsgeschwindigkeit von 25%
}

void loop()
{
  // Ausgabe des aktuellen Winkels
  Serial.print("Aktueller Winkel: ");
  Serial.println(getWinkel());

  delay(500); // Kurze Pause, um die Ausgabe lesbar zu halten
  // motorFadingTest();
}

void motorFadingTest()
{
  // Fading von 0 bis 255
  for (int duty = 0; duty <= 255; duty += 25)
  {
    setMotor(duty);
  }
  for (int duty = 255; duty >= 0; duty -= 25)
  {
    setMotor(duty);
  }
}

void setMotor(int duty)
{
  Serial.print("Setze Motor auf: ");
  Serial.println(duty);
  ledcWrite(pwmChannelMotor, duty);
  delay(1500);

  // Ausgabe des aktuellen Winkels
  Serial.print("Aktueller Winkel: ");
  Serial.println(getWinkel());

}

u_int16_t getWinkel()
{
  return winkel;
}
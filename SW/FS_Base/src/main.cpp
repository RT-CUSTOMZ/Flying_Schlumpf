#include <Arduino.h>
// Definitionen für den Motor-PWM
const int pwmMotor = 19;          // GPIO 19, Steuerung des Motors
const int pwmChannelMotor = 0;    // Kanal für den Motor
const int pwmFreqMotor = 6000;    // PWM-Frequenz für den Motor
const int pwmResolutionMotor = 8; // 10 Bit (0-1023)

const int lichtschranke = 34; // Lichtschranke, misst die Drehung des Motors in 4° Schritten

void setup()
{
  Serial.begin(115200);
  pinMode(lichtschranke, INPUT_PULLUP); // Lichtschranke als Eingang

  ledcSetup(pwmChannelMotor, pwmFreqMotor, pwmResolutionMotor);
  ledcAttachPin(pwmMotor, pwmChannelMotor);
  ledcWrite(pwmChannelMotor, 0);
}

void loop()
{
  digitalRead(lichtschranke); // Abfrage der Lichtschranke
  while (digitalRead(lichtschranke) == HIGH)
  {
    // Warten, bis die Lichtschranke durchbrochen wird
    delay(100);
  }
  Serial.println("Lichtschranke durchbrochen");
  while (digitalRead(lichtschranke) == LOW)
  {
    // Warten, bis die Lichtschranke durchbrochen wird
    delay(100);
  }
  Serial.println("Lichtschranke nicht durchbrochen");
  
  return; // Beenden von Loop, damit der Motor nicht läuft
  // Fading von 0 bis 255
  for (int duty = 0; duty <= 255; duty += 25)
  {
    ledcWrite(pwmChannelMotor, duty);
    delay(1500);
  }
  for (int duty = 255; duty >= 0; duty -= 25)
  {
    ledcWrite(pwmChannelMotor, duty);
    delay(1500);
  }
}

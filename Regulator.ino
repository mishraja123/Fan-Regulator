#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define Speed1 21
#define Speed2 19
#define Speed4 18

char auth[] = "-R9pMAs-gT5XSHcq0Hf2Mku3i9pLwrRe";
char ssid[] = "tecno";
char pass[] = "kingmishra";

BLYNK_WRITE(V0)
{
  int fan_speed = param.asInt();
  if (fan_speed == 0) 
  {
    digitalWrite(Speed1, LOW);
    digitalWrite(Speed2, LOW);
    digitalWrite(Speed4, LOW);
  }
  if (fan_speed == 1) 
  {
    digitalWrite(Speed1, HIGH);
    digitalWrite(Speed2, LOW);
    digitalWrite(Speed4, LOW);
  }
  if (fan_speed == 2) 
  {
    digitalWrite(Speed2, HIGH);
    digitalWrite(Speed1, LOW);
    digitalWrite(Speed4, LOW);
  }
  if (fan_speed == 3)
  {
    digitalWrite(Speed1, HIGH);
    digitalWrite(Speed2, HIGH);
    digitalWrite(Speed4, LOW);
  }
  if (fan_speed == 4)
  {
    digitalWrite(Speed4, HIGH);
    digitalWrite(Speed1, LOW);
    digitalWrite(Speed2, LOW);
  }
}
void setup() 
{
  Serial.begin(115200);
  pinMode(Speed1, OUTPUT);
  pinMode(Speed2, OUTPUT);
  pinMode(Speed4, OUTPUT);


  digitalWrite(Speed1, LOW);
  digitalWrite(Speed2, LOW);
  digitalWrite(Speed4, LOW);
  Blynk.begin(auth, ssid, pass);
}

void loop() 
{
  Blynk.run();
}

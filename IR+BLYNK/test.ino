#include <ESP8266WiFi.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin("moto g42_2324", "Madhumita1978");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.println("..");
    delay(200);
  }
  Serial.println();
  Serial.println("NodeMCU is Connected!");
  Serial.println(WiFi.localIP());
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

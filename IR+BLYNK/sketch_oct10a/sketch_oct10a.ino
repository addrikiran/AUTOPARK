#define BLYNK_TEMPLATE_ID "TMPL3-DT2rPDS"
#define BLYNK_TEMPLATE_NAME "IRFINAL"
#define BLYNK_AUTH_TOKEN "DJgAqFG4bEqa-dMtpR6UocNK-5r8HJcr"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Kiran's Moto";
char pass[] = "Addri123";

bool ir1,ir2;
#define IRpin1 D2
#define IRpin2 D3

// This function is called every time the Virtual Pin 0 state changes


BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V0);
  Blynk.syncVirtual(V1);

}


void setup(){
  pinMode(IRpin1, INPUT);
  pinMode(IRpin2, INPUT);
  //pinMode(2, OUTPUT); // Initialise digital pin 2 as an output pin
  Serial.begin(115200);
  delay(100);
  Blynk.begin(auth, ssid, pass);
}

void loop(){
   ir1= digitalRead(IRpin1);
  if(ir1==0){
    Serial.println("Object Present");
  }
  else if(ir1==1){
    Serial.println("Empty");

  }
  ir2= digitalRead(IRpin2);
  if(ir2==0){
    Serial.println("Object Present");
  }
  else if(ir2==1){
    Serial.println("Empty");

  }
  Blynk.run();
  Blynk.virtualWrite(V0, ir1);
  Blynk.virtualWrite(V1, ir2);
}

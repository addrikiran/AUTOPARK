#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 15 //D8
#define RST_PIN 2 //D4
#define SERVO_PIN 0 //D3
//int pos=0;
Servo gateServo;
MFRC522 mfrc522(SS_PIN, RST_PIN);

String card_list[2] = {"DEE0E91D","20E59559"};
String user_info[2][4] = {{"Addri Kiran Dey","21","3rd year","Verified"},{"Addri2","21","3rd year","Verified"}};
int total_card;
String card_num;

void setup() {
  Serial.begin(115200);
  SPI.begin();
  mfrc522.PCD_Init();
  gateServo.attach(SERVO_PIN); // Attach servo to D3 pin
  Serial.println();
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial()){
    return;
  }
  else 
  {
    card_num = getCardNumber();
    showData();
  }
}

String getCardNumber(){
  String UID = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    UID += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
    UID += String(mfrc522.uid.uidByte[i], HEX);
  }
  UID.toUpperCase();
  return UID;
}

void showData(){
  String name,age,designation,location;
  boolean user_found = false;
  total_card = sizeof(card_list)/sizeof(card_list[0]);
  
  for(int i=0;i<total_card;i++){
    String check_num = card_list[i];
    if(card_num.equals(check_num)){
      user_found = true;
      
      name = user_info[i][0];
      age = user_info[i][1];
      designation = user_info[i][2];
      location = user_info[i][3];

      Serial.print("Card ID : ");
      Serial.println(card_num);
    
      Serial.print("Name : ");
      Serial.println(name);
    
      Serial.print("Age : ");
      Serial.println(age);
    
      Serial.print("Designation : ");
      Serial.println(designation);
    
      Serial.print("Location : ");
      Serial.println(location);
    
      Serial.println("------------");


      
   
       gateServo.write(180);              
       delay(5000);
       gateServo.write(0);              
       
       
    }  
  }
  if(user_found == false){
    Serial.print("Card ID : ");
    Serial.print(card_num);
    Serial.println(" have not registered.");
    Serial.println("------------");
  }
  delay(1000);
}

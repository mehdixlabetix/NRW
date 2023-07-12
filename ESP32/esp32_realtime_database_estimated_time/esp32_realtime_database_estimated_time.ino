
#include <Arduino.h>
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Insert your network credentials
#define WIFI_SSID "C.l"
#define WIFI_PASSWORD "6rqy3hf8"

// Insert Firebase project API Key
#define API_KEY "AIzaSyAR7Hrs-GJPB2mQ_ycBBx1iP78THeQzLO8"
//"f7kjER9vwhRmeLoO3NCvIBT6L8SFQVl9HuyUqAG2"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://esp32-dht11-4833b-default-rtdb.firebaseio.com/" 

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int c1=0;
int c2=0;

bool signupOK = false;



#define LED_red1 23
#define LED_green1 15

#define LED_red2 14
#define LED_green2 13





 int default_time_g1=3000;
 int default_time_r1=3000;
 int default_time_g2=3000;
 int default_time_r2=3000;
 int tmax=10000;


//tg1=time_green1  ,tr1=time_red1 ,tr2=time_red2 ,tg2=time_green2 
int tg1=0,tr1=0,tg2=0,tr2=0;
int n=1  ;      // variable de multiplication dependan du voie


int estimated_time(int c){
int taille=5;
int vitesse=14;
int nbligne=4;
//temps de reaction +temps de parcours
return (c*0.5+((c/nbligne)*taille+((c/nbligne)-1))/vitesse)*1000;


}

void setup(){
pinMode(LED_red1,OUTPUT); 
pinMode(LED_green1,OUTPUT);

pinMode(LED_red2,OUTPUT); 
pinMode(LED_green2,OUTPUT);


Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("ok");
    signupOK = true;
  }
  else {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);


    
 
  Serial.print("c1 :");

  Serial.println(c1, DEC);
  
  Serial.print("c2 :");
  
  Serial.println(c2, DEC);  

}

void loop(){

if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();
    if (Firebase.RTDB.getInt(&fbdo, "/nrw/aaa/n")) {
      if (fbdo.dataType() == "int") {
        c1 = fbdo.intData();
        Serial.print(" c1 ");
        Serial.println(c1);
      }
    }
    else {
      Serial.println(fbdo.errorReason());
    }
     if (Firebase.RTDB.getInt(&fbdo, "/nrw/aaaa/n1")) {
      if (fbdo.dataType() == "int") {
        c2 = fbdo.intData();
        Serial.print(" c2 ");
        Serial.println(c2);
      }
    }
    else {
      Serial.println(fbdo.errorReason());
    }
}




//LIGHT MANAGEMENT BASED ON ESTIMATED TIME

if(c1 > n*c2){
  tg1=estimated_time(c1);
  tr2=tg1;
  tg2=default_time_g2;
  tr1=default_time_r1;
  if(tg1>=tmax){
    tg1=tmax;
    tr2=tmax;
  }


}
else if( c2> n*c1){
  tg2=estimated_time(c2);
  tr1=tg2;
  tg1=default_time_g1;
  tr2=default_time_r2;
    if(tg2>=tmax){
    tg2=tmax;
    tr1=tmax;
  }

}
else{
  tg1=default_time_g1;
  tr1=default_time_r1;
  tg2=default_time_g2;
  tr2=default_time_r2;

}



 
  Serial.print("estimated_time c1:");

  Serial.println(estimated_time(c1));
  
  Serial.print("estimated_time c2:");

  Serial.println(estimated_time(c2));

Serial.print(" time_green_1//time_red_2 ");
Serial.println(tg1);
Serial.print(" time_green_2//time_red_1 ");
Serial.println(tg2);
digitalWrite(LED_red2,HIGH); 
digitalWrite(LED_green1,HIGH); 
delay(tg1);
digitalWrite(LED_red2,LOW); 
digitalWrite(LED_green1,LOW); 
digitalWrite(LED_red1,HIGH); 
digitalWrite(LED_green2,HIGH); 


delay(tg2);
digitalWrite(LED_red1,LOW); 
digitalWrite(LED_green2,LOW); 

}

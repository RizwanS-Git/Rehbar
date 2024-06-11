
#include <WiFi.h>
#include <ThingSpeak.h>    //using thingspeak library
WiFiClient client;
//#define LED 15

//#define RXp2 16
//#define TXp2 17

int count =0;

long myChannelNumber = 2557363;     //write your channel ID 
const char myWriteAPIKey[] = "E8FU3EG7RDH9ZBMT"; //write your channel API key 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
 // Serial2.begin(115200, SERIAL_8N1, RXp2, TXp2);
 
//  pinMode(LED , OUTPUT);

  WiFi.begin("Redmi", "qwertyui");                      //write your wifi name and passward
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
 // digitalWrite(LED,HIGH);
  Serial.println("1");
 // Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

void loop()
 {
 // if(Serial2.available()!=0)
 // {
 //   if(count==1)
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
      float current = analogRead(12);
      Serial.println(current);
      ThingSpeak.writeField(myChannelNumber,2,current,myWriteAPIKey);
    //  count=0;
   // }
//   if(count==0)
  //  {  
       float voltage = analogRead(14);
       Serial.println(voltage);
      ThingSpeak.writeField(myChannelNumber,1,voltage,myWriteAPIKey);
   //   count++;
 //   }
 // delay(1000);
  }
//}

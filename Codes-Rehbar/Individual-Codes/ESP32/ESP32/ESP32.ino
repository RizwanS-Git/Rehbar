
#include <WiFi.h>
#include <ThingSpeak.h>    //using thingspeak library
WiFiClient client;

#define RXp2 16
#define TXp2 17

int count =0;

long myChannelNumber = 2516560;     //write your channel ID 
const char myWriteAPIKey[] = "TSDZX054G8I313BC"; //write your channel API key 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXp2, TXp2);

  WiFi.begin("Dexter", "40867e58");                      //write your wifi name and passward
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
 // Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

void loop()
 {
  if(Serial2.available()!=0)
  {
    if(count==0)
    {  
      String current = Serial2.readStringUntil('\n');
      ThingSpeak.writeField(myChannelNumber,2,current,myWriteAPIKey);
      count++;
    }
    if(count==1)
    {  
       String voltage = Serial2.readStringUntil('\n');
      ThingSpeak.writeField(myChannelNumber,1,voltage,myWriteAPIKey);
      count=0;
    }
  delay(1000);
  }
}

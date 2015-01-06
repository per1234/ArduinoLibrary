#include <DHT.h> //temperature and humidity library
#include <Decoded.h> //Our library
#include <Servo.h> //Servo motor library
#include <Ethernet.h> //internet library
#include <SPI.h> //communication library
#include <SoftwareSerial.h> //talk with computer

//this is your specific end point.
  String url= "/api/?uid=8a7827b9813f7a054484109a28905793&trigger=dv2nn&value=";  
//this is to identify your computer
  byte computer = 0xAD; //change to your choice...
//this is the object that handles all communication with the arduino
  Decoded decoded(Serial, computer);
  
int rfidPin = 3;//PWM


void setup()
{
  Serial.begin(9600);
  Serial.println("Starting up");
  decoded.setupInternet();  
  decoded.addRFID(3);
  Serial.println("ready...");
}

void loop()
{
   String checkChar = decoded.checkForRFID();
  if(checkChar.length() > 0)  {
       Serial.println(checkChar);
       decoded.hitTriggerUrl(url, checkChar);
  }

  delay(250);
}

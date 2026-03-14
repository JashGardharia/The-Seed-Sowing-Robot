#include <WiFi.h>
#include <ESP32Servo.h>

const char* ssid = "SeedSowingRobot";
const char* password = "12345678";

WiFiServer server(80);

Servo seedServo;

int IN1 = 27;
int IN2 = 26;
int IN3 = 25;
int IN4 = 33;

int ENA = 14;
int ENB = 12;

int servoPin = 13;

bool seedState = false;

void forward(){digitalWrite(IN1,HIGH);digitalWrite(IN2,LOW);digitalWrite(IN3,HIGH);digitalWrite(IN4,LOW);}
void back(){digitalWrite(IN1,LOW);digitalWrite(IN2,HIGH);digitalWrite(IN3,LOW);digitalWrite(IN4,HIGH);}
void left(){digitalWrite(IN1,LOW);digitalWrite(IN2,HIGH);digitalWrite(IN3,HIGH);digitalWrite(IN4,LOW);}
void right(){digitalWrite(IN1,HIGH);digitalWrite(IN2,LOW);digitalWrite(IN3,LOW);digitalWrite(IN4,HIGH);}
void stopRobot(){digitalWrite(IN1,LOW);digitalWrite(IN2,LOW);digitalWrite(IN3,LOW);digitalWrite(IN4,LOW);}

void seedOn(){seedServo.write(90);seedState=true;}
void seedOff(){seedServo.write(0);seedState=false;}

String page(){
String p="<!DOCTYPE html><html><head><meta name='viewport' content='width=device-width, initial-scale=1'>";
p+="<style>";
p+="body{margin:0;font-family:Arial;background:linear-gradient(135deg,#000,#444);color:white;text-align:center}";
p+="h1{margin-top:30px}";
p+=".btn{width:120px;height:70px;font-size:18px;margin:10px;border:none;border-radius:12px;background:#777;color:white;transition:0.2s}";
p+=".btn:active{background:#00ff55;box-shadow:0 0 20px #00ff55}";
p+=".seedon{background:#00aa33}";
p+=".seedoff{background:#cc0000}";
p+="</style></head><body>";

p+="<h1>Seed Sowing Robot</h1>";

p+="<div>";
p+="<a href='/forward'><button class='btn'>Forward</button></a><br>";
p+="<a href='/left'><button class='btn'>Left</button></a>";
p+="<a href='/stop'><button class='btn'>Stop</button></a>";
p+="<a href='/right'><button class='btn'>Right</button></a><br>";
p+="<a href='/back'><button class='btn'>Back</button></a>";
p+="</div><br>";

if(seedState)
p+="<a href='/seedoff'><button class='btn seedon'>Seed Sowing: ON</button></a>";
else
p+="<a href='/seedon'><button class='btn seedoff'>Seed Sowing: OFF</button></a>";

p+="</body></html>";
return p;
}

void setup(){
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);

pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);

analogWrite(ENA,200);
analogWrite(ENB,200);

seedServo.attach(servoPin);
seedServo.write(0);

Serial.begin(115200);

WiFi.softAP(ssid,password);

Serial.print("Robot IP: ");
Serial.println(WiFi.softAPIP());

server.begin();
}

void loop(){
WiFiClient client=server.available();
if(!client)return;

String req=client.readStringUntil('\r');
client.flush();

if(req.indexOf("/forward")!=-1)forward();
if(req.indexOf("/back")!=-1)back();
if(req.indexOf("/left")!=-1)left();
if(req.indexOf("/right")!=-1)right();
if(req.indexOf("/stop")!=-1)stopRobot();

if(req.indexOf("/seedon")!=-1)seedOn();
if(req.indexOf("/seedoff")!=-1)seedOff();

client.println("HTTP/1.1 200 OK");
client.println("Content-type:text/html");
client.println();
client.println(page());
client.println();

delay(1);
client.stop();
} 

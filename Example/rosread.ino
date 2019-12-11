

#include <WiFi.h>
#include <ros.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Empty.h>
#include <std_msgs/String.h>


const char* ssid     = "";
const char* password = "";
IPAddress server(192,168,43,44);
const uint16_t serverPort = 11411;
String control; 
//Creating a Nodehandle object
ros::NodeHandle nh;

void messageCb1( const std_msgs::Int32& toggle_msg){
var=toggle_msg.data;
Serial.println(toggle_msg.data);
    if(var > 2000)
   digitalWrite(4, HIGH);   // turn on the led
      else
   digitalWrite(4, LOW);   // turn off the led
  
}

void messageCb3( const std_msgs::String& toggle_msg){
control=toggle_msg.data;
if(control.equals("led_be"))
   digitalWrite(4, HIGH);   // turn on the led
if(control.equals("led_ki"))
   digitalWrite(4, LOW);   // turn off the led
 if(control.equals("led_blink"))
 while (control.equals("led_blink")){
  
  digitalWrite(4,HIGH-digitalRead(4)); // blink the led
  nh.spinOnce();
  delay(500);
  
  } 
  
}

void messageCb2( const std_msgs::Empty& test){

  digitalWrite(4,HIGH-digitalRead(4));
}

ros::Subscriber<std_msgs::Int32> sub1("chat", &messageCb1 );
ros::Subscriber<std_msgs::Empty> sub2("toggle_led", &messageCb2 );
ros::Subscriber<std_msgs::String> sub3("led_control", &messageCb3);

void setup()
{
  pinMode(4, OUTPUT);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  nh.getHardware()->setConnection(server, serverPort);
  nh.initNode();
  Serial.print("IP = ");
  Serial.println(nh.getHardware()->getLocalIP());
  nh.subscribe(sub1);
  nh.subscribe(sub2);
  nh.subscribe(sub3);
}


void loop()
{
  nh.spinOnce();
  delay(1);
}

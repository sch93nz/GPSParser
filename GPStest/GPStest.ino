
#include <GPSparser.h>
#include <SoftwareSerial.h>

SoftwareSerial GPSconnect(3,2);
GPSparser pars;


void setup() {
  Serial.begin(115200);
  GPSconnect.begin(9600);

  Serial.println("GPS Example 1");
  Serial.println("Displaying the raw NMEA data transmitted by GPS module.");
  Serial.println("by Mikal Hart");
  Serial.println();

  // put your setup code here, to run once:

}


void loop() {
 int length = GPSconnect.available();
 char data[length];
 int i=0;
 for(i=0;i<length;++i){
  data[i]=GPSconnect.read();
 }
 String information = String(data);
 
 int last = information.lastIndexOf('$');
 
 String dat = information.substring(last);
 dat.trim();
 char info[dat.length()];
 dat.toCharArray(info,dat.length());
 pars.giveData(info,dat.length());
 
 delay(3000);
}

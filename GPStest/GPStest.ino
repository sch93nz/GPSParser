
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

long time;

void loop() {
 
 int length = GPSconnect.available();
 char data[length];
 int i=0;
 for(i=0;i<length;++i){
  data[i]=GPSconnect.read();
 }
 String information = String(data);
 
 int last = information.lastIndexOf('$');
 
 String dat = information.substring(last,0);
 dat.trim();
 char info[dat.length()];
 dat.toCharArray(info,dat.length());
// Serial.print("pure out put ");
// Serial.println(data);
// Serial.print("out put   ");
// Serial.println(dat);
 
 pars.giveData(info,dat.length());

  long diff = millis() - time;
  if(diff >950 && diff < 1050){
    Serial.println("Starting read");
    time = millis();
    String hata = String("ModeOne "+ String(pars.ModeOne())+
    " ModeTwo "+ String(pars.ModeTwo()));
    
    Serial.println(hata);

    if(pars.ModeTwo()!='1'){
      Serial.println("We should havve more data");
    }
  }
 delay(250);
 
}

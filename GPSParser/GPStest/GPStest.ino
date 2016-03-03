
#include <GPSparser.h>
#include <SoftwareSerial.h>

#define zpin A2
#define ypin A1
#define xpin A0

void ADXL3handle();
void GPShandle();
void calibrate();

SoftwareSerial GPSconnect(2, 3);
GPSparser pars;

int Xcenter, Ycenter, Zcenter;

long time;
long time2;
int X, Y, Z;

void setup() {
  Serial.begin(19200);
  GPSconnect.begin(9600);

  Serial.println("GPS Example 1");
  Serial.println("Displaying the raw NMEA data transmitted by GPS module.");
  Serial.println("by Mikal Hart");
  Serial.println();

  time = millis();
  time2 = millis();
  // put your setup code here, to run once:
  calibrate();
  Serial.println("Calibration complete");
}

void calibrate() {
  int i = 0; X = 0; Y = 0; Z = 0;
  for (i = 0; i < 10; ++i) {
    X += analogRead(xpin);
    Y += analogRead(ypin);
    Z += analogRead(zpin);
    delay(100);
  }

  Xcenter = abs(X / i);
  Ycenter = abs(Y / i);
  Zcenter = abs(Z / i);
}

void loop() {

  GPShandle();

  //ADXL3handle();

  //delay(10);

}
int count =0;

void ADXL3handle() {
  count++;

  long diff = millis() - time2;
  X += (analogRead(xpin) - Xcenter);
  Y += (analogRead(ypin) - Ycenter);
  Z += (analogRead(zpin) - Zcenter);

  if (diff > 1000) {
    float xlocal = X / count;
    if (xlocal > 0) {
      xlocal = xlocal * 1.185f;
    } else {
      xlocal = xlocal * 2.0f;
    }

    float ylocal = Y / count;
    if (ylocal > 0) {
      ylocal = ylocal * 1.975f;
    } else {
      ylocal = ylocal * 1.8666f;
    }

    float zlocal = Z / count;// * 0.05f;


    Serial.println();
    Serial.print("X axis: ");
    Serial.print(xlocal);
    Serial.print(" deg\t Y axis: ");
    Serial.print(ylocal);
    Serial.print(" deg\t Z axis: ");
    Serial.print(zlocal);
    Serial.println(" mm");
    X = 0; Y = 0; Z = 0; count =0;
    time2 = millis();
  }
}

void GPShandle() {

  int length = GPSconnect.available();
  char data[length] ;

  int i = 0;
  for (i = 0; i < length; ++i) {
    data[i] = GPSconnect.read();
  }
  String information = String(data);

  int last = information.indexOf('*');
  int first = information.indexOf('$');
  if (last < first) {
    last = information.lastIndexOf('*');
  }
  String dat = information.substring(first, last);

  dat.trim();

  char info[dat.length()];
  dat.toCharArray(info, dat.length());
   // Serial.print("pure out ");
   // Serial.print(information);
   // Serial.println("|");
  //
  //  Serial.print("out put  ");
  //  Serial.print(dat);
  //  Serial.println("|");


  if (dat.length() > 10) {
    pars.giveData(info, dat.length());
  }
  long diff = millis() - time;
  if (diff > 1000) {
    time = millis();
    String hata = String("ModeOne " + String(pars.ModeOne()) +
                         " ModeTwo " + String(pars.ModeTwo()));

    Serial.println(hata);

    if (pars.ModeTwo() != '1' && pars.ModeTwo() != '#') {
      Serial.println("We should havve more data");
    }
    // pars.clearData();
  }

}


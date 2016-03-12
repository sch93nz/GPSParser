#include <SD.h>
#include <MemoryFree.h>
#include <GPSparser.h>
#include <SoftwareSerial.h>

#define zpin A2
#define ypin A1
#define xpin A0

void ADXL3handle();
void GPShandle();
void calibrate();
void Write(String t);
void Write(float d);
void createFilename();
void testMem(int i);

SoftwareSerial GPSconnect(6, 5); //rx,tx
GPSparser pars;

int Xcenter, Ycenter, Zcenter;

long time;

int X, Y, Z;

String filename;

void setup() {
 
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  Serial.begin(19200);
  GPSconnect.begin(9600);
  if (!SD.begin(4)) {
    Serial.println("no SD Card");
  }
  pars.clearData();

  delay(1000);
  time = millis();

  calibrate();
  createFilename();
  //Serial.println("Setup Done");
  digitalWrite(13, LOW);
}

void calibrate() {
  int i = 0; X = 0; Y = 0; Z = 0;
  for (i = 0; i < 20; ++i) {
    X += analogRead(xpin);
    Y += analogRead(ypin);
    Z += analogRead(zpin);
    //GPShandle();
    delay(100);
  }

  Xcenter = abs(X / i);
  Ycenter = abs(Y / i);
  Zcenter = abs(Z / i);
}

void loop() {
 // testMem(0);
  //GPShandle();

  ADXL3handle();
  long diff = millis() - time;
  if (diff > 1000) {
    time = millis();
    //Write("this test data and should not be considered to be relevent in any way");
    //Write(99875);
    //Write("this to is \r\ntest data ");
  }
  delay(250);

}
int count = 0;

void ADXL3handle() {
  count++;

  long diff = millis() - time;
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

    Write(millis());
    Write(",");
  //  Write("\r\n");
   // Write("X axis: ");
    Write(xlocal);
    Write(",");
  //  Write(" deg\t Y axis: ");
    Write(ylocal);
    Write(",");
  //  Write(" deg\t Z axis: ");
    Write(zlocal);
    Write(",");
    Write("degress");
        Write("\r\n");
    
     Write(millis());
    Write(",");
    Write(X/count);
    Write(",");
    Write(Y/count);
    Write(",");
    Write(Z/count);
        Write(",");
    Write("Direct");
    Write("\r\n");
  //  Write(" mm");
   // Write("\r\n");
    X = 0; Y = 0; Z = 0; count = 0;
  }
}

void GPShandle() {
//  testMem(1);
  int length = GPSconnect.available();
  Serial.println("length =" + String(length));
  if ( length > 0) {
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
    information = information.substring(first, last);

    information.trim();


    information.toCharArray(data, information.length());
    //testMem(2);

    Serial.println(information);

    pars.giveData(data, information.length());
    testMem(3);
    long diff = millis() - time;
    Serial.println("diff =" + diff);
    if (diff > 1000) {
  //    testMem(4);
      String hata = String("ModeOne " + String(pars.ModeOne()) +
                           " ModeTwo " + String(pars.ModeTwo()) + "\r\n");

      Write(hata);
      String namesInfo = String(pars.getNames());

      if (pars.checkVTG()) {
        Write(pars.printVTG());
      }
      if (pars.checkRMC()) {
        Write(pars.printRMC());
      }
      if (pars.checkGSA()) {
        Write(pars.printGSA());
      }
      if (pars.checkGGA()) {
        Write(pars.printGGA());
      }

      if (pars.ModeTwo() != '1' && pars.ModeTwo() != '@') {

        Write("We should have more data\r\n");
      }

    }
  }
}

void Write(float d) {
  Write(String(d));
}

void Write(String t) {
 // testMem(5);
  File myFile = SD.open(filename, FILE_WRITE);

  if (myFile) {
    Serial.print(t);
    //Serial.println("Bytes Writen " + String(
      myFile.print(t);//));
    myFile.flush();


  } else {
    Serial.println("fail to write");
    Serial.print(t);
  }
  myFile.close();
  //testMem(6);
}



void createFilename() {
  filename = String(millis()); ;//String(pars.UTC());
  filename = filename.substring(0, 6);
  filename = "D" + filename + ".txt";
  Serial.println(filename);
  Write("Start at "+String(millis())+"\r\n");
}

void testMem(int end) {
  Serial.println();
  for (int i = 0; i < end; ++i) {
    Serial.print("\t");
  }
  Serial.print(String(end) + " free = ");
  Serial.println(freeMemory());

}




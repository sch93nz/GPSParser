#pragma once


struct RMC {

	float UTC,latitude, longitude,speed,course;
	char N_S, E_W,Status;
};

struct VTG {
	float Tcourse, Mcourse, speedKnots, speedKilometers;
};

struct GSA {
	char ModeOne, ModeTwo;
	float satID[12];
	float PDOP, HDOP, VDOP;
};

class GPSparser {

private:
	RMC *dataRMC;
	VTG *dataVTG;
	GSA *dataGSA;

	void StripVTG(char *data, int length);
	void StripRMC(char *data, int length);
	void StripGSA(char *data, int length);

	float charTofloat(char *data);

public:

	void giveData(char *info,int length);
	void clearData();
	
	//VTG data
	
	float Tcourse();
	float Mcourse();
	float speedKnots();
	float speedKilometers();

	//RMC data

	float Latitude();
	float Longitude();
	float speed();
	float course();
	char N_S_direction();
	char E_W_direction();

	//GSA data

	char ModeOne();
	char ModeTwo();
	float* satIDs();
	float PDOP();
	float HDOP();
	float VDOP();

};
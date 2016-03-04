#pragma once


struct RMC {
	char name[7];
	float UTC,latitude, longitude,speed,course;
	char N_S, E_W,Status;
};

struct VTG {
	char name[7];
	float Tcourse, Mcourse, speedKnots, speedKilometers;
};

struct GGA {
	char name[7];
	float UTC, latitude, Longitude, Fix, Satellites, HDOP, MSL, GeoSep;
	char N_S, E_W, AltUnit, GeoSepUnit;
};

struct GSA {
	char name[7];
	char ModeOne, ModeTwo;
	float satID[12];
	float PDOP, HDOP, VDOP;
};

class GPSparser {

private:
	RMC dataRMC;
	VTG dataVTG;
	GSA dataGSA;
	GGA dataGGA;
	char Names[34];

	void StripVTG(char *data, int length);
	void clearVTG();
	void StripRMC(char *data, int length);
	void clearRMC();
	void StripGSA(char *data, int length);
	void clearGSA();
	void StripGGA(char *data, int length);
	void clearGGA();

	double atof(char *s);
	bool isdigit(char t);
	bool isspace(char t);

public:

	void giveData(char *info,int length);
	void clearData();
	char* getNames();
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

	//GGA data

	float Satalllites();
	float MSL();
	float Fix();
	float GeoSep();
	float UTC();

};
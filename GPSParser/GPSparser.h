#pragma once


struct RMC {
	char name[7];
	char UTC[11]; 
	char latitude[11];
	char longitude[11];
	char speed[6];
	char course[6];
	char N_S, E_W,Status;
};

struct VTG {
	char name[7];
	char Tcourse[7];
	char Mcourse[7];
	char speedKnots[5];
	char speedKilometers[5];
};

struct GGA {
	char name[7];
	char UTC[11];
	char latitude[11];
	char longitude[11]; 
	char Satellites[2];
	char HDOP[5];
	char MSL[5];
	char GeoSep[5];
	char Fix,N_S, E_W, AltUnit, GeoSepUnit;
};

struct GSA {
	char name[7];
	char ModeOne, ModeTwo;
	float satID[12];
	char PDOP[5];
	char HDOP[5];
	char VDOP[5];
};

class GPSparser {

private:
	RMC dataRMC;
	VTG dataVTG;
	GSA dataGSA;
	GGA dataGGA;
	char Names[34];
	char printout[120];

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
	
	char* Tcourse();
	char* Mcourse();
	char* speedKnots();
	char* speedKilometers();
	char * printVTG();

	//RMC data

	char* Latitude();
	char* Longitude();
	char* speed();
	char* course();
	char N_S_direction();
	char E_W_direction();

	//GSA data

	char ModeOne();
	char ModeTwo();
	float* satIDs();
	char* PDOP();
	char* HDOP();
	char* VDOP();

	//GGA data

	char* Satalllites();
	char* MSL();
	char Fix();
	char* GeoSep();
	char* UTC();

};
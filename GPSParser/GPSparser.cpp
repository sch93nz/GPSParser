#include "GPSparser.h"


void GPSparser::StripVTG(char * data, int length)
{
	int i = 0;
	bool kill = true;
	
	clearVTG();
	char  ref;

	

	// Name
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			dataVTG.name[i] = data[i];
			dataVTG.name[i + 1] = '\0';
		}
		else {
			kill = false;
		}
	}
	kill = true;

	//Tcourse
	{
		char temp[10];
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				temp[t] = data[i];
				++t;
			}
			else {
				kill = false;
			}
		}
		float item;
		if (t > 0) {
			item = atof(temp);
		}
		else {
			item = -1.0;
		}
		dataVTG.Tcourse = item;
		kill = true;
	}

	//Reference
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			ref = data[i];
		}
		else {
			kill = false;
		}
	}
	kill = true;

	//Mcourse
	{
		char temp[10];
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				temp[t] = data[i];
				++t;
			}
			else {
				kill = false;
			}
		}
		float item;
		if (t > 0) {
			item = atof(temp);
		}
		else {
			item = -1.0;
		}
		dataVTG.Mcourse = item;
		kill = true;
	}

	//Reference
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			ref = data[i];
		}
		else {
			kill = false;
		}
	}
	kill = true;

	//speedKnots
	{
		char temp[10];
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				temp[t] = data[i];
				++t;
			}
			else {
				kill = false;
			}
		}
		float item;
		if (t > 0) {
			item = atof(temp);
		}
		else {
			item = -1.0;
		}
		dataVTG.speedKnots = item;
		kill = true;
	}

	//Reference
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			ref = data[i];
		}
		else {
			kill = false;
		}
	}
	kill = true;

	//speedKilometers
	{
		char temp[10];
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				temp[t] = data[i];
				++t;
			}
			else {
				kill = false;
			}
		}
		float item;
		if (t > 0) {
			item = atof(temp);
		}
		else {
			item = -1.0;
		}
		dataVTG.speedKilometers = item;
		kill = true;
	}

	//Reference
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			ref = data[i];
		}
		else {
			kill = false;
		}
	}
	kill = true;

	//Reference
	for (; i <= length && kill; ++i) {
		if (data[i] != ','&&data[i] != '*') {
			ref = data[i];
		}
		else {
			kill = false;
		}
	}
	kill = true;

}

void GPSparser::clearVTG()
{
	dataVTG.name[0] = '\0';
	dataVTG.Mcourse = -1.0f;
	dataVTG.speedKilometers = -1.0f;
	dataVTG.speedKnots = -1.0f;
	dataVTG.Tcourse = -1.0f;
}

void GPSparser::StripRMC(char * data, int length)
{
	int i = 0;
	bool kill = true;
	
	clearRMC();
	char Status, N_S, E_W;
	
	// Name
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			dataRMC.name[i] = data[i];
			dataRMC.name[i + 1] = '\0';
		}
		else {
			kill = false;
		}
	}

	kill = true;

	// UTS
	{
		char temp[10];
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				temp[t] = data[i];
				++t;
			}
			else {
				kill = false;
			}
		}
		float item;
		if (t > 0) {
			item = atof(temp);
		}
		else {
			item = -1.0;
		}
		dataRMC.UTC = item;
		kill = true;
	}

	// satus
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			Status = data[i];
		}
		else {
			kill = false;
		}
	}
	dataRMC.Status = Status;
	kill = true;
	
	//Latitude
	{
		char temp[10];
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				temp[t] = data[i];
				++t;
			}
			else {
				kill = false;
			}
		}
		float item;
		if (t > 0) {
			item = atof(temp);
		}
		else {
			item = -1.0;
		}
		dataRMC.latitude = item;
		kill = true;
	}

	//N_S
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			N_S = data[i];
		}
		else {
			kill = false;
		}
	}
	dataRMC.N_S = N_S;
	kill = true;
	
	//lon
	{
		char temp[10];
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				temp[t] = data[i];
				++t;
			}
			else {
				kill = false;
			}
		}
		float item;
		if (t > 0) {
			item = atof(temp);
		}
		else {
			item = -1.0;
		}
		dataRMC.longitude = item;
		kill = true;
	}

	//E_W
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			E_W = data[i];
		}
		else {
			kill = false;
		}
	}
	dataRMC.E_W = E_W;
	kill = true;

	//Speed
	{
		char temp[10];
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				temp[t] = data[i];
				++t;
			}
			else {
				kill = false;
			}
		}
		float item;
		if (t > 0) {
			item = atof(temp);
		}
		else {
			item = -1.0;
		}
		dataRMC.speed = item;
		kill = true;
	}

	//course
	{
		char temp[10];
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				temp[t] = data[i];
				++t;
			}
			else {
				kill = false;
			}
		}
		float item;
		if (t > 0) {
			item = atof(temp);
		}
		else {
			item = -1.0;
		}
		dataRMC.course = item;
		kill = true;
	}


}

void GPSparser::clearRMC()
{
	dataRMC.name[0] = '\0';
	dataRMC.course = -1.0f;
	dataRMC.E_W = '\0';
	dataRMC.latitude = -1.0f;
	dataRMC.longitude = -1.0f;
	dataRMC.N_S = '\0';
	dataRMC.speed = -1.0f;
	dataRMC.Status = '\0';
	dataRMC.UTC = -1.0;
}

void GPSparser::StripGSA(char * data, int length)
{
	int i = 0;
	bool kill = true;

	clearGSA();

	
	// Name
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			dataGSA.name[i] = data[i];
			dataGSA.name[i + 1] = '\0';
		}
		else {
			kill = false;
		}
	}
	 
	kill = true;

	// Mode 1
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			dataGSA.ModeOne = data[i];
		}
		else {
			kill = false;
		}
	}

	kill = true;

	// Mode 2
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			dataGSA.ModeTwo = data[i];
		}
		else {
			kill = false;
		}
	}

	kill = true;
	
	// satID
	for (int k = 0; k < 12; ++k) {
		char temp[4];
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				temp[t] = data[i];
				++t;
			}
			else {
				kill = false;
			}
		}
		float item;
		if (t > 0) {
			item = atof(temp);
		}
		else {
			item = -1.0;
		}
		dataGSA.satID[k] = item;
		kill = true;
	}

	// PDOP
	{
	char temp[10];
	int t = 0;
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			temp[t] = data[i];
			++t;
		}
		else {
			kill = false;
		}
	}
	float item;
	if (t > 0) {
		item = atof(temp);
	}
	else {
		item = -1.0;
	}
	dataGSA.PDOP = item;
	kill = true;
}
	
	// HDOP
	{
	char temp[10];
	int t = 0;
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			temp[t] = data[i];
			++t;
		}
		else {
			kill = false;
		}
	}
	float item;
	if (t > 0) {
		item = atof(temp);
	}
	else {
		item = -1.0;
	}
	dataGSA.HDOP = item;
	kill = true;
}
	
	// VDOP
	{
		char temp[10];
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',' && data[i] != '*') {
				temp[t] = data[i];
				++t;
			}
			else {
				kill = false;
			}
		}
		float item;
		if (t > 0) {
			item = atof(temp);
		}
		else {
			item = -1.0;
		}
		dataGSA.VDOP = item;
		kill = true;
	}

}

void GPSparser::clearGSA()
{
	dataGSA.name[0] = '\0';
	dataGSA.HDOP = -1.0f;
	dataGSA.ModeOne = '\0';
	dataGSA.ModeTwo = '\0';
	dataGSA.PDOP = -1.0f;
	for (int i = 0; i < 12; ++i) {
		dataGSA.satID[i] = -1.0f;
	}
	dataGSA.VDOP = -1.0f;
}

void GPSparser::StripGGA(char * data, int length)
{
	clearGGA();
	int i = 0;
	bool kill = true;
	


	// Name
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			dataGGA.name[i] = data[i];
			dataGGA.name[i + 1] = '\0';
		}
		else {
			kill = false;
		}
	}
	kill = true;
	
	//UTC
	{
		char temp[10];
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				temp[t] = data[i];
				++t;
			}
			else {
				kill = false;
			}
		}
		float item;
		if (t > 0) {
			item = atof(temp);
		}
		else {
			item = -1.0;
		}
		dataGGA.UTC = item;
		kill = true;
	}

	//Latitude
	{
		
		char temp[10];
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				temp[t] = data[i];
				++t;
			}
			else {
				kill = false;
			}
		}
		float item;
		if (t > 0) {
			item = atof(temp);
		}
		else {
			item = -1.0;
		}
		dataGGA.latitude = item;
		kill = true;
	}
		//N_S
	char N_S;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				N_S = data[i];
			}
			else {
				kill = false;
			}
		}
		dataGGA.N_S = N_S;
		kill = true;
	

	//lon
	{
		char temp[10];
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				temp[t] = data[i];
				++t;
			}
			else {
				kill = false;
			}
		}
		float item;
		if (t > 0) {
			item = atof(temp);
		}
		else {
			item = -1.0;
		}
		dataGGA.Longitude = item;
		kill = true;
	}

	//E_W
	char E_W;
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			E_W = data[i];
		}
		else {
			kill = false;
		}
	}
	dataGGA.E_W = E_W;
	kill = true;
	
	// position Fix indicator
	char Status;
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			Status = data[i];
		}
		else {
			kill = false;
		}
	}
	dataGGA.Fix = Status;
	kill = true;

	// Number of Satallites
	{
		char temp[2];
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				temp[t] = data[i];
				++t;
			}
			else {
				kill = false;
			}
		}
		float item;
		if (t > 0) {
			item = atof(temp);
		}
		else {
			item = -1.0;
		}
		dataGGA.Satellites = item;
		kill = true;
	}

	// HDOP
	{
		char temp[10];
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				temp[t] = data[i];
				++t;
			}
			else {
				kill = false;
			}
		}
		float item;
		if (t > 0) {
			item = atof(temp);
		}
		else {
			item = 0.0;
		}
		dataGGA.HDOP = item;
		kill = true;
	}

	// MSL Altitude
	{
		char temp[10];
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				temp[t] = data[i];
				++t;
			}
			else {
				kill = false;
			}
		}
		float item;
		if (t > 0) {
			item = atof(temp);
		}
		else {
			item = -1.0;
		}
		dataGGA.MSL = item;
		kill = true;
	}
	
	// AltUnit
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			dataGGA.AltUnit = data[i];
		}
		else {
			kill = false;
		}
	}
	kill = true;

	// Geoidal Separation
	{
		char temp[10];
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				temp[t] = data[i];
				++t;
			}
			else {
				kill = false;
			}
		}
		float item;
		if (t > 0) {
			item = atof(temp);
		}
		else {
			item = -1.0;
		}
		dataGGA.GeoSep = item;
		kill = true;
	}

	// Geoidal Separation Unit
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			dataGGA.GeoSepUnit = data[i];
		}
		else {
			kill = false;
		}
	}
	kill = true;

}

void GPSparser::clearGGA()
{
	dataGGA.name[0] = '\0';
	dataGGA.AltUnit = '\0';
	dataGGA.E_W = '\0';
	dataGGA.Fix = -1.0f;
	dataGGA.GeoSep = -1.0f;
	dataGGA.GeoSepUnit = '\0';
	dataGGA.HDOP = -1.0f;
	dataGGA.latitude = -1.0f;
	dataGGA.Longitude = -1.0f;
	dataGGA.MSL = -1.0f;
	dataGGA.N_S = '\0';
	dataGGA.Satellites = -1.0;
	dataGGA.UTC = -1.0f;
}

/* atof: convert string s to double */
double GPSparser::atof(char *s)
{
	double val, power;
	int i, sign;
	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}

	return sign * val / power;

}

void GPSparser::giveData(char * info, int length)
{ 
	if (info[3] == 'V' && info[4] == 'T' && info[5] == 'G') {
		StripVTG(info,length);
	}
	else if (info[3] == 'R' && info[4] == 'M' && info[5] == 'C') {
		StripRMC(info,length);
	}
	else if (info[3] == 'G' && info[4] == 'S' && info[5] == 'A') {
		StripGSA(info,length);
	}
	else if (info[3] == 'G' && info[4] == 'G' && info[5] == 'A') {
		StripGGA(info,length);
	}
	
}

void GPSparser::clearData()
{
		clearGGA();
		clearGSA();
		clearRMC();
		clearVTG();
}

char * GPSparser::getNames()
{
	
	int k = 0;
	if (dataGGA.name!='\0') {
		for (int i = 0; i < 6; ++i) {
			Names[k] = dataGGA.name[i];
			++k;
		}
		
		Names[k] = ',';
		++k;
		Names[k] = ' ';
		++k;
	}
	if (dataGSA.name != '\0') {
		for (int i = 0; i < 6; ++i) {
			Names[k] = dataGSA.name[i];
			++k;
		}
		
		Names[k] = ',';
		++k;
		Names[k] = ' ';
		++k;
	}
	if (dataRMC.name != '\0') {
		for (int i = 0; i < 6; ++i) {
			Names[k] = dataRMC.name[i];
			++k;
		}
		
		Names[k] = ',';
		++k;
		Names[k] = ' ';
		++k;
	}
	if (dataVTG.name != '\0') {
		for (int i = 0; i < 6; ++i) {
			Names[k] = dataVTG.name[i];
			++k;
		}
	}
	Names[k] = '\0';
	
	return Names;
		
}

//VTG data
float GPSparser::Tcourse()
{
		return dataVTG.Tcourse;
}

float GPSparser::Mcourse()
{
		return dataVTG.Mcourse;
}

float GPSparser::speedKnots()
{
		return dataVTG.speedKnots;
}

float GPSparser::speedKilometers()
{
	return dataVTG.speedKilometers;
}

//RMC data
float GPSparser::Latitude()
{
	if (dataRMC.latitude>-1.0f) {
		return dataRMC.latitude;
	}
	else if (dataGGA.latitude>-1.0f) {
		return dataGGA.latitude;
	}else{
		return -1.0f;
	}
}

float GPSparser::Longitude()
{
	if (dataRMC.longitude>-1.0f) {
		return dataRMC.longitude;
	}
	else if (dataGGA.Longitude>-1.0f) {
		return dataGGA.Longitude;
	}
	else {
		return -1.0f;
	}
}

float GPSparser::speed()
{
		return dataRMC.speed;
}

float GPSparser::course()
{
		return dataRMC.course;
}

char GPSparser::N_S_direction()
{
	if (dataRMC.N_S!='\0') {
		return dataRMC.N_S;
	}
	else if (dataGGA.N_S !='\0') {
		return dataGGA.N_S;
	}
	else {
		return '#';
	}
}

char GPSparser::E_W_direction()
{
	if (dataRMC.E_W != '\0') {
		return dataRMC.E_W;
	}
	else if (dataGGA.E_W != '\0') {
		return dataGGA.E_W;
	}
	else {
		return '#';
	}
}

// GSA data
char GPSparser::ModeOne()
{
	if (dataGSA.ModeOne != '\0')
		return dataGSA.ModeOne;
	else
		return '#';
}

char GPSparser::ModeTwo()
{
	if (dataGSA.ModeTwo != '\0')
		return dataGSA.ModeTwo;
	else
		return '#';
}

float * GPSparser::satIDs()
{

	float data[12];// = new float[12];
	if (dataGSA.satID[0] > -1.0f)
		for (int i = 0; i < 12;++i)
		data[i] = dataGSA.satID[i];
	
	return data;
}

float GPSparser::PDOP()
{
			return dataGSA.PDOP;
	
}

float GPSparser::HDOP()
{
	if (dataGSA.HDOP>-1.0f)
		return dataGSA.HDOP;
	else if (dataGGA.HDOP>-1.0f) {
		return dataGGA.HDOP;
	}else {
		return -1.0f;
	}
}

float GPSparser::VDOP()
{
	return dataGSA.VDOP;
	
}

//GGA data
float GPSparser::Satalllites()
{
	return dataGGA.Satellites;
}

float GPSparser::MSL()
{
	return dataGGA.MSL;
}

float GPSparser::Fix()
{
	return dataGGA.Fix;
}

float GPSparser::GeoSep()
{
	return dataGGA.GeoSep;
}

float GPSparser::UTC()
{
	if (dataRMC.UTC>-1.0f) {
		return dataRMC.UTC;
	}
	else if (dataGGA.UTC>-1.0f) {
		return dataGGA.UTC;
	}
	else { 
		return 0.0; 
	}

}

bool GPSparser::isdigit(char t)
{
	
	return t>='0' && t<='9';
}

bool GPSparser::isspace(char t)
{
	return !(t >= '0' && t <= '9');
}

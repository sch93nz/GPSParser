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
		
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				dataVTG.Tcourse[t] = data[i];
				++t;
			}
			else {
				dataVTG.Tcourse[t] = '\0';
				kill = false;
			}
		}
		
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
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				dataVTG.Mcourse[t] = data[i];
				++t;
			}
			else {
				dataVTG.Mcourse[t] = '\0';
				kill = false;
			}
		}
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
	
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				dataVTG.speedKnots[t] = data[i];
				++t;
			}
			else {
				dataVTG.speedKnots[t] = '\0';
				kill = false;
			}
		}
		
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
	
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				dataVTG.speedKilometers[t] = data[i];
				++t;
			}
			else {
				dataVTG.speedKilometers[t] = '\0';
				kill = false;
			}
		}

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
	dataVTG.Mcourse[0] = '\0';
	dataVTG.speedKilometers[0] = '\0';
	dataVTG.speedKnots[0] = '\0';
	dataVTG.Tcourse[0] = '\0';

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
		
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				dataRMC.UTC[t] = data[i];
				++t;
			}
			else {
				dataRMC.UTC[t] = '\0';
				kill = false;
			}
		}
		
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
		
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				dataRMC.latitude[t] = data[i];
				++t;
			}
			else {
				dataRMC.latitude[t] = '\0';
				kill = false;
			}
		}
		
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
		
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				dataRMC.longitude[t] = data[i];
				++t;
			}
			else {
				dataRMC.longitude[t] = '\0';
				kill = false;
			}
		}
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
		
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				dataRMC.speed[t] = data[i];
				++t;
			}
			else {
				dataRMC.speed[t] = '\0';
				kill = false;
			}
		}
		
		kill = true;
	}

	//course
	{
		
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				dataRMC.course[t] = data[i];
				++t;
			}
			else {
				dataRMC.course[t] = '\0';
				kill = false;
			}
		}
		
		kill = true;
	}


}

void GPSparser::clearRMC()
{
	dataRMC.name[0] = '\0';
	dataRMC.course[0] = '\0';
	dataRMC.E_W = '\0';
	dataRMC.latitude[0] = '\0';
	dataRMC.longitude[0] = '\0';
	dataRMC.N_S = '\0';
	dataRMC.speed[0] = '\0';
	dataRMC.Status = '\0';
	dataRMC.UTC[0] = '\0';
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
	
	int t = 0;
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			dataGSA.PDOP[t] = data[i];
			++t;
		}
		else {
			dataGSA.PDOP[t] = '\0';
			kill = false;
		}
	}
	
	kill = true;
}
	
	// HDOP
	{
	
	int t = 0;
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			dataGSA.HDOP[t] = data[i];
			++t;
		}
		else {
			dataGSA.HDOP[t] = '\0';
			kill = false;
		}
	}
	
	kill = true;
}
	
	// VDOP
	{
	
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',' && data[i] != '*') {
				dataGSA.VDOP[t] = data[i];
				++t;
			}
			else {
				dataGSA.VDOP[t] = '\0';
				kill = false;
			}
		}
		
		kill = true;
	}

}

void GPSparser::clearGSA()
{
	dataGSA.name[0] = '\0';
	dataGSA.HDOP[0] = '\0';
	dataGSA.ModeOne = '\0';
	dataGSA.ModeTwo = '\0';
	dataGSA.PDOP[0] = '\0';
	for (int i = 0; i < 12; ++i) {
		dataGSA.satID[i] = -1.0f;
	}
	dataGSA.VDOP[0] = '\0';
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
		
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				dataGGA.UTC[t] = data[i];
				++t;
			}
			else {
				dataGGA.UTC[t] = '\0';
				kill = false;
			}
		}
	
		kill = true;
	}

	//Latitude
	{
		
		
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				dataGGA.latitude[t] = data[i];
				++t;
			}
			else {
				dataGGA.latitude[t] = '\0';
				kill = false;
			}
		}
		
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
	
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				dataGGA.longitude[t] = data[i];
				++t;
			}
			else {
				dataGGA.longitude[t] = '\0';
				kill = false;
			}
		}
		
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
		
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				dataGGA.Satellites[t] = data[i];
				++t;
			}
			else {
				dataGGA.Satellites[t] = '\0';
				kill = false;
			}
		}
		
		kill = true;
	}

	// HDOP
	{
		
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				dataGGA.HDOP[t] = data[i];
				++t;
			}
			else {
				dataGGA.HDOP[t] = '\0';
				kill = false;
			}
		}
	
		kill = true;
	}

	// MSL Altitude
	{
		
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				dataGGA.MSL[t] = data[i];
				++t;
			}
			else {
				dataGGA.MSL[t] = '\0';
				kill = false;
			}
		}
		
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
	
		int t = 0;
		for (; i <= length && kill; ++i) {
			if (data[i] != ',') {
				dataGGA.GeoSep[t] = data[i];
				++t;
			}
			else {
				dataGGA.GeoSep[t] = '\0';
				kill = false;
			}
		}
		
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
	dataGGA.GeoSep[0] = '\0';
	dataGGA.GeoSepUnit = '\0';
	dataGGA.HDOP[0] = '\0';
	dataGGA.latitude[0] = '\0';
	dataGGA.longitude[0] = '\0';
	dataGGA.MSL[0] = '\0';
	dataGGA.N_S = '\0';
	dataGGA.Satellites[0] = '\0';
	dataGGA.UTC[0] = '\0';
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
char * GPSparser::Tcourse()
{
		return dataVTG.Tcourse;
}

char * GPSparser::Mcourse()
{
		return dataVTG.Mcourse;
}

char * GPSparser::speedKnots()
{
		return dataVTG.speedKnots;
}

char * GPSparser::speedKilometers()
{
	return dataVTG.speedKilometers;
}

char * GPSparser::printVTG()
{
	int k = 0;
	printout[k] = 'n'; ++k;
	printout[k] = 'a'; ++k;
	printout[k] = 'm'; ++k;
	printout[k] = 'e'; ++k;
	printout[k] = ' '; ++k;
	for (int i = 0; i < 6; ++i) {
		printout[k]= dataVTG.name[i];
		++k;
	}
	printout[k] = '\n'; ++k;
	printout[k] = 'T'; ++k;
	printout[k] = 'c'; ++k;
	printout[k] = 'o'; ++k;
	printout[k] = 'u'; ++k;
	printout[k] = 'r'; ++k;
	printout[k] = 's'; ++k;
	printout[k] = 'e'; ++k;
	printout[k] = ' '; ++k;
	for (int i = 0; i < 6; ++i) {
		printout[k] = dataVTG.Tcourse[i];
		++k;
	}
	printout[k] = '\n'; ++k;
	printout[k] = 'M'; ++k;
	printout[k] = 'c'; ++k;
	printout[k] = 'o'; ++k;
	printout[k] = 'u'; ++k;
	printout[k] = 'r'; ++k;
	printout[k] = 's'; ++k;
	printout[k] = 'e'; ++k;
	printout[k] = ' '; ++k;
	for (int i = 0; i < 6; ++i) {
		printout[k] = dataVTG.Mcourse[i];
		++k;
	}
	printout[k] = '\n'; ++k;
	printout[k] = 'K'; ++k;
	printout[k] = 'n'; ++k;
	printout[k] = 'o'; ++k;
	printout[k] = 't'; ++k;
	printout[k] = 's'; ++k;
	printout[k] = ' '; ++k;
	for (int i = 0; i < 4; ++i) {
		printout[k] = dataVTG.speedKnots[i];
		++k;
	}
	printout[k] = '\n'; ++k;
	printout[k] = 'K'; ++k;
	printout[k] = 'm '; ++k;
	printout[k] = '/'; ++k;
	printout[k] = 's'; ++k;
	printout[k] = ' '; ++k;
	for (int i = 0; i < 4; ++i) {
		printout[k] = dataVTG.speedKilometers[i];
		++k;
	}
	printout[k] = '\0';
	return printout;
}

//RMC data
char * GPSparser::Latitude()
{
	if (dataRMC.latitude[0]!='\0') {
		return dataRMC.latitude;
	}
	else {
		return dataGGA.latitude;
	}
}

char * GPSparser::Longitude()
{
	if (dataRMC.longitude[0]!='\0') {
		return dataRMC.longitude;
	}
	else {
		return dataGGA.longitude;
	}
	
}

char * GPSparser::speed()
{
		return dataRMC.speed;
}

char * GPSparser::course()
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

char * GPSparser::PDOP()
{
			return dataGSA.PDOP;
	
}

char * GPSparser::HDOP()
{
	if (dataGSA.HDOP[0] != '\0')
		return dataGSA.HDOP;
	else {
		return dataGGA.HDOP;
	}
}

char * GPSparser::VDOP()
{
	return dataGSA.VDOP;
	
}

//GGA data
char * GPSparser::Satalllites()
{
	return dataGGA.Satellites;
}

char * GPSparser::MSL()
{
	return dataGGA.MSL;
}

char GPSparser::Fix()
{
	return dataGGA.Fix;
}

char * GPSparser::GeoSep()
{
	return dataGGA.GeoSep;
}

char * GPSparser::UTC()
{
	if (dataRMC.UTC[0] != '\0') {
		return dataRMC.UTC;
	}
	else {
		return dataGGA.UTC;
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

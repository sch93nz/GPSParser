#include "GPSparser.h"


void GPSparser::StripVTG(char * data, int length)
{
	int i = 0;
	bool kill = true;
	char name[6];
	char  ref;
	dataVTG = new VTG;

	// Name
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			name[i] = data[i];
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
			item = charTofloat(temp);
		}
		else {
			item = -1.0;
		}
		dataVTG->Tcourse = item;
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
			item = charTofloat(temp);
		}
		else {
			item = -1.0;
		}
		dataVTG->Mcourse = item;
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
			item = charTofloat(temp);
		}
		else {
			item = -1.0;
		}
		dataVTG->speedKnots = item;
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
			item = charTofloat(temp);
		}
		else {
			item = -1.0;
		}
		dataVTG->speedKilometers = item;
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

void GPSparser::StripRMC(char * data, int length)
{
	int i = 0;
	bool kill = true;
	char name[6];
	char Status, N_S, E_W;
	
	dataRMC = new RMC;
	// Name
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			name[i] = data[i];
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
			item = charTofloat(temp);
		}
		else {
			item = -1.0;
		}
		dataRMC->UTC = item;
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
	dataRMC->Status = Status;
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
			item = charTofloat(temp);
		}
		else {
			item = -1.0;
		}
		dataRMC->latitude = item;
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
	dataRMC->N_S = N_S;
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
			item = charTofloat(temp);
		}
		else {
			item = -1.0;
		}
		dataRMC->longitude = item;
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
	dataRMC->E_W = E_W;
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
			item = charTofloat(temp);
		}
		else {
			item = -1.0;
		}
		dataRMC->speed = item;
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
			item = charTofloat(temp);
		}
		else {
			item = -1.0;
		}
		dataRMC->course = item;
		kill = true;
	}


}

void GPSparser::StripGSA(char * data, int length)
{
	int i = 0;
	bool kill = true;
	char name[6];
	dataGSA = new GSA;
	char modeOne, ModeTwo;
	
	
	// Name
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			name[i] = data[i];
		}
		else {
			kill = false;
		}
	}
	kill = true;

	// Mode 1
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			modeOne = data[i];
		}
		else {
			kill = false;
		}
	}
	dataGSA->ModeOne = modeOne;
	kill = true;

	// Mode 2
	for (; i <= length && kill; ++i) {
		if (data[i] != ',') {
			ModeTwo = data[i];
		}
		else {
			kill = false;
		}
	}
	dataGSA->ModeTwo = ModeTwo;
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
			item = charTofloat(temp);
		}
		else {
			item = -1.0;
		}
		dataGSA->satID[k] = item;
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
		item = charTofloat(temp);
	}
	else {
		item = -1.0;
	}
	dataGSA->PDOP = item;
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
		item = charTofloat(temp);
	}
	else {
		item = -1.0;
	}
	dataGSA->HDOP = item;
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
			item = charTofloat(temp);
		}
		else {
			item = -1.0;
		}
		dataGSA->VDOP = item;
		kill = true;
	}

}

float GPSparser::charTofloat(char * data)
{
	return 0.0f;
}

void GPSparser::giveData(char * info, int length)
{
	if (info[3] == 'V') {
		StripVTG(info,length);
	}
	else if (info[3] == 'R') {
		StripRMC(info,length);
	}
	else if (info[3] == 'G') {
		StripGSA(info,length);
	}
	
}

void GPSparser::clearData()
{
	dataGSA = nullptr;
	dataRMC = nullptr;
	dataVTG = nullptr;
}

//VTG data

float GPSparser::Tcourse()
{
	return 0.0f;
}

float GPSparser::Mcourse()
{
	return 0.0f;
}

float GPSparser::speedKnots()
{
	return 0.0f;
}

float GPSparser::speedKilometers()
{
	return 0.0f;
}

//RMC data

float GPSparser::Latitude()
{
	if (dataRMC != nullptr) {
		return dataRMC->latitude;
	}
	else {
		return -1.0f;
	}
}

float GPSparser::Longitude()
{
	if (dataRMC != nullptr) {
		return dataRMC->longitude;
	}
	else {
		return -1.0f;
	}
}

float GPSparser::speed()
{
	if (dataRMC != nullptr) {
		return dataRMC->speed;
	}
	else {
		return -1.0f;
	}
}

float GPSparser::course()
{
	if (dataRMC != nullptr) {
		return dataRMC->course;
	}
	else {
		return -1.0f;
	}
}

char GPSparser::N_S_direction()
{
	if (dataRMC != nullptr) {
		return dataRMC->N_S;
	}
	else {
		return -1;
	}
}

char GPSparser::E_W_direction()
{
	if (dataRMC != nullptr) {
		return dataRMC->E_W;
	}
	else {
		return -1;
	}
}

// GSA data

char GPSparser::ModeOne()
{
	if (dataGSA != nullptr)
		return dataGSA->ModeOne;
	else
		return -1;
}

char GPSparser::ModeTwo()
{
	if (dataGSA != nullptr)
		return dataGSA->ModeTwo;
	else
		return -1;
}

float * GPSparser::satIDs()
{

	float* data = new float[12];
	if (dataGSA != nullptr)
		data = dataGSA->satID;
	
	return data;
}

float GPSparser::PDOP()
{
	if (dataGSA != nullptr)
		return dataGSA->PDOP;
	else
		return -1.0;
}

float GPSparser::HDOP()
{
	if (dataGSA != nullptr)
		return dataGSA->HDOP;
	else
		return -1.0;
}

float GPSparser::VDOP()
{
	if (dataGSA != nullptr)
		return dataGSA->VDOP;
	else
		return -1.0;
}

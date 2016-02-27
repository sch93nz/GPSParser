#include "GPSparser.h"


GPSparser test;

int main(int argc, char **argv) {

	char testOne[] = "$GPGSA,A,3,26,05,18,27,29,,,,,,,,1.52,1.25,0.87*0F";
	char testTwo[] = "$GPRMC,023345.000,A,2232.1767,N,11401.1953,E,0.18,151.55,100410,,,";
	char testThree[] = "$GPVTG,148.81,T,,M,0.13,N,0.24,K,A*3D";

	test.giveData(testOne, 50);
	test.giveData(testTwo, 66);
	test.giveData(testThree, 37);


}
#include "GPSparser.h"
#include <stdio.h>

int inputTOdegrees(int d);
int midpoint(int imin, int imax);
int binary_search(int A[], int key, int xmin, int xmax);
bool equal(int value, int key);

GPSparser test;

using namespace std;

int main(int argc, char **argv) {

	char testOne[] = "$GPGSA,A,3,26,05,18,27,29,,,,,,,,1.52,1.25,0.87*0F";
	char testTwo[] = "$GPRMC,023345.000,A,2232.1767,N,11401.1953,E,0.18,151.55,100410,,,";
	char testThree[] = "$GPVTG,148.81,T,,M,0.13,N,0.24,K,A*3D";
	char testfour[] = "$GPGGA,033410.000,2232.1745,N,11401.1920,E,1,07,1.1,107.14,M,0.00,M,,";

	test.giveData(testOne, 50);
	test.giveData(testTwo, 66);
	test.giveData(testThree, 37);
	test.giveData(testfour, 69);
	printf(test.getNames());


	int d = inputTOdegrees(419);
	d = inputTOdegrees(418);
	d = inputTOdegrees(368);
	d = inputTOdegrees(524);
	int input[] = { 662,661,660,657,654,652.8,651.6,650.4,649.2,648,646.8,645.6,644.4,643.2,642,640.6,
		639.2,637.8,636.4,635,633.6,632.2,630.8,629.4,628,626.2,624.4,622.6,620.8,619,617.2,615.4,
		613.6,611.8,610,607.9,605.8,603.7,601.6,599.5,597.4,595.3,593.2,591.1,589,586.4,583.8,581.2,
		578.6,576,573.4,570.8,568.2,565.6,563,560.4,557.8,555.2,552.6,550,547.4,544.8,542.2,539.6,537,
		534.3,531.6,528.9,526.2,523.5,520.8,518.1,515.4,512.7,510,507.5,505,502.5,500,497.5,495,492.5,490,
		487.5,485,482,479,476,473,470,467,464,461,458,455,452.8,450.6,448.4,446.2,444,441.8,439.6,437.4,
		435.2,433,430.5,428,425.5,423,420.5,418,415.5,413,410.5,408,406.2,404.4,402.6,400.8,399,397.2,
		395.4,393.6,391.8,390,388.4,386.8,385.2,383.6,382,380.4,378.8,377.2,375.6,374,372.9,371.8,
		370.7,369.6,368.5,367.4,366.3,365.2,364.1,363,360,357,356,355 };
	for(int k : input) {
		d = inputTOdegrees(k);
		printf("deg= %d \t input= %d \n",d,k);
	}

	d = 10;
}


int inputTOdegrees(int d) {
	int degrees[] = { -90,-85,-80,-75,-70,-69,-68,-67,-66,-65,-64,-63,-62,-61,-60,-59,-58,
		-57,-56,-55,-54,-53,-52,-51,-50,-49,-48,-47,-46,-45,-44,-43,-42,-41,-40,-39,-38,-37,
		-36,-35,-34,-33,-32,-31,-30,-29,-28,-27,-26,-25,-24,-23,-22,-21,-20,-19,-18,-17,-16,
		-15,-14,-13,-12,-11,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,
		15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,
		44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,75,80,85,90 };

	int input[] = { 662,661,660,657,654,652.8,651.6,650.4,649.2,648,646.8,645.6,644.4,643.2,642,640.6,
		639.2,637.8,636.4,635,633.6,632.2,630.8,629.4,628,626.2,624.4,622.6,620.8,619,617.2,615.4,
		613.6,611.8,610,607.9,605.8,603.7,601.6,599.5,597.4,595.3,593.2,591.1,589,586.4,583.8,581.2,
		578.6,576,573.4,570.8,568.2,565.6,563,560.4,557.8,555.2,552.6,550,547.4,544.8,542.2,539.6,537,
		534.3,531.6,528.9,526.2,523.5,520.8,518.1,515.4,512.7,510,507.5,505,502.5,500,497.5,495,492.5,490,
		487.5,485,482,479,476,473,470,467,464,461,458,455,452.8,450.6,448.4,446.2,444,441.8,439.6,437.4,
		435.2,433,430.5,428,425.5,423,420.5,418,415.5,413,410.5,408,406.2,404.4,402.6,400.8,399,397.2,
		395.4,393.6,391.8,390,388.4,386.8,385.2,383.6,382,380.4,378.8,377.2,375.6,374,372.9,371.8,
		370.7,369.6,368.5,367.4,366.3,365.2,364.1,363,360,357,356,355 };

	const int length = 149;

	int index = binary_search(input, d, 0, 149);
	// Serial.println(index);
	return degrees[index];
}

int midpoint(int imin, int imax)
{
	return imin + ((imax - imin) / 2);
}

int binary_search(int A[], int key, int xmin, int xmax)
{

	int imin = xmin;
	int imax = xmax;
	// continue searching while [imin,imax] is not empty
	while (imin <= imax)
	{
		// calculate the midpoint for roughly equal partition
		int imid = midpoint(imin, imax);
		if (equal(A[imid], key))
			// key found at index imid
			return imid;
		// determine which subarray to search
		else if (A[imid] < key)
			// change max index to search lower subarray
			imax = imid - 1;
		else
			// change min index to search upper subarray
			imin = imid + 1;
			
	}
	// Serial.println("key " +String(key));
	// Serial.println("imin " +String(imin));

	if (xmin == imin) return imin;
	if (imax == xmax) return imax;

	// key was not found
	return -1;
}

bool equal(int value, int key)
{
	float v = value;
	float k = key;
	return (k <= (v + 1.5) && k >= (v - 1.5));
}

#include "stdio.h"
#include "math.h"
#include <stdbool.h>

bool sampledata[128] = { 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0 };

typedef struct framearr_s {
	char preamble[16];
	char downformat[5];
	char transpondercap[3];
	char address[24];
	char type[5];
	char message[56];
	char parity[24];
}framearr;

framearr dataDecompose(char datain[128]);
void convertPos(bool datain[128]);

int main(){
	bool datain[112];
	for (int i = 16; i < 128; i++) { // remove preamble
		datain[i - 16] = sampledata[i];
	}
	
	convertPos(datain);
	return(0);
}


void convertPos(bool datain[128]) {
	int lat_bin = 0;
	for (int i = 54; i < 71; i++) { //latitude 
		lat_bin = (lat_bin << 1) + datain[i];
		//printf("%d", (int)datain[i]);
	}
	//printf("\n%d\n\n", lat_bin);
	int lon_bin = 0;
	for (int i = 71; i < 88; i++) { //longitude
		lon_bin = (lon_bin << 1) + datain[i];
		//printf("%d", (int)datain[i]);
	}
	//printf("\n%d", lon_bin);
	float lat, lon;
	lat = 6 * (8 + (lat_bin / pow(2, 17)));
	lon = 10 * (0 + (lon_bin / pow(2, 17)));
	printf("\nLatitude:%f",lat);
	printf("\nLongitude:%f", lon);
}

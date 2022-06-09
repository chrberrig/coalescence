#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "coales.h"

int main(int argc, char **argv){ 

	FILE *fp = stdout;
 
	
	int option;
	while((option = getopt(argc, argv, "o:p:i:r:b:n:t:m")) != -1){ //get option from the getopt() method
		switch(option){

			case 'o': // Sets population size
				fp = fopen(optarg, "w");
				break;

			case 'N': // Sets population size
				pop = atoi(optarg);
				break;

			case 'g': // Sets recovery rate
				g_end = atof(optarg);
				break;

			case ':': // check for opt arg if required
				printf("option -%c needs a value\n", optopt);
				// printf("option needs a value\n");
				break;

			case '?': // used for some unknown options
				printf("unknown option: %c\n", optopt);
				break;
		}
	}
	
	
	struct Agent pop_state[N];

	fclose(fp);
	return 0;
}

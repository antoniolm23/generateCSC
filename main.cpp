#include <iostream>
#include <ctype.h>
#include <unistd.h>
#include "generateCSC.h"

/*@Antonio:
 * The aim of this program is to generate a new .csc file
 * according to some parameters that we give to the main.
 * Possible parameters are:
 * 1) -a: Number of total advertising nodes (default 100)
 * 2) -s: Square side (default 300)
 * 3) -p: Eventual ploss
 * 4) -r: radius
 */

using namespace std;

#define SEED_STOP 4294967295
#define DEFAULT_ADV 100
#define DEFAULT_SQUARE_SIDE 300
#define DEFAULT_PLOSS 0
#define DEFAULT_RADIUS 100
int main(int argc, char **argv) {
	
	//Assignements
	int advNodes = DEFAULT_ADV;
	int squareSide = DEFAULT_SQUARE_SIDE;
	double ploss = DEFAULT_PLOSS;
	double radius = DEFAULT_RADIUS;
	
	//BEGIN Parsing of arguments
	char c;
	while ((c = getopt(argc, argv, "a:s:p:r:")) != -1)
	{
		switch(c)
		{
			case 'a':
				advNodes = atoi(optarg);
				break;
			case 's':
				squareSide = atoi(optarg);
				break;
			case 'p':
				ploss = atof(optarg);
				break;
			case 'r':
				radius = atof(optarg);
				break;
			case '?':
				cout<<"Unsupported argument\n";
				break;
		}
	}
	//END parsing
	
	cout<<"parsing ended"<<endl;
	
	generateCSC gcsc = generateCSC(advNodes, squareSide, ploss, radius);
	gcsc.cscInit();
	
}

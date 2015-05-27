#include <iostream>
#include <ctype.h>
#include <unistd.h>
#include "generateCSC.h"

/**
 * @author: Antonio:
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

/**
 * Print an help showing all the possible commands available for the user to generate
 * a correct csc file
 */
void printHelp() 
{
	cout << "Available comands are\n\t" \
		"-a: number of advertising motes (coordinator excluded)\n\t" \
		"-s: size of the square side \n\t" \
		"-p: possible ploss\n\t" \
		"-r: transmitting range\n\t" \
		"-h: privides this help\n";
}

int main(int argc, char **argv) 
{
	
	//Assignements to default values
	int advNodes = DEFAULT_ADV;
	int squareSide = DEFAULT_SQUARE_SIDE;
	double ploss = DEFAULT_PLOSS;
	double radius = DEFAULT_RADIUS;
	
	//BEGIN Parsing of arguments
	char c;
	while ((c = getopt(argc, argv, "a:s:p:r:h")) != -1)
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
			case 'h':
				printHelp();
				return 0;
			case '?':
				cout<<"Unsupported argument\n";
				break;
		}
	}
	//END parsing
	
	generateCSC gcsc = generateCSC(advNodes, squareSide, ploss, radius);
	bool acceptedCSC = false;
	
	/**
	 * Until a correctly generated csc file is not generated
	 * continue generating the file
	 */
	while (!acceptedCSC)
	{
		acceptedCSC = gcsc.cscWrite();
		
		/**
		 * If the generatedCSC is wrong, delete it
		 * NOTE: it is possible to write this part of code
		 * at the top, right before the gcsc.cscWrite, but 
		 * behaving in this way would lead to a deletion of 
		 * a file that hasn't been generated yet, to avoid this, 
		 * the deletion is done here.
		 */
		if(acceptedCSC == false)
		{
			remove( "advertising.csc" );
		}
	}
	
	
}

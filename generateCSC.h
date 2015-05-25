#include <iostream>
#include <fstream>
#include "Random.h"
#include "advertiserList.h"
#include <string>
#include <sstream>

using namespace std;

class generateCSC
{
	double ploss;
	int advNodes;
	int squareSide;
	Random r;
	advertiserList advertiserPositions;
	
	//Generates nodes and positions
	void genAdvMotes(int );
	void  genListenerMote(int);
	void genCoordinatorMote(int);
	
	string xmlAdvMotes();
	string xmlListenerMote();
	string xmlCoordinatorMote();
public:
	/*
	 * Constructor of the class genCSC
	 * @param: int advNodes, int squareSidem double ploss double radius 
	 * NOTE: ploss is due to the wireless medium not to collisions
	 */
	generateCSC(int, int, double, double);
	void cscInit();
};
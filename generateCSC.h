#include <iostream>
#include <fstream>
#include "Random.h"
#include "motes.h"
#include <string>
#include <sstream>

using namespace std;

/**
 * Class used to generate the csc file,
 * parsed by cooja to deploy nodes in an
 * area with fixed positions and 
 * other characteristics
 */
class generateCSC
{
	double ploss;
	int advNodes;
	int squareSide;
	Random random;
	motes motePositions;
	
	//Generates nodes and positions
	void genAdvMotes(int);
	void  genListenerMote(int);
	void genCoordinatorMote(int);
	
	string xmlAdvMotes(int, position);
	string xmlListenerMote(int, position);
	string xmlCoordinatorMote(int, position);
public:
	
	/*
	 * Constructor of the class genCSC
	 * @param: int advNodes, int squareSidem double ploss double radius 
	 * NOTE: ploss is due to the wireless medium not to collisions
	 */
	generateCSC(int, int, double, double);
	
	//effective write on the csc file (by default "advertising.csc")
	bool cscWrite();
};
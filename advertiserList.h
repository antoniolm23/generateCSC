#include <iostream>
#include <list>
#include <math.h>

#define COORDINATOR 1
#define ADVERTISER 2
#define LISTENER 0

using namespace std;

struct position
{
	int x;
	int y;
	int type;
};

class advertiserList
{
	list<position> positions;
	double radius;
	position listener;
	
	bool computeDistance(position, position);
public:
	void init();
	void setRadius(double r) {radius = r;}
	//position and id of the node
	int retrieveColliders(position, int);
	void setListener(position);
	bool search(position);
	bool add(position);
};
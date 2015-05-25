#include "advertiserList.h"

void advertiserList::init()
{
	positions = list<position>();
}

/*
 * Given 2 positions compute the distance between them
 */
bool advertiserList::computeDistance(position p1, position p2)
{
	double distance = sqrt((p2.x - p1.x) * (p2.x - p1.x) + 
	(p2.y - p1.y) * (p2.y - p1.y) );
	//cout<<distance<<'\n';
	if(distance < radius)
		return false;
	else
		return true;
}


/*
 * Retrieve the number of colliding nodes in order to let
 * the advertiser know which is the transmitting probability
 */
int advertiserList::retrieveColliders(position p)
{
	int colliders = 0;
	
	//compare each element in the list with the position of the listener
	for(list<position>::iterator it = positions.begin(); it != positions.end(); ++it)
	{
		if(computeDistance(*it, p) == false)
		{
			colliders++;
		}
	}
	return colliders;
}

/*
 * Function that adds a new advertiser in position p
 */
bool advertiserList::add(position p)
{
	if(!search(p)) 
	{
		positions.push_back(p);
		return true;
	}
	else
		return false;
}

/*
 * Search if the generated position is already occupied
 */
bool advertiserList::search(position p) 
{
	for(list<position>::iterator it = positions.begin(); it != positions.end(); ++it) 
	{
		if(it->x == p.x && it->y == p.y)
			return true;
	}
	return false;
}

/*
 * Set the listener position
 */
void advertiserList::setListener(position p)
{
	listener.x = p.x;
	listener.y = p.y;
}

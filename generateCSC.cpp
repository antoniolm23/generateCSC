#include "generateCSC.h"

/**
 * Constructor of the class
 * @param: a is the number of advertising motes, 
 *         s is the square side dimension
 *         p is the eventual ploss
 *         ra is the radius of the transmitting range circle
 */
generateCSC::generateCSC(int a, int s, double p, double ra)
{
	advNodes = a;
	squareSide = s;
	ploss = p;
	motePositions.init();
	motePositions.setRadius(ra);
	random.init();
}

/**
 * Convert an integer to string
 * @param: t is the integer to convert
 * @return: the resultant string 
 */
string convertInt(int t)
{
	stringstream convert;	//needed to convert double to string
	string tmpString;
	convert << t;
	tmpString = convert.str();
	return tmpString;
}

/**
 * Generates the coordinator of the network
 * and adds it to the group of motes
 * @param: id of the node
 */
void generateCSC::genCoordinatorMote(int id) 
{
	position p;
	bool acceptable = false;
	
	//check if the position is acceptable
	while(!acceptable) 
	{
		//compute the position in the square
		int x = random.getNumber(squareSide);
		int y = random.getNumber(squareSide);
		
		/*
		* add the position in order to futher state the number of 
		* colliding nodes further state if position are correct, otherwise generate 
		* new position
		*/ 
		p.x = x;
		p.y = y;
		p.id = id;
		p.type = COORDINATOR;
		acceptable = motePositions.add(p);
	}

}

/**
 * Generate an advertising mote position and adds it to 
 * the group of motes
 * @param: the id of the node 
 */
void generateCSC::genAdvMotes(int id)
{
	position p;
	bool acceptable = false;
	
	while(!acceptable) 
	{
		//compute the position in the square
		int x = random.getNumber(squareSide);
		int y = random.getNumber(squareSide);
		
		/*
		* add the position in order to futher state the number of 
		* colliding nodes further state if position are correct, otherwise generate 
		* new position
		*/ 
		p.x = x;
		p.y = y;
		p.id = id;
		p.type = ADVERTISER;
		acceptable = motePositions.add(p);
	}
}

/**
 * Generate a new listener mote, 
 * this node position has to be at least in the area of another node and has to 
 * be in different position w.r.t. other nodes.
 * If everything is fine adds the mote to the group of motes
 * @param: id of the node
 */
void generateCSC::genListenerMote(int id)
{
	position p;
	bool acceptable = false;
	
	while(!acceptable) 
	{
		//compute the position in the square
		int x = random.getNumber(squareSide);
		int y = random.getNumber(squareSide);
		
		/*
		* add the position in order to further state the number of 
		* colliding nodes if position are correct, otherwise generate 
		* new position
		*/ 
		p.x = x;
		p.y = y;
		p.id = id;
		p.type = LISTENER;
		acceptable = motePositions.setListener(p);
	}
}

/**
 * creates the xml for an advertising mote, basing on its characteristics
 * @param: node id and node position
 * @return: the xml string that will be then written to a file
 */
string generateCSC::xmlAdvMotes(int id, position p)
{
	//header
	string xml = "\t\t<mote>\n\t\t\t<breakpoints />\n\t\t\t";
	xml +="<interface_config>\n\t\t\t\tse.sics.cooja.interfaces.Position";
	
	//retrieve the number of colliding nodes from this node position
	int colliders = motePositions.retrieveColliders(p);
	
	//check if colliders number exceeds the maximum value
	if(colliders == -1)
		return "";
	
	//positon
	xml += "\n\t\t\t\t<x>" + convertInt(p.x) + "</x>";
	xml += "\n\t\t\t\t<y>" + convertInt(p.y) + "</y>";
	xml += "\n\t\t\t\t<z>0.0</z>\n\t\t\t</interface_config>";
	
	//footer
	xml += "\n\t\t\t<interface_config>\n\t\t\t\tse.sics.cooja.mspmote.interfaces.MspMoteID";
	xml += "\n\t\t\t\t<id>" + convertInt(id) + "</id>\n\t\t\t</interface_config>";
	xml += "\n\t\t\t<motetype_identifier>sky" + convertInt(colliders + MAXCOLLIDERS) + \
	"</motetype_identifier>";
	xml += "\n\t\t</mote>\n";
	
	return xml;
}

/**
 * creates the xml for a listener node, sky15 is the identifier 
 * for a listener node
 * @param: node id and node position
 * @return: the xml string
 */
string generateCSC::xmlListenerMote(int id, position p)
{
	//header
	string xml = "\t\t<mote>\n\t\t\t<breakpoints />\n\t\t\t"; 
	xml += "<interface_config>\n\t\t\t\tse.sics.cooja.interfaces.Position";
	
	//position
	xml += "\n\t\t\t\t<x>" + convertInt(p.x) + "</x>";
	xml += "\n\t\t\t\t<y>" + convertInt(p.y) + "</y>";
	xml += "\n\t\t\t\t<z>0.0</z>\n\t\t\t</interface_config>";
	
	//footer
	xml += "\n\t\t\t<interface_config>\n\t\t\t\tse.sics.cooja.mspmote.interfaces.MspMoteID";
	xml += "\n\t\t\t\t<id>" + convertInt(id) + "</id>\n\t\t\t</interface_config>";
	xml += "\n\t\t\t<motetype_identifier>sky15</motetype_identifier>";
	xml += "\n\t\t</mote>\n";
	
	//cout<<xml<<endl;
	
	return xml;
}

/**
 * creates the xml for a coordinator node, the identifier of 
 * this type of node depends upon the number of colliding nodes
 * @params: node id and node position
 * @return: the xml string
 */
string generateCSC::xmlCoordinatorMote(int id, position p)
{
	//header
	string xml = "\t\t<mote>\n\t\t\t<breakpoints />\n\t\t\t";
	xml +="<interface_config>\n\t\t\t\tse.sics.cooja.interfaces.Position";
	
	//position
	xml += "\n\t\t\t\t<x>" + convertInt(p.x) + "</x>";
	xml += "\n\t\t\t\t<y>" + convertInt(p.y) + "</y>";
	
	int colliders = motePositions.retrieveColliders(p);
	
	//check if colliders number exceeds the maximum value
	if(colliders == -1)
		return "";
	
	//footer
	xml += "\n\t\t\t\t<z>0.0</z>\n\t\t\t</interface_config>";
	xml += "\n\t\t\t<interface_config>\n\t\t\t\tse.sics.cooja.mspmote.interfaces.MspMoteID";
	xml += "\n\t\t\t\t<id>" + convertInt(id) + "</id>\n\t\t\t</interface_config>";
	xml += "\n\t\t\t<motetype_identifier>sky" + \
	convertInt(colliders) + "</motetype_identifier>";
	xml += "\n\t\t</mote>\n";
	
	return xml;
}


/**
 * This is the function in charge of generating the csc file:
 * provided a schema that is the header of the csc file, 
 * this functions generates the number of needed motes in the 
 * area stated by the user
 * @return: true if it was possible to generate the csc file, false otherwise
 */
bool generateCSC::cscWrite()
{
	
	string line;
	
	//provided an example file
	ifstream schema;
	schema.open("schema.csc");
	ofstream cscFile;
	cscFile.open("advertising.csc", ios::app);
	int i = 1;
	cout<<"doing copy"<<endl;
	
	//1 step: copy the content of schema.csc in advertising.csc
	while( getline(schema, line) )
	{
		//add the newline character since it is discarded by the getline
		cscFile << line << '\n';
	}
	
	//close the schema file
	schema.close();
	
	cout<<"generating motes position"<<endl;
	string xml;
	
	//BEGIN position generation
	//int i = 1;
	//geenerate coordinator
	genCoordinatorMote(i); 
	
	//generate advertisers
	for( i = 2; i <= advNodes + 1; i++ )
		genAdvMotes(i);
	
	//generate listener
	genListenerMote(i);
	
	//END position generation
	
	
	/**
	 * After generating nodes' position it's time to 
	 * generate the xml description for each mote, this 
	 * description highly depends upon the number of colliding
	 * nodes in the neighborhood 
	 */
	
	//BEGIN xml generation
	
	cout << "generate xml" << endl;
	//keep into account coordinator too 
	int nodes = advNodes + 1; 
	for(i = 0; i < nodes; i++) 
	{
		cout << "for cycle" <<endl;
		int id = i + 1;
		position p = motePositions.getPosition(i);
		
		//basing on the type of mote, generate the xml code
		if(p.type == COORDINATOR)
			xml = xmlCoordinatorMote(id, p);
		if(p.type == ADVERTISER)
			xml = xmlAdvMotes(id, p);
		
		if(xml == "")
			return false;
		//cout <<"XML: " << m <<endl;
		
		//write string on file
		cscFile << xml << '\n';
	}
	
	//retrieve listener
	position p = motePositions.getPositionListener();
	xml = xmlListenerMote(++i, p);
	
	cscFile << xml << '\n';
	
	//END xml generation
	
	cout << "epilogue" <<endl;
	//now add the epilogue to the file
	schema.open("epilogue.csc");
	while( getline(schema, line) )
	{
		cscFile << line << '\n';
	}
	schema.close();
	
	cscFile.close();
	
	cout << "END" <<endl;
	
	return true;
	
}

#include "generateCSC.h"

/*Constructor of the class*/
generateCSC::generateCSC(int a, int s, double p, double ra)
{
	advNodes = a;
	squareSide = s;
	ploss = p;
	advertiserPositions.init();
	advertiserPositions.setRadius(ra);
	r.init();
}

string convertDouble(double t) 
{
	stringstream convert;	//needed to convert double to string
	string tmpString;
	convert << t;
	tmpString = convert.str();
	return tmpString;
}

string convertInt(int t)
{
	stringstream convert;	//needed to convert double to string
	string tmpString;
	convert << t;
	tmpString = convert.str();
	return tmpString;
}

/*
 * Generates the coordinator of the network
 */
void generateCSC::genCoordinatorMote() 
{
	position p;
	bool acceptable = false;
	
	//check if the position is acceptable
	while(!acceptable) 
	{
		//compute the position in the square
		int x = r.getNumber(squareSide);
		int y = r.getNumber(squareSide);
		
		/*
		* add the position in order to futher state the number of 
		* colliding nodes further state if position are correct, otherwise generate 
		* new position
		*/ 
		p.x = x;
		p.y = y;
		p.type = COORDINATOR;
		acceptable = advertiserPositions.add(p);
	}

}

/*
 * @purpose: generate an advertising mote position
 * @parameter: the id of the node 
 */
void generateCSC::genAdvMotes()
{
	position p;
	bool acceptable = false;
	
	while(!acceptable) 
	{
		//compute the position in the square
		int x = r.getNumber(squareSide);
		int y = r.getNumber(squareSide);
		
		/*
		* add the position in order to futher state the number of 
		* colliding nodes further state if position are correct, otherwise generate 
		* new position
		*/ 
		p.x = x;
		p.y = y;
		p.type = ADVERTISER;
		acceptable = advertiserPositions.add(p);
	}
	
	//select number of colliding nodes
	/*int colliding = advertiserPositions.retrieveColliders();
	
	//complete the xml file
	
	//cout<<xml<<endl;
	
	return xml;*/
}

/*
 * @purpose: generate a new listener mote, 
 * this node position has to be at least in the area of another node 
 */
string generateCSC::genListenerMote(int id)
{
	position p;
	bool acceptable = false;
	
	while(!acceptable) 
	{
		//compute the position in the square
		int x = r.getNumber(squareSide);
		int y = r.getNumber(squareSide);
		
		/*
		* add the position in order to further state the number of 
		* colliding nodes if position are correct, otherwise generate 
		* new position
		*/ 
		p.x = x;
		p.y = y;
		p.type = LISTENER;
		acceptable = advertiserPositions.search(p);
	}
}

/**
 * creates the xml for an advertising mote, basing on its characteristics
 * @params: node id and node position
 * @return: the xml string that will be then written to a file
 */
string generateCSC::xmlAdvMotes(int id, position p)
{
	string xml = "\t\t<mote>\n\t\t\t<breakpoints />\n\t\t\t";
	xml +="<interface_config>\n\t\t\t\tse.sics.cooja.interfaces.Position";
	
	//retrieve the number of colliding nodes from this node position
	int colliders = advertiserPositions.retrieveColliders(id, p);
	
	xml += "\n\t\t\t\t<x>" + convertInt(p.x) + "</x>";
	xml += "\n\t\t\t\t<y>" + convertInt(p.y) + "</y>";
	xml += "\n\t\t\t\t<z>0.0</z>\n\t\t\t</interface_config>";
	xml += "\n\t\t\t<interface_config>\n\t\t\t\tse.sics.cooja.mspmote.interfaces.MspMoteID";
	xml += "\n\t\t\t\t<id>" + convertInt(id) + "</id>\n\t\t\t</interface_config>";
	xml += "\n\t\t\t<motetype_identifier>sky" + convertInt(colliders + 7) + \
	"</motetype_identifier>";
	xml += "\n\t\t</mote>\n";
	
	return xml;
}

/**
 * creates the xml for a listener node, sky15 is the identifier 
 * for a listener node
 * @params: node id and node position
 * @return: the xml string
 */
string generateCSC::xmlListenerMote(int id, position p)
{
	//header
	string xml = "\t\t<mote>\n\t\t\t<breakpoints />\n\t\t\t"; 
	xml += "<interface_config>\n\t\t\t\tse.sics.cooja.interfaces.Position";
	
	xml += "\n\t\t\t\t<x>" + convertInt(p.x) + "</x>";
	xml += "\n\t\t\t\t<y>" + convertInt(p.y) + "</y>";
	xml += "\n\t\t\t\t<z>0.0</z>\n\t\t\t</interface_config>";
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
	string xml = "\t\t<mote>\n\t\t\t<breakpoints />\n\t\t\t";
	xml +="<interface_config>\n\t\t\t\tse.sics.cooja.interfaces.Position";
	
	//complete the xml file
	xml += "\n\t\t\t\t<x>" + convertDouble(p.x) + "</x>";
	xml += "\n\t\t\t\t<y>" + convertDouble(p.y) + "</y>";
	xml += "\n\t\t\t\t<z>0.0</z>\n\t\t\t</interface_config>";
	xml += "\n\t\t\t<interface_config>\n\t\t\t\tse.sics.cooja.mspmote.interfaces.MspMoteID";
	xml += "\n\t\t\t\t<id>" + convertInt(id) + "</id>\n\t\t\t</interface_config>";
	xml += "\n\t\t\t<motetype_identifier>sky1</motetype_identifier>";
	xml += "\n\t\t</mote>\n";
	
	return xml;
}


/*
 * This is the function in charge of generating the csc file:
 * provided a schema that is the header of the csc file, 
 * this functions generates the number of needed motes in the 
 * area stated by the user
 */
void generateCSC::cscInit()
{
	
	string line;
	
	//provided an example file
	ifstream schema;
	schema.open("schema.csc");
	ofstream cscFile;
	cscFile.open("advertising.csc", ios::app);
	int i = 0;
	cout<<"doing copy"<<endl;
	
	//1 step: copy the content of schema.csc in advertising.csc
	while( getline(schema, line) )
	{
		//add the newline character since it is discarded by the getline
		cscFile << line << '\n';
	}
	
	//close the schema file
	schema.close();
	
	cout<<"generating coordinator"<<endl;
	string m;
	m = genCoordinator(i); 
	cscFile << m <<'\n';
	cout<<"generating advertisers"<<endl;
	
	//now it's time to generate and add the various motes to the file
	for( i = 1; i <= advNodes; i++ )
	{
		m = genAdvMotes(i);
		cscFile << m << '\n';
	}
	
	//generate and add the listener mote
	m = genListenerMote(++i);
	cscFile << m << '\n';
	
	cout<<"retrieveColliders"<<endl;
	
	int n = advertiserPositions.retrieveColliders();
	cout<<"Colliding nodes: "<<n<<endl;
	
	//now add the epilogue to the file
	schema.open("epilogue.csc");
	while( getline(schema, line) )
	{
		cscFile << line << '\n';
	}
	schema.close();
	
	cscFile.close();
	
}

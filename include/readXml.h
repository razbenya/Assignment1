#ifndef BOOSTXML_H
#define BOOSTXML_H
#include <boost/foreach.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <string>
#include "../include/cyberdns.h"
#include "../include/cyberpc.h"
#include "../include/cyberexpert.h"
#include <vector>
using boost::property_tree::ptree;
using namespace std;

void readComputers(CyberDNS* dns); 						//read the list of computers from the xml file
void readNetWork(CyberDNS* dns);						//read the lists of wires from the xml file
vector<int> readEvents(CyberDNS* dns , std::vector<CyberExpert*> *expertlist);	//read the lists of events from the xml file
										//return vector with 2 varibles: current day and termination time
void runPCs(CyberDNS* dns);							//run the pc and infect others if worm is activate

#endif /* BOOSTXML_H */


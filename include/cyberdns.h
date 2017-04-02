

#ifndef CYBERDNS_H
#define CYBERDNS_H
#include <iostream>
#include <string>
#include <map>
#include "../include/cyberpc.h"
using namespace std;

class CyberPC; //Forward deceleration

class CyberDNS
{
private:
    std::map<const std::string, CyberPC &> cyber_DNS_;	//Hash map to hold PC names and pointers
    virtual void Clear();
 
public:
    CyberDNS();
	void AddPC(CyberPC & cyber_pc_);				//add new pc to the dns 
	CyberPC & GetCyberPC(const std::string & cyber_pc_name) const;	//return a pc
	std::vector<std::string> GetCyberPCList(); 		// Return list of PC's as a vector of strings.
	virtual ~CyberDNS();					//destructor
};

#endif

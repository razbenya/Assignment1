#ifndef CYBER_PC
#define CYBER_PC
#include <iostream>
#include <string>
#include "../include/cyberworm.h"
#include "../include/cyberdns.h"
using namespace std;

class CyberDNS; // Forward decleration

class CyberPC
{
private:
    const std::string cyber_pc_os_;			//pc operating system
    const std::string cyber_pc_name_;			//pc name
    int cyber_pc_time_to_infect_;			//the time that left till the computer get infected if worm is found
    std::vector<std::string> cyber_pc_connections_;	//the list of computers that connecting to the computer
    CyberWorm * cyber_worm_ = NULL;			//cyber worm
    
    CyberPC(); 						// Prevent the use of an empty constructor
    void Clear();					
    CyberPC(const CyberPC&);				//Prevent the use of copy constructor
    CyberPC operator=(const CyberPC&);			//prevent the use of oprator= constructor
    
public:
    virtual ~CyberPC();
    	CyberPC(string cyber_pc_os, string cyber_pc_name);						// Only use this constructor
	std::string getOS();									//return pc os
	std::string getName();									//return pc name
	void AddConnection(std::string  second_pc);						// Add a connection to this PC
	void Infect(CyberWorm & worm); 								// Add a worm to this PC
	void Run(const CyberDNS & server); 							// Activate PC and infect others if worm is active	
	void Disinfect();									// called by cyber expert, disinfect PC
        bool isInfected();									//return true if the pc is infected
        int getTimeToInfect();									//return the time that left untill pc infection	
        void update();										//update time to infect
        string getWormName();									//return the worm name 
};


#endif
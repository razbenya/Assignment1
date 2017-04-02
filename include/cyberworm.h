#ifndef CYBER_WORM
#define CYBER_WORM
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CyberWorm
{
private:
    const std::string 	cyber_worm_os_;			//worm faivorite os
    const std::string 	cyber_worm_name_;		//worm name
    const int 	cyber_worm_dormancy_time_;		//time that take till the worm start to infect
    CyberWorm();					// Prevent the use of an empty constructor
 
public:
    CyberWorm(std::string cyber_worm_os, std::string cyber_worm_name, int cyber_worm_dormancy_time);
	CyberWorm(const CyberWorm& other); 		//copy constructor;
        int dormanTime();				//return worm dormancy time
        string getOS();					//return os
        string getName();				//return name
};


#endif
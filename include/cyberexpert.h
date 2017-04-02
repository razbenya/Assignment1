#ifndef CYBER_EXPERT
#define CYBER_EXPERT
#include <iostream>
#include <string>
#include <vector>
#include "../include/cyberpc.h"
using namespace std;

class CyberExpert
{
private:
    const string cyber_expert_name_;		//expert name
    const int cyber_expert_work_time_;		//expert work time
    const int cyber_expert_rest_time_;		//how much time the experts break take
    const int cyber_expert_efficiency_;		//how many computer could he check in one time step
    int alreadyWorked;				//how much time steps did the expert work since his last break
    int rested;					//how much time did he rest since he take the break
    CyberExpert(); 				// Prevent the use of an empty constructor
 
public:
    CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_);
 	void Clean(CyberPC & cyber_pc);   	//clean a computer
        int getWorkTime();			//get work time .. 
        int getAlreadyWorked();			//get already worked .. 
        int getRestTime();			//get rest time ..
        int getEfficiency();			//get efficiency
        string getName();			//get name .. 
        void update();				//this function update the time that the expert work and send him to break if needed
        void rest();				//send the expert to work
        void run(CyberDNS*,int);		//run all the experts and make them do their thing
};


#endif
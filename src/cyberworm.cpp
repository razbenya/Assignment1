#include "../include/cyberworm.h"

CyberWorm::CyberWorm(std::string cyber_worm_os, std::string cyber_worm_name, int cyber_worm_dormancy_time):cyber_worm_os_(cyber_worm_os),cyber_worm_name_(cyber_worm_name),cyber_worm_dormancy_time_(cyber_worm_dormancy_time){}

CyberWorm::CyberWorm(const CyberWorm& other):cyber_worm_os_(other.cyber_worm_os_),cyber_worm_name_(other.cyber_worm_name_),cyber_worm_dormancy_time_(other.cyber_worm_dormancy_time_)
{}

int CyberWorm::dormanTime(){
	return cyber_worm_dormancy_time_;
}

string CyberWorm::getOS(){
	return cyber_worm_os_;
}

string CyberWorm::getName(){
	return cyber_worm_name_;
}


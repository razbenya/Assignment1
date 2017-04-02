#include "../include/cyberpc.h"  

CyberPC::CyberPC(string cyber_pc_os, string cyber_pc_name): cyber_pc_os_(cyber_pc_os), cyber_pc_name_(cyber_pc_name),cyber_pc_time_to_infect_(0),cyber_pc_connections_() {}

CyberPC::~CyberPC(){
	Clear();
}
void CyberPC::Clear(){
	if(cyber_worm_!=NULL)
		delete cyber_worm_;
	cyber_pc_connections_.clear();
}

void CyberPC::AddConnection(string second_pc) {
	cyber_pc_connections_.push_back(second_pc);   
}

string CyberPC::getOS(){
	return cyber_pc_os_;
}

string CyberPC::getName()
{
	return cyber_pc_name_;
}

bool CyberPC::isInfected(){
	return cyber_worm_!=NULL;
}

int CyberPC::getTimeToInfect(){
	return cyber_pc_time_to_infect_;
}

void CyberPC::update(){
	if(cyber_worm_!=NULL)
		if(cyber_pc_time_to_infect_>0)
			cyber_pc_time_to_infect_--;
}

string CyberPC::getWormName(){
	return cyber_worm_->getName();
}

void CyberPC::Infect(CyberWorm & worm){
	if(worm.getOS()==cyber_pc_os_){
		if (cyber_worm_!=NULL)
			Disinfect();   
		cyber_pc_time_to_infect_=worm.dormanTime();
		cyber_worm_ = new CyberWorm(worm);
		cout<<"             "<< this->getName()<<" infected by " << worm.getName()<<endl;;
	}
	else
		cout<<"             "<<"Worm "<<worm.getName()<<" is incompatible with "<<this->getName()<<endl;
}

void CyberPC::Run(const CyberDNS & server){

	if(cyber_worm_!=NULL && cyber_worm_->dormanTime() == cyber_pc_time_to_infect_)
		cout<<"       "<< cyber_pc_name_ <<": Worm " << cyber_worm_->getName() << " is dormant "<<endl;
	if(cyber_pc_time_to_infect_==0 && cyber_worm_!=NULL)
	{
		cout << "       "<<this->getName() << " Infecting.."<<endl;
		vector<string> pcs = cyber_pc_connections_;
		for(size_t i=0;i<pcs.size();i++)
		{
			server.GetCyberPC(pcs[i]).Infect(*cyber_worm_);
		}
	}
}
void CyberPC::Disinfect(){    
	if (cyber_worm_!=NULL){
		delete cyber_worm_;
		cyber_worm_ = NULL;
	}
}





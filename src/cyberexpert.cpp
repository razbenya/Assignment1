#include "../include/cyberexpert.h"
/*
 * init cyberExpert
 */
CyberExpert::CyberExpert(string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_):
cyber_expert_name_(cyber_expert_name_),cyber_expert_work_time_(cyber_expert_work_time_),cyber_expert_rest_time_(cyber_expert_rest_time_),cyber_expert_efficiency_(cyber_expert_efficiency_),alreadyWorked(0),rested(0)
{}

void CyberExpert::run(CyberDNS* dns,int computersChecked){
	vector<string> pcs = dns->GetCyberPCList();
	if(this->getAlreadyWorked() != this->getWorkTime()){
	  size_t size = (computersChecked+this->getEfficiency());
		for(size_t j=computersChecked;j<size&&j<pcs.size();j++){
			this->Clean(dns->GetCyberPC(pcs[(pcs.size()-1)-j]));
		}
	}
	this->update();
}
/*
 * clean a computer
 */
void CyberExpert::Clean(CyberPC & cyber_pc){
	cout<< "       " <<this->getName() << " examining "<<cyber_pc.getName() <<endl;
	if(cyber_pc.isInfected())
		cout<< "            Worm "<< cyber_pc.getWormName() << " successfully removed from "<< cyber_pc.getName() <<endl;
	cyber_pc.Disinfect();   
}
int CyberExpert::getEfficiency(){
	return cyber_expert_efficiency_;
}

int CyberExpert::getWorkTime(){
	return cyber_expert_work_time_;
}

int CyberExpert::getRestTime(){
	return cyber_expert_rest_time_;
}

string CyberExpert::getName(){
	return cyber_expert_name_;
}
void CyberExpert::update(){
	if( cyber_expert_work_time_!= alreadyWorked){
		alreadyWorked++;
		if(cyber_expert_work_time_== alreadyWorked)
			cout<<"       "<<this->getName()<< " is taking a break"<<endl;
	} 
	else 
		rest();
}
void CyberExpert::rest(){
	if(cyber_expert_rest_time_!=rested){
		rested++;
		if(cyber_expert_rest_time_==rested){
			cout<<"       "<< this->getName() <<" is back to work"<<endl;
			rested=0;
			alreadyWorked=0;
		}
	}
}
int CyberExpert::getAlreadyWorked(){
	return alreadyWorked;

}
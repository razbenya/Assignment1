#include "../include/cyberdns.h"

CyberDNS::CyberDNS():cyber_DNS_(){}

CyberDNS::~CyberDNS(){
	Clear();
}

void CyberDNS::Clear() {
	map<string,CyberPC &>::iterator i;
	for(i=cyber_DNS_.begin();i!=cyber_DNS_.end();i++){
		delete &i->second;
	}
}


void CyberDNS::AddPC(CyberPC & cyber_pc_){
	if(cyber_DNS_.find(cyber_pc_.getName())==cyber_DNS_.end())
		cyber_DNS_.insert(pair<string,CyberPC &>(cyber_pc_.getName(),cyber_pc_));
	else
		delete &cyber_pc_;
}

CyberPC &  CyberDNS::GetCyberPC(const std::string & cyber_pc_name) const{
	return cyber_DNS_.find(cyber_pc_name)->second;
}

vector<string> CyberDNS::GetCyberPCList(){
	vector<string> pcs;
	for(map<string,CyberPC &>::iterator i=cyber_DNS_.begin();i!=cyber_DNS_.end();i++){
		pcs.push_back(i->first);
	}
	return pcs;
}	
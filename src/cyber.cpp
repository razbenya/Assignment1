#include "../include/cyberpc.h"
#include "../include/cyberdns.h"
#include "../include/cyberworm.h"
#include "../include/cyberexpert.h"
#include "../include/readXml.h"

#include <iostream>

int main(int argc, char**argv)
{
	int computersChecked = 0;
	CyberDNS* dns = new CyberDNS();
	std::vector<CyberExpert*>* experts = new vector<CyberExpert*>;
	readComputers(dns);
	readNetWork(dns);
	vector<int>days = readEvents(dns,experts);
	for(int i=days[1];i<=days[0];i++){
		cout<<"Day: "<<i<<endl;
		for(size_t Experts=0;Experts<(*experts).size();Experts++)
		{
			((*experts)[Experts])->run(dns,computersChecked);
			computersChecked = (*experts)[Experts]->getEfficiency();
		}
		runPCs(dns);
		computersChecked=0;
	}
	for(size_t i=0;i<(*experts).size();i++)
		delete (*experts)[i];
	delete experts;
	delete dns;
	experts = NULL;
	dns = NULL;
	return 0;
}
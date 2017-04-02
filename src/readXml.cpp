#include "../include/readXml.h"
#include "../include/cyberexpert.h"

void readComputers(CyberDNS* dns){
	const std::string COMPUTER_XML_PACH="computers.xml";
	ptree computers_pt;
	read_xml(COMPUTER_XML_PACH,computers_pt);
	string pc_name;
	string pc_os;

	BOOST_FOREACH(boost::property_tree::ptree::value_type const & node,computers_pt){
		pc_name=node.second.get<string>("name");
		pc_os=node.second.get<string>("os");
		CyberPC* pc = new CyberPC(pc_os,pc_name);
		cout << "Adding to server:" << pc_name << "\n";
		dns->AddPC(*pc);
		cout << pc_name << " connected to server\n";
		pc = NULL;
	}
	for(int i=0;i<3;i++)
		cout<< "-------------------------------------------------\n";
	computers_pt.clear();
}

void readNetWork(CyberDNS* dns){
	const std::string NETWORK_XML_PACH="network.xml";
	ptree network_pt;
	read_xml(NETWORK_XML_PACH,network_pt);
	string pointA;
	string pointB;

	BOOST_FOREACH(boost::property_tree::ptree::value_type const & node,network_pt){
		pointA=node.second.get<string>("pointA");
		pointB=node.second.get<string>("pointB");
		cout<<"Connecting " << pointA << " to " << pointB <<endl;
		(dns->GetCyberPC(pointA)).AddConnection(pointB);
		cout<< "    "<< pointA << " now Connected to " << pointB <<endl;
		(dns->GetCyberPC(pointB)).AddConnection(pointA);
		cout<< "    " << pointB << " now Connected to " << pointA <<endl;
	}
	for(int i=0;i<3;i++)
		cout<< "-------------------------------------------------\n";
	network_pt.clear();
}

void runPCs(CyberDNS* dns)
{
	vector<string> s = dns->GetCyberPCList();
	for(int i=(s.size()-1);i>=0;i--){
		dns->GetCyberPC(s[i]).Run(*dns);
		dns->GetCyberPC(s[i]).update();
	}    
}

vector<int> readEvents(CyberDNS* dns , std::vector<CyberExpert*> *expertlist) {
	const std::string EVENTS_XML_PACH="events.xml";
	ptree events_pt;
	read_xml(EVENTS_XML_PACH,events_pt);
	//hack events
	string computer;
	string wormName;
	int wormDormancy;
	string wormOS;
	//clock In Events
	string name;
	int workTime;
	int restTime;
	int efficiency;
	int computersChecked = 0;
	//termination events
	int time;

	int day = 0;

	BOOST_FOREACH(boost::property_tree::ptree::value_type const & node,events_pt){
		if(node.first == "hack"){
			cout<<"Day: " << day <<endl;
			computer = node.second.get<string>("computer");
			wormName = node.second.get<string>("wormName");
			wormDormancy = node.second.get<int>("wormDormancy");
			wormOS = node.second.get<string>("wormOs");
			cout << "       Hack occured on " << computer <<endl;
			CyberWorm* worm = new CyberWorm(wormOS,wormName,wormDormancy);
			dns->GetCyberPC(computer).Infect(*worm);
			delete worm;
			worm = NULL;
			runPCs(dns);
			day++;
		}
		else if(node.first == "clock-in"){
			cout<<"Day: " << day <<endl;
			name = node.second.get<string>("name");
			workTime = node.second.get<int>("workTime");
			restTime = node.second.get<int>("restTime");
			efficiency = node.second.get<int>("efficiency");
			cout<<"       Clock-In: " << name << " began working "<<endl;
			CyberExpert * ce = new CyberExpert(name,workTime,restTime,efficiency);
			expertlist->push_back(ce);
			for(size_t i=0;i<(*expertlist).size();i++){
				(*expertlist)[i]->run(dns,computersChecked);
				computersChecked = (*expertlist)[i]->getEfficiency();
			}
			computersChecked=0;
			runPCs(dns);
			day++;
		}
		else{
			time = node.second.get<int>("time");
		}

	}
	events_pt.clear();
	vector<int> tmp;
	tmp.push_back(time);
	tmp.push_back(day);
	return tmp;
}


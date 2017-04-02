# All Targets
all: cyber

# Tool invocations
cyber: bin/cyberdns.o bin/cyberpc.o bin/cyberworm.o bin/cyberexpert.o bin/readXml.o bin/cyber.o
	@echo 'Building target: cyber'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/cyber bin/cyberdns.o bin/cyberpc.o bin/cyberworm.o bin/cyberexpert.o bin/readXml.o bin/cyber.o
	@echo 'Finished building target: cyber'
	@echo ' '

# Depends on the source and header files
bin/cyberdns.o: src/cyberdns.cpp 
	g++ -g -Wall -Weffc++ -c -Linclude -o bin/cyberdns.o src/cyberdns.cpp

# Depends on the source and header files	
bin/cyberpc.o: src/cyberpc.cpp
	g++ -g -Wall -Weffc++ -c -Linclude -o bin/cyberpc.o src/cyberpc.cpp

# Depends on the source and header files	
bin/cyberexpert.o: src/cyberexpert.cpp
	g++ -g -Wall -Weffc++ -c -Linclude -o bin/cyberexpert.o src/cyberexpert.cpp
	
# Depends on the source and header files
bin/cyberworm.o: src/cyberworm.cpp
	g++ -g -Wall -Weffc++ -c -Linclude -o bin/cyberworm.o src/cyberworm.cpp

	
#Depends on the source and header files
bin/readXml.o: src/readXml.cpp
	g++ -g -Wall -Weffc++ -c -Linclude -I/usr/local/boost/1.57.0/include/boost -o bin/readXml.o src/readXml.cpp	
	
# Depends on the source and header files
bin/cyber.o: src/cyber.cpp
	g++ -g -Wall -Weffc++ -c -Linclude -I/usr/local/boost/1.57.0/include/boost -o bin/cyber.o src/cyber.cpp

	

#Clean the build directory
clean: 
	rm -f bin/*
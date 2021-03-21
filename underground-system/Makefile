main.exe: main.o underground_system.o station_pair.o customer.o
	g++ -o main.exe main.o underground_system.o station_pair.o customer.o

main.o: main.cpp underground_system.cpp station_pair.cpp customer.cpp
	g++ -c customer.cpp station_pair.cpp underground_system.cpp main.cpp 

clean:
	del *.o *.exe
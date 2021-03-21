#include "underground_system.h"
#include <iostream>

using namespace std;

int main() {
    UndergroundSystem undergroundSystem;

    undergroundSystem.checkIn(45, "Leyton", 3);
    undergroundSystem.checkIn(32, "Paradise", 8);
    undergroundSystem.checkIn(27, "Leyton", 10);
    undergroundSystem.checkOut(45, "Waterloo", 15);
    undergroundSystem.checkOut(27, "Waterloo", 20);
    undergroundSystem.checkOut(32, "Cambridge", 22);

    cout << undergroundSystem.getAverageTime("Paradise", "Cambridge") << endl; // return 14.00000. There was only one travel from "Paradise" (at time 8) to "Cambridge" (at time 22)
    cout << undergroundSystem.getAverageTime("Leyton", "Waterloo") << endl;    // return 11.00000. There were two travels from "Leyton" to "Waterloo", a customer with id=45 from time=3 to time=15 and a customer with id=27 from time=10 to time=20. So the average time is ( (15-3) + (20-10) ) / 2 = 11.00000
    
    undergroundSystem.checkIn(10, "Leyton", 24);
    
    cout << undergroundSystem.getAverageTime("Leyton", "Waterloo") << endl; // return 11.00000
    
    undergroundSystem.checkOut(10, "Waterloo", 38);
    
    cout << undergroundSystem.getAverageTime("Leyton", "Waterloo") << endl; // return 12.00000
}
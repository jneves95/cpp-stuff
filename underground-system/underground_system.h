// underground_system.h
#ifndef UNDERGROUND_SYSTEM_H
#define UNDERGROUND_SYSTEM_H

#include "customer.h"
#include "station_pair.h"
#include <string>
#include <unordered_map>

class UndergroundSystem {
private:
    std::unordered_map<int, Customer> customersInTransit;
    std::unordered_map<std::string, StationPair> stationPairs;

public:
    void checkIn(int id, std::string stationName, int t);
    void checkOut(int id, std::string stationName, int t);
    double getAverageTime(std::string startStation, std::string endStation);
};

#endif
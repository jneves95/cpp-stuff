// station_pair.h
#ifndef STATION_PAIR_H
#define STATION_PAIR_H

#include <string>

class StationPair {
private:
    std::string startStation;
    std::string endStation;
    double averageTime;
    int trips;

public:
    StationPair();
    StationPair(std::string startStation, std::string endStation);
    StationPair(std::string startStation, std::string endStation, int time);

    void addTrip(int time);

    double getAverageTime() { return averageTime; }
};

#endif
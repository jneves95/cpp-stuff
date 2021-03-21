#include "station_pair.h"
#include <string>

StationPair::StationPair() { throw "Error: Station names not specified."; }
StationPair::StationPair(std::string startStation, std::string endStation) : startStation(startStation), endStation(endStation), averageTime(0), trips(0) {}
StationPair::StationPair(std::string startStation, std::string endStation, int time) : startStation(startStation), endStation(endStation), averageTime(time), trips(1) {}

/**
 * Updates the number of trips and the average time for this station pair.
 */
void StationPair::addTrip(int time) {
    double temp = averageTime * trips + time;
    averageTime = temp / ++trips;
}
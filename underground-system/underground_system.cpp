#include "customer.h"
#include "station_pair.h"
#include "underground_system.h"
#include <iostream>
#include <unordered_map>

using namespace std;

void UndergroundSystem::checkIn(int id, string stationName, int t) {
    // Check if customer is already checked in
    if (customersInTransit.find(id) != customersInTransit.end()) {
        cout << "Customer " << id << " is already checked in." << endl;
        return;
    }

    // Save this customer until it checks out
    customersInTransit.emplace(id, Customer(id, stationName, t));
}

void UndergroundSystem::checkOut(int id, string stationName, int t) {
    // Check if customer is checked in
    auto it = customersInTransit.find(id);

    if (it == customersInTransit.end()) {
        cout << "Customer " << id << " is not checked in." << endl;
        return;
    }
    else {
        Customer c = it->second;
        string startStation = c.getStartStation();
        int startTime = c.getStartTime();

        // Determine time between stations
        int duration = t - startTime;

        // Look for station pair
        string pairName = startStation + ":" + stationName;
        auto it = stationPairs.find(pairName);

        if (it == stationPairs.end()) {
            // Insert new station pair
            stationPairs.emplace(pairName, StationPair(startStation, stationName, duration));
        }
        else {
            // Update station pair
            it->second.addTrip(duration);
        }

        // Check customer out
        customersInTransit.erase(id);
    }
}

double UndergroundSystem::getAverageTime(string startStation, string endStation) {
    string pairName = startStation + ":" + endStation;

    auto it = stationPairs.find(pairName);

    if (it != stationPairs.end()) {
        return it->second.getAverageTime();
    }
    
    return -1;
}
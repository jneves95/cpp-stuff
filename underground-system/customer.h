// customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    int id;
    std::string startStation;
    int startTime;

public:
    Customer(int id, std::string startStation, int startTime);

    std::string getStartStation() { return startStation; }
    int getStartTime() { return startTime; }
};

#endif
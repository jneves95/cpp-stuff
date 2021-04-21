#pragma once

#include "nested_integer.h"

class NestedIterator {
private:
    int index;
    vector<NestedInteger> list;
    NestedIterator* current;
public:
    NestedIterator(vector<NestedInteger>& list) : index(0), list(list), current(nullptr) {}

    int next();

    bool hasNext();
};
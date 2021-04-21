#include <iostream>
#include <vector>
#include "nested_integer.h"
#include "nested_iterator.h"

using namespace std;

int NestedIterator::next() {
    if (current) {
        return current->next();
    }

    int val = list[index].getInteger();
    index++;
    return val;
}

bool NestedIterator::hasNext() {
    if (index == list.size()) return false;

    if (list[index].isInteger()){
        if (current) {
            delete(current);
            current = nullptr;
        }

        return true;
    } 

    if (current == nullptr) {
        vector<NestedInteger> temp = list[index].getArray();
        current = new NestedIterator(temp);
    }

    if (!current->hasNext()) {
        delete(current);
        current = nullptr;
        index++;

        return hasNext();
    }
    
    return true;
}
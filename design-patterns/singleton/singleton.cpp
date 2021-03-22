#include <iostream>

// Singleton pattern example
class Singleton {
private:
    static Singleton *instance; // Holds the only instance of this class
    int data;   // Some protected data

    Singleton() {   // Private constructor to prevent object creation
        data = 0;
    }
public:
    static Singleton *getInstance();  // Gets or creates the only instance of this class

    // Some business logic
    int getData() {
        return data;
    }

    void setData(int data) {
        this->data = data;
    }

    void doubleData() {
        data *= 2;
    }

    // Extra methods out of the scope of the example; for completion only
    Singleton(Singleton &other) = delete; // Singleton should not be cloneable

    void operator=(const Singleton &) = delete; // Singleton should not be assignable
};

// Static members need to be defined explicitly
Singleton* Singleton::instance = nullptr;

// TIP: Static method should be defined outside the class
Singleton *Singleton::getInstance() {
    if (instance == nullptr) {
        instance = new Singleton();
    }
    return instance;
}

int main() {
    Singleton *instance = instance->getInstance();

    std::cout << instance->getData() << std::endl;
    instance->setData(5);
    std::cout << instance->getData() << std::endl;
    instance->doubleData();
    std::cout << instance->getData() << std::endl;
}
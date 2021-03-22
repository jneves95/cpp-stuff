#include <iostream>
#include <string>
#include <thread>
#include <mutex>

// Follows the same example for our simple singleton class, but makes it correctly-destructable and thread-safe

class Singleton {
private:
    static Singleton *instance;
    static std::mutex mutex;
    std::string owner;

    Singleton(std::string owner) {
        this->owner = owner;
    }  

public:
    static Singleton *getInstance(std::string s); 

    std::string getOwner() { return owner; }

    // Extra methods out of the scope of the example; for completion only
    Singleton(Singleton &other) = delete; // Singleton should not be cloneable

    void operator=(const Singleton &) = delete; // Singleton should not be assignable
};

// Static members need to be defined explicitly
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mutex;

Singleton *Singleton::getInstance(const std::string s) {
    std::lock_guard<std::mutex> lock(mutex);    // Scope lock

    if (instance == nullptr) {
        instance = new Singleton(s);
    }
    return instance;
}

void ThreadOne() {
    // Emulate slow initialization
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton *instance = Singleton::getInstance("One");
    std::cout << instance->getOwner() << std::endl;
}

void ThreadTwo() {
    // Emulate slow initialization
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton *instance = Singleton::getInstance("Two");
    std::cout << instance->getOwner() << std::endl;
}

int main() {
    std::cout << "Although we cannot be sure which thread is going to be the first to get the lock, we should see the same data displayed, ";
    std::cout << "meaning the singleton was reused successfully, otherwise two singletons were created." << std::endl;

    std::thread t1(ThreadOne);
    std::thread t2(ThreadTwo);

    t1.join();
    t2.join();
}
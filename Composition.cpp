#include<iostream>
using namespace std;

class Engine {
public:
    void start() {
        // Code to start the engine
        cout<<"Engine start "<<endl;
    }
};

class Car {
public:
    Car() : engine(new Engine())
    {
        cout<<"ctor "<<endl;
    }
    void startCar() {
        cout<<"startCar "<<endl;
        engine->start();
    }
    ~Car()
    {
        cout<<"dtor"<<endl;
        delete engine;
    }
private:
    Engine* engine;
};

int main() {
    Car car;
    car.startCar();
    return 0;
}
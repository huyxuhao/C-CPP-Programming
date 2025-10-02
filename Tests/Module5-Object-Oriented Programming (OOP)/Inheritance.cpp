#include <iostream>

// Base class
class Vehicle
{
public:
    int speed = 0;
    void accelerate()
    {
        speed += 10;
    }
};

// Derived class
// Car inherits publicly from Vehicle
class Car : public Vehicle
{
public:
    int numberOfDoors = 4;
};

int main()
{
    Car myCar;
    myCar.speed = 50;
    myCar.accelerate();

    std::cout << "Car speed: " << myCar.speed << std::endl;
    std::cout << "Doors: " << myCar.numberOfDoors << std::endl;

    Car *carPtr = &myCar;
    carPtr->speed = 80;
    std::cout << "Updated car speed via pointer: " << carPtr->speed << std::endl;

    return 0;
}
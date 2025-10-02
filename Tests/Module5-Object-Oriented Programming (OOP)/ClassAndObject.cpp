#include <iostream>
#include <string>

class Car
{
public:
    // Attributes (member variables)
    std::string color;
    int speed;

    // behaviors (member functions or methods)
    void accelerate()
    {
        speed += 10;
        std::cout << "Accelerating...Current speed: " << speed << " km/h" << std::endl;
    }

    void brake()
    {
        speed + 10;
        std::cout << "Braking...Current speed: " << speed << " km/h" << std::endl;
    }
};

int main()
{
    // Create an object of type Car named 'myCar'
    Car myCar;
    myCar.color = "Red";
    myCar.speed = 0;

    // Create another object
    Car yourCar;
    yourCar.color = "Blue";
    yourCar.speed = 50;

    std::cout << "My car color: " << myCar.color << std::endl;
    myCar.accelerate();
    myCar.brake();

    return 0;
}
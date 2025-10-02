#include <iostream>

class SmartCar
{
private:
    int speed;

public:
    // Setter: A public method to safely modify private data
    void setSpeed(int newSpeed)
    {
        if (newSpeed > 0)
        {
            speed = newSpeed;
        }
    }

    // Getter: A public method to safely read private data
    int getSpeed()
    {
        return speed;
    }
};

int main()
{

    SmartCar myCar;
    myCar.setSpeed(80);
    myCar.setSpeed(-50); // this will be ignored due to validation in setter

    std::cout << "Current speed: " << myCar.getSpeed() << std::endl;

    return 0;
}
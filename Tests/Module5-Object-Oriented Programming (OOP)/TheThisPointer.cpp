#include <iostream>
#include <string>

class Player
{
private:
    std::string name;
    int health;

public:
    Player(std::string name, int health)
    {
        //'this->name' refers to the class member variable
        //'name' refers to the function parameter
        this->name = name;
        this->health = health;
    }

    void printInfo()
    {
        std::cout << "Player: " << this->name << ", Health: " << this->health << std::endl;
    }
};

int main()
{
    Player player1("Alice", 100);
    player1.printInfo();
    return 0;
}
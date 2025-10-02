#include <iostream>
#include <string>

class Player
{
private:
    std::string name;
    int health;

public:
    // Parameterized constructor
    Player(std::string n, int h)
    {
        name = n;
        health = h;

        std::cout << name << " has entered the game!" << std::endl;
    }

    // Destructor
    ~Player()
    {
        std::cout << name << " has left the game!" << std::endl;
    }
};

int main()
{
    // Constructor is called automatically when player1 is created
    Player player1 = Player("Alice", 100);

    // When main() ends, player1 goes out of scope and  its detructor is called
    return 0;
}
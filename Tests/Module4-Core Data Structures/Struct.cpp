#include <iostream>
#include <string>

// Define a template for our data type
struct Player
{
    std::string name;
    int jerseyNumber;
    double battingAverage;
};

int main()
{
    // create an instance of struct
    Player player1;

    // access members with dot operator (.)
    player1.name = "John Doe";
    player1.jerseyNumber = 42;
    player1.battingAverage = 0.325;

    std::cout << "Player: " << player1.name << std::endl;
    std::cout << "Jersey: " << player1.jerseyNumber << std::endl;

    // using a pointer to a struct
    Player *playerPtr = &player1;
    std::cout << "Name via pointer: " << playerPtr->name << std::endl;

    return 0;
}
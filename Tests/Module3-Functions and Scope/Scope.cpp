#include <iostream>

// This is a global variable
std::string globalMessage = "I am global";

// this is a static variable
static int count = 0;

void myFunction()
{
    // this is a local vairable
    int localNumber = 100;
    std::cout << "Inside myFunction: " << localNumber << std::endl;
    std::cout << "Global message in myFunction: " << globalMessage << std::endl;

    count++;
}

int main()
{
    myFunction();
    myFunction();

    std::cout << "Inside main: " << globalMessage << std::endl;
    // std::cout << localNumber; // Error: localNumber is not accessible here

    std::cout << "myFunction was called " << count << " times." << std::endl;

    return 0;
}
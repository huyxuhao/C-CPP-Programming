#include <iostream>
#include <string>
using std::string;

int main()
{
    string name;
    int age;

    // prompt the user their name
    std::cout << "Please enter your name:";
    std::getline(std::cin, name); // use getline to read a full line of text

    // prompt the user their age
    std::cout << "Please enter your age: ";
    std::cin >> age; // use >> operator to read formatted

    // print a greeting
    std::cout << "Hello, " << name << "! You are " << age << " years old." << std::endl;

    return 0;
}
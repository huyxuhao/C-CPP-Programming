#include <iostream>
#include <string> //required for using string data type
// To avoid repeating std::string
using std::string;

int main()
{
    // declaring variables and initializing them
    int userAge = 25;         // for storing whole numbers
    double price = 19.99;     // for storing decimal numbers
    char grade = 'A';         // for storing a single character
    bool isStudent = true;    // for storing boolean values
    string userName = "Alex"; // for a sequence of characters (note the use of double quotes)

    std::cout << "User: " << userName << std::endl;
    std::cout << "Age: " << userAge << std::endl;
    std::cout << "Price: $" << price << std::endl;
    return 0;
}
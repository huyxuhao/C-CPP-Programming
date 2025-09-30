#include <iostream>

int main()
{

    // the if statement
    int score = 85;
    if (score > 60)
    {
        std::cout << "You passed!" << std::endl;
    }

    // the if-else statement
    int number = 7;
    if (number % 2 == 0)
    {
        std::cout << number << " is even." << std::endl;
    }
    else
    {
        std::cout << number << " is odd." << std::endl;
    }

    // the if-else if-else ladder
    score = 88;

    if (score >= 90)
    {
        std::cout << "Grade: A" << std::endl;
    }
    else if (score >= 80)
    {
        std::cout << "Grade: B" << std::endl;
    }
    else if (score >= 70)
    {
        std::cout << "Grade: C" << std::endl;
    }
    else
    {
        std::cout << "Grade: F" << std::endl;
    }

    // the switch statement
    int choice = 2;

    switch (choice)
    {
    case 1:
        std::cout << "You selected New Game." << std::endl;
        break;
    case 2:
        std::cout << "You selected Load Game." << std::endl;
        break;
    default:
        std::cout << "Invalid choice." << std::endl;
        break;
    }

    // the ternary operator
    int a = 5, b = 10;
    (a > b) ? std::cout << a << " is greater than " << b << std::endl
            : std::cout << b << " is greater than " << a << std::endl;

    return 0;
}
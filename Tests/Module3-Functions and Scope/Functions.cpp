#include <iostream>

// function definition
// this function take no input and return no value (void)
void printGreeting()
{
    std::cout << "Hello and Welcome!" << std::endl;
}

// function prototype (declaration)
void printFarewell();

// parameters and arguments
// parameters: the variables listed in the function's definition
// arguments: the actual values you pass to the function when you call it

// pass-by-value
// by default, c++ copies the arguments you pass to the function.
// Any changes made to the parameter inside the function do not affect the original variable.
void tryToChange(int number)
{
    number = 100; // this change the copy, not the original
    std::cout << "Inside the function, number is: " << number << std::endl;
}

// pass-by-reference (using &)
// if you want the function to modify the original variable, you can pass it by reference
void actuallyChange(int &number)
{
    number = 100; // this change the original variable
}

// return values
int add(int a, int b = 0) // b has a default value of 0
{
    return a + b;
}

// function overloading
void print(int value)
{
    std::cout << "Integer: " << value << std::endl;
}
void print(double value)
{
    std::cout << "Double: " << value << std::endl;
}
void print(std::string value)
{
    std::cout << "String: " << value << std::endl;
}

int main()
{
    printGreeting(); // function call

    printFarewell(); // function call

    std::cout << "===Pass-By-Value===" << std::endl;

    int myNumber = 10;

    std::cout << "Before the function, myNumber is: " << myNumber << std::endl;

    tryToChange(myNumber); // a copy of myNumber is passed

    std::cout << "After the function, myNumber is: " << myNumber << std::endl;

    std::cout << "===Pass-By-Reference===" << std::endl;

    std::cout << "Before the function, myNumber is: " << myNumber << std::endl;

    actuallyChange(myNumber); // myNumber is passed by reference

    std::cout << "After the function, myNumber is: " << myNumber << std::endl;

    int sum1 = add(6, 8);
    std::cout << "Sum1: " << sum1 << std::endl;
    int sum2 = add(6); // b uses default value of 0
    std::cout << "Sum2: " << sum2 << std::endl;

    print(1);
    print(3.14);
    print("Function Overloading");

    return 0;
}

// function definition
void printFarewell()
{
    std::cout << "Goodbye!" << std::endl;
}
#include <iostream>

const double PI = 3.14158; // value of a constant variable cannot be changed after initialization

int main()
{
    int a = 5;
    int b = 10;
    int sum = a + b;    // adding operator
    int modulo = b % a; // modulus operator

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Modulo: " << modulo << std::endl;

    return 0;
}
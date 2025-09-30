#include <iostream>

// A simple recursive function to calculate factorial of a number
int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    // Recursive step: n * factorial of (n - 1)
    return n * factorial(n - 1);
}

int main()
{
    int result = factorial(4); // 4! = 4 * 3 * 2 * 1 = 24
    std::cout << "Factorial of 4 is: " << result << std::endl;
    return 0;
}
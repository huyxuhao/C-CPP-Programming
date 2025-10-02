#include <iostream>

int main()
{
    int score[2]; // declare an array (c-style) of 2 integers

    // initialize the array
    score[0] = 17;
    score[1] = 86;

    // you can also initialize an array when you declare it
    // int score[2] = {17, 86};

    // access and print the elements
    std::cout << "the score at index 0 is: " << score[0] << std::endl;

    // modify an element
    score[1] = 12;
    std::cout << "the score at index 1 is: " << score[1] << std::endl;

    // iterate over the array
    for (int i = 0; i < 2; i++)
    {
        std::cout << "Element " << i << ": " << score[i] << std::endl;
    }

    // iterate using range-based for loop (c++11 and later)
    for (int s : score)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    return 0;
}
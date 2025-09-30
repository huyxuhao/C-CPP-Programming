#include <iostream>

int main()
{

    // the for loop
    for (int i = 1; i <= 5; i++)
    {
        std::cout << "Iteration number: " << i << std::endl;
    }

    // the while loop
    int countDown = 3;
    while (countDown > 0)
    {
        std::cout << countDown << std::endl;
        countDown--; // if the condition in a while loop never becomes false, you'll create a infinite loop
    }

    // the do-while loop
    int choice;
    do
    {
        std::cout << "---Menu---" << std::endl;
        std::cout << "1. Start" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
    } while (choice != 2);

    std::cout << "Goodbye!" << std::endl;

    // loop Control: break and continue

    for (int i = 1; i <= 20; i++)
    {
        if (i > 10)
        {
            break; // exits the loop entirely
        }
        if (i % 2 == 0)
        {
            continue; // skips this iteration (because it's even number)
        }
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // the range-based for loop (c++11 and later)
    int scores[] = {88, 95, 76, 100, 82};
    for (int score : scores)
    {
        std::cout << score << " ";
    }
    std::cout << std::endl;

    // using auto and modifying elements
    for (auto score : scores) // to get a copy of each element (read-only)
    {
        std::cout << score << " "; // auto deduces the type of score
    }
    std::cout << std::endl;

    // to modify the original array, use a reference
    for (auto &score : scores) // use & (ampersand) to get a reference to each element
    {
        score *= 2;
    }

    // print modified scores
    std::cout << "Modified scores: ";
    for (auto score : scores)
    {
        std::cout << score << " ";
    }
    std::cout << std::endl;

    return 0;
}
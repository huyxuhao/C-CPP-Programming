#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //-------------------------------//
    // Non-modifying algorithms
    std::vector<int> numbers = {10, 25, 10, 30, 42, 10};

    // Count how many times 10 appears
    int num_tens = std::count(numbers.begin(), numbers.end(), 10);
    std::cout << "10 appears " << num_tens << " times\n";

    // Find the first occurence of 30
    auto it = std::find(numbers.begin(), numbers.end(), 30);
    if (it != numbers.end())
    {
        std::cout << "Found 30 at position: " << std::distance(numbers.begin(), it) << "\n";
    }
    else
    {
        std::cout << "30 not found\n";
    }
    //-------------------------------//
    // Modifying algorithms
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Sorted numbers: " << "\n";
    // Using range-based loop
    for (const auto &num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Remove duplicates
    auto new_end = std::remove(numbers.begin(), numbers.end(), 10);
    for (const auto &num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    numbers.erase(new_end, numbers.end());
    std::cout << "After removing 10s: " << "\n";
    for (const auto &num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
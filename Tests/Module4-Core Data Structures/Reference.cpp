#include <iostream>
#include <string>

int main()
{
    std::string food = "Pizza";

    // 'meal' is now another name for 'food'
    // the '&' is only used in the declaration
    std::string &meal = food;

    std::cout << "Food: " << food << std::endl;
    std::cout << "Meal: " << meal << std::endl;

    // if you change the alias, the original changes too
    meal = "Burger";

    std::cout << "Food: " << food << std::endl;
    std::cout << "Meal: " << meal << std::endl;

    return 0;
}
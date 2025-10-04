#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory>

struct Person
{
    std::string name;
    int age;
};

struct PtrCompare
{
    bool operator()(std::shared_ptr<Person> const &a, std::shared_ptr<Person> const &b) const
    {
        return a->name < b->name; // compare by pointed-to value
    }
};

int main()
{
    //---------------------------------------------------//
    // Vector example
    std::vector<int> numbers;
    numbers.push_back(10); // add to the end
    numbers.push_back(20);
    numbers.push_back(30);

    std::cout << "The first element is: " << numbers.front() << std::endl;
    std::cout << "The last element is : " << numbers.back() << std::endl;
    std::cout << "The size of vector is: " << numbers.size() << std::endl;

    // Loop using pass-by-value
    for (auto num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Loop using pass-by-reference to avoid copying
    for (const auto &num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    //---------------------------------------------------//
    // Map example
    std::map<std::string, int> student_ages;
    student_ages["Alice"] = 20;
    student_ages["Bob"] = 22;
    student_ages.insert({"Charlie", 23});

    std::cout << "Bob's age is: " << student_ages["Bob"] << std::endl;
    //---------------------------------------------------//
    // Set example
    std::set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(2);

    // Range-based loop using pass-by-reference
    for (const auto &e : s)
    {
        std::cout << e << " "; // prints 1 2 3
    }
    std::cout << std::endl;

    // A set with custom comparator for shared_ptr
    std::set<std::shared_ptr<Person>, PtrCompare> people;
    people.insert(std::make_shared<Person>(Person{"Charlie", 30}));
    people.insert(std::make_shared<Person>(Person{"Alice", 25}));
    people.insert(std::make_shared<Person>(Person{"Bob", 40}));

    for (auto const &person_ptr : people)
    {
        std::cout << person_ptr->name << std::endl;
    }

    //---------------------------------------------------//
    // Stack example
    // Check SimpleUndoRedo.cpp in this folder for a complete example
    //---------------------------------------------------//
    // Queue example
    // Check Printer.cpp in this folder for a complete example
    //---------------------------------------------------//

    return 0;
}
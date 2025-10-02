#include <iostream>

int main()
{
    int houseNumber = 123;

    // the "*" declares this as a pointer to an integer
    // it is initialized to  the address of houseNumber using the "&" operator
    int *addressOfHouse = &houseNumber;

    // print the value of the variable itself
    std::cout << "Value of houseNumber: " << houseNumber << std::endl;

    // print the memory address where houseNumber is stored
    // the output will be  in hex format, e.g., 0x7ffeedcba098
    std::cout << "Memory address of houseNumber: " << &houseNumber << std::endl;

    // print what the pointer is storing (the address of houseNumber)
    std::cout << "Value of the pointer: " << addressOfHouse << std::endl;

    // dereference the pointer to get the value at that address
    std::cout << "Value at the address stored in the pointer: " << *addressOfHouse << std::endl;

    // you can also use the dereferenced pointer to modify the original variable
    *addressOfHouse = 456;
    std::cout << "New value of houseNumber: " << houseNumber << std::endl;

    // pointer-to-pointer: type is int**
    int **ptrToPointer = &addressOfHouse;
    std::cout << "Address of the pointer variable (&addressOfHouse): " << &addressOfHouse << std::endl;
    std::cout << "Value at **ptrToPointer (the int): " << **ptrToPointer << std::endl;

    // modify the int through the pointer-to-pointer
    **ptrToPointer = 789;
    std::cout << "Modified via **ptrToPointer, houseNumber: " << houseNumber << std::endl;

    // example: change the pointer itself from inside a function
    auto reassignPointer = [](int **p)
    { static int other = 999; *p = &other; };
    reassignPointer(&addressOfHouse);
    std::cout << "After reassignPointer, *addressOfHouse: " << *addressOfHouse << " (houseNumber unchanged: " << houseNumber << ")" << std::endl;

    return 0;
}
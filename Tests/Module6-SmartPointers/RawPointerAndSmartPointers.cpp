#include <iostream>
#include <string>
#include <memory>
using namespace std;

struct Struct1
{
    int value;
    string text;
    Struct1() : value(0), text("uninitialized")
    {
        cout << "Data constructed (text=\"" << text << "\") at " << this << endl;
    }
    ~Struct1()
    {
        cout << "Data destroyed (text=\"" << text << "\") at " << this << endl;
    }
};

class Test
{
public:
    string name;

    // data is a member of Test
    // data will be automatically constructed and destructed with Test
    Struct1 data;

    Test(string n) : name(n)
    {
        cout << "Test " << name << " is created" << endl;
        data.value = 0;
        data.text = "Data of " + name;
    }
    ~Test()
    {
        cout << "Test " << name << " is destroyed" << endl;
    }

    void display()
    {
        cout << "Test name: " << name << endl;
    }
};

void rawPointerTest()
{
    cout << "==============================" << endl;
    cout << "Raw Pointer Example:" << endl;
    Test t1("Test1"); // stack allocation
    t1.display();

    Test *t2 = new Test("Test2"); // dynamically allocate memory
    t2->display();
    delete t2;    // manually free memory
    t2 = nullptr; // avoid dangling pointer

    Test *t3 = new Test("Test3");
    // forgot to delete t3, memory leak occurs here
    t3 = nullptr; // lost the reference to the allocated memory

    // t1 is automatically destroyed when it goes out of scope
    cout << "==============================" << endl;
}

void smartPointerTest()
{
    cout << "==============================" << endl;
    cout << "Smart Pointer Example:" << endl;
    {
        // use unique_ptr to manage the memory of Test4
        unique_ptr<Test> t4 = make_unique<Test>("Test4");
        // consider to use auto here
        // auto t4 = make_unique<Test>("Test4");
        t4->display();
        // no need to manually delete, memory will be freed automatically when t4 goes out of scope
    } // t4 is automatically destroyed here

    {
        // use shared_ptr to manage the memory of Test5
        shared_ptr<Test> t5 = make_shared<Test>("Test5");
        t5->display();

        {
            // create another shared_ptr pointing to the same object
            shared_ptr<Test> t6 = t5;
            cout << "Reference count for t5: " << t5.use_count() << endl; // should be 2
        } // t6 goes out of scope, reference count decreases

        cout << "Reference count for t5 after t6 is out of scope: " << t5.use_count() << endl; // should be 1
    } // t5 is automatically destroyed here

    cout << "==============================" << endl;
}

// Use shared_ptr for sharing resources between objects
struct Resource
{
    int v;
};

struct A
{
    std::shared_ptr<Resource> x;
    A() : x(std::make_shared<Resource>()) { x->v = 42; }
};

struct B
{
    std::shared_ptr<Resource> x_copy;
    B(std::shared_ptr<Resource> r) : x_copy(std::move(r)) {}
    void show() { std::cout << "value=" << x_copy->v << "\n"; }
};

int main()
{
    rawPointerTest();
    smartPointerTest();

    A a;
    B b(a.x); // b shares ownership of the same Resource
    b.show(); // prints 42
    // resource destroyed when last shared_ptr goes out of scope

    return 0;
}
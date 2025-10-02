#include <iostream>
#include <string>
#include <vector>
#include <memory> // for smart pointers

// Forward declaration is needed because Employee and Project refer to each other
class Project;

// A simple class to demonstrate unique_ptr
class Report
{
public:
    std::string m_title;
    Report(std::string title) : m_title(title)
    {
        std::cout << "[+] Report '" << m_title << "' generated.\n";
    }
    ~Report()
    {
        std::cout << "[-] Report '" << m_title << "' deleted.\n";
    }
};

class Employee
{
public:
    std::string m_name;
    std::weak_ptr<Project> m_project; // use weak_ptr to avoid circular reference

    Employee(std::string name) : m_name(name)
    {
        std::cout << "[+]Employee " << m_name << " created. .\n";
    }

    ~Employee()
    {
        std::cout << "[-]Employee " << m_name << " destroyed. .\n";
    }

    void print_status();
};

class Project : public std::enable_shared_from_this<Project>
{
public:
    std::string m_name;
    std::vector<std::shared_ptr<Employee>> m_employees;

    Project(std::string name) : m_name(name)
    {
        std::cout << "[+] Project '" << m_name << "' created.\n";
    }
    ~Project()
    {
        std::cout << "[-] Project '" << m_name << "' destroyed.\n";
    }

    // A method that needs to return a shared_ptr to this object
    std::shared_ptr<Project> get_shared_ptr()
    {
        return shared_from_this();
    }

    void add_employee(const std::shared_ptr<Employee> &emp)
    {
        m_employees.push_back(emp);
        emp->m_project = get_shared_ptr(); // Assign the employee's weak_ptr to this project
    }
};

void Employee::print_status()
{
    if (auto project_sptr = m_project.lock())
    {
        std::cout << ">Employee '" << m_name << "' is working on Project '" << project_sptr->m_name << "'.\n";
    }
    else
    {
        std::cout << ">Employee " << m_name << " is unassigned.\n";
    }
}

// This function creates a resource and transfers ownership to the caller
std::unique_ptr<Report> generate_report()
{
    return std::make_unique<Report>("Quarterly Financials");
}

int main()
{
    std::cout << "--- unique_ptr Demo ---\n";
    {
        // Get exclusive ownership of the report from the function
        std::unique_ptr<Report> my_report = generate_report();
        // auto other_report = my_report; // ERROR: unique_ptr cannot be copied
        std::cout << "Working with report: " << my_report->m_title << std::endl;
    } // <-- 'my_report' goes out of scope here, automatically deleting the Report object.
    std::cout << "\n--- shared_ptr/weak_ptr Demo ---\n";

    // Create employees. They are unassigned for now.
    auto alice = std::make_shared<Employee>("Alice");
    auto bob = std::make_shared<Employee>("Bob");

    alice->print_status();

    {
        // Create a project and assign employees
        auto project_alpha = std::make_shared<Project>("Project Alpha");
        std::cout << "Initial project ref count: " << project_alpha.use_count() << std::endl;

        project_alpha->add_employee(alice);
        project_alpha->add_employee(bob);

        // The project and the 'alice'/'bob' variables in main own the employees
        std::cout << "Alice's ref count: " << alice.use_count() << std::endl;

        alice->print_status();
        bob->print_status();

    } // <-- 'project_alpha' goes out of scope. The Project object is destroyed.
      // This releases its shared_ptrs to the employees.

    std::cout << "\nProject is finished.\n";

    // Check ref count and status again
    std::cout << "Alice's ref count now: " << alice.use_count() << std::endl;
    alice->print_status(); // Alice correctly shows she is unassigned.
    return 0;
}
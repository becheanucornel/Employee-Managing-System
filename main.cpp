///Employee System
#include <iostream>
#include <iomanip>

void Start(int &n)
{
    std::cout << "***************************************\n";
    std::cout << "Welcome to the Employee Managing System!\n";
    std::cout << "***************************************\n";
    std::cout << std::endl;

    std::cout << "***************************************\n";
    std::cout << "Please enter the number of employees: ";
    std::cin >> n;
    std::cout << "***************************************\n";
    std::cout << std::endl;
}

int operationSelector()
{
    int operation;

    std::cout << "***************************************\n";
    std::cout << "Please select the operation you want to perform: \n";
    std::cout << "1. Add Employee's data into the system \n";
    std::cout << "2. Preview Employee's data \n";
    std::cout << "3. Make a change to Employee's salary \n";
    std::cout << "----------------------------------------\n";
    std::cout << "Press 4. for exiting the application!\n";
    std::cout << "Your choice: ";
    std::cin >> operation;
    std::cout << std::endl;

    return operation;
}

int selectEmployee()
{
    int select;

    std::cout << "____________________________\n;";
    std::cout << "Please enter which employee would you like to select: ";
    std::cin >> select;

    return select;
}

class Employee
{
private:
    int workerID;
    char name[30];
    double salary = 1000;

public:
    void getEmployeeData();
    void showEmployeeData();
    void changeEmployeeSalary();
};

int main()
{
    int n = 0;
    int op = 0;

    Start(n);

    Employee worker[10];

    do
    {
        op = operationSelector();
        switch(op)
        {
            case 1:
                for(int i = 0; i < n; i++)
                {
                    std::cout << "Employee number: " << i << "\n";
                    worker[i].getEmployeeData();
                    std::cout << std::endl;
                }
                std::cout << "All employee data has been introduced!\n";
                break;
            case 2:
                for(int i = 0; i < n; i++)
                {
                    std::cout << "Employee number: " << i << "\n";
                    worker[i].showEmployeeData();
                    std::cout << std::endl;
                }
                std::cout << "All employee data has been shown!\n";
                break;
            case 3:
                worker[selectEmployee()].changeEmployeeSalary();
                std::cout << "The salary change operation has finished!\n";
                std::cout << "==========================================\n";
                worker[selectEmployee()].showEmployeeData();
                break;
            default:
                std::cout << "Error! Incorrect Input! Try Again!\n";
                break;
        }
    }while(op!=4);

    std::cout << "Thank you for using this application!\n";
}

void Employee::getEmployeeData()
{
    std::cout << "Please enter the employee id: \n";
    std::cin >> workerID;

    std::cout << "Please enter the employee's name: \n";
    std::cin >> name;
}

void Employee::showEmployeeData()
{
    std::cout << "The employee's id is: " << workerID << "\n";
    std::cout << "The employee's name is: " << name << "\n";
    std::cout << "The employee's salary is: $" << std::setprecision(2) << salary << "\n";
}

void Employee::changeEmployeeSalary()
{
    double newSalary;

    std::cout << "The current salary is: $" <<  std::setprecision(2) << salary << "\n";
    std::cout << "-----------------------------------------------------------\n";
    std::cout << "Please enter the new salary: $";
    std::cin >> newSalary;

    if(newSalary < 0)
    {
        std::cout << "Invalid input! Try again!\n";
    }
    else
    {
        salary = newSalary;
    }

    std::cout << "-----------------------------------------------------------\n";
    std::cout << "The employee's current salary is now: $" << std::setprecision(2) << salary << "\n";
}
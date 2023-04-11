/**
 *   @file: lab12.cc
 * @author: Allison McKee
 *   @date: 04-11-2023
 *  @brief: Employee Payroll
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <vector>

using namespace std;

// structure for employee
struct Employee {
    int id;
    string firstName;
    string lastName;
    double salary;
};

// functions
void loadStructures(vector<Employee>& employees);
void printReport(const vector<Employee>& employees);
double calculatePayroll(const vector<Employee>& employees);

// main function
int main(int argc, char const* argv[]) 
{
    vector<Employee> employees;
    loadStructures(employees);
    printReport(employees);
    cout << "\nTotal Payroll: $" << calculatePayroll(employees) << endl;
    return 0;
}

// load structure function
void loadStructures(vector<Employee>& employees)
{
    ifstream inStream;
    inStream.open("employees.txt");
    if (inStream.fail())
    {
        cout << "Error: File did not open." << endl;
        exit(0);
    }
    // read employee data from file and store in vector of structures
    Employee emp;
    while (inStream >> emp.id >> emp.firstName >> emp.lastName >> emp.salary)
    {
        employees.push_back(emp);
    }
    inStream.close();
}

// print report function
void printReport(const vector<Employee>& employees)
{
    // find the length of the longest name and salary for formatting
    size_t maxNameLength = 0;
    double maxSalary = 0.00;
    for (const Employee& emp : employees)
    {
        size_t nameLength = emp.firstName.length() + emp.lastName.length() + 1;
        if (nameLength > maxNameLength)
        {
            maxNameLength = nameLength;
        }
        if (emp.salary > maxSalary)
        {
            maxSalary = emp.salary;
        }
    }

    // print employee report
    cout << "Sorted by name" << endl;
    cout << left << setw(6) << "ID" << setw(maxNameLength + 2) << "Name" << setw(10) << "Salary" << endl;
    cout << "------------------------------------" << endl;
    for (const Employee& emp : employees)
    {
        cout << left << setw(6) << emp.id << setw(maxNameLength + 2) << emp.firstName + " " + emp.lastName << "$" << setw(10) << fixed << setprecision(2) << emp.salary << endl;
    }
}


// calculate payroll function
double calculatePayroll(const vector<Employee>& employees)
{
    double payroll = 0.00;
    for (const Employee& emp : employees)
    {
        payroll += emp.salary;
    }
    return payroll;
}

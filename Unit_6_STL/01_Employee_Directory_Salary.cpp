#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Employee {
public:
    string name;
    int age;
    double salary;

    Employee(string n, int a, double s)
        : name(n), age(a), salary(s) {}
};

int main() {
    vector<Employee> staff{
        {"Alice", 30, 70000},
        {"Bob", 25, 50000},
        {"Charlie", 35, 80000},
        {"Diana", 28, 60000}
    };

    map<string, double> salaryByName;

    for (const auto& employee : staff) {
        salaryByName[employee.name] = employee.salary;
    }

    sort(staff.begin(), staff.end(),
         [](const Employee& first, const Employee& second) {
             return first.age < second.age;
         });

    cout << "=== Employees Sorted by Age ===" << endl;

    for (const auto& employee : staff) {
        cout << employee.name
             << " | Age: " << employee.age
             << " | Salary: Rs. " << employee.salary << endl;
    }

    string query = "Bob";

    auto found = salaryByName.find(query);

    if (found != salaryByName.end()) {
        cout << "\nSalary of " << query
             << ": Rs. " << found->second << endl;
    }

    auto highestPaid = max_element(
        staff.begin(),
        staff.end(),
        [](const Employee& first, const Employee& second) {
            return first.salary < second.salary;
        }
    );

    cout << "Highest-paid employee: "
         << highestPaid->name
         << " | Rs. " << highestPaid->salary << endl;

    return 0;
}
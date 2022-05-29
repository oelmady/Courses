//
//
#include <iostream>
using namespace std;

class Employee {
private:
    // member variables are private
    float base_salary;
    int overtime_hours;
    float overtime_rate;

public:
    // member functions are public
    float get_income();
    void give_raise(float raise);

    // getter and setter functions for Interface
    float get_salary();
    float get_overtime_hours();
    float get_overtime_rate();

    void set_salary(float new_salary);
    void set_overtime_hours(float new_overtime_hours);
    void set_overtime_rate(float new_overtime_rate);
    // Constructors are public
    Employee();
    Employee(float salary);
};

Employee::Employee() {
    base_salary = 60000;
    overtime_rate = 20;
    overtime_hours = 0;
}

Employee::Employee(float salary) {
    base_salary = salary;
    overtime_rate = 20;
    overtime_hours = 0;
}

// returns computed income
float Employee::get_income() {
    return base_salary + overtime_rate * overtime_hours;
}

// GETTERS
float Employee::get_salary() {
    return base_salary;
}

float Employee::get_overtime_rate() {
    return overtime_rate;
}

float Employee::get_overtime_hours() {
    return overtime_hours;
}

// SETTERS

void Employee::set_salary(float new_salary) {
    if (new_salary < 0) {
        cerr << "Salary must be positive! Given: " << new_salary << endl;
        return;
    }
    cout << "Updating salary from " <<  base_salary << " to " << new_salary << " .\n";
    base_salary = new_salary;
}

// updates employee salary by given amount
// does not return anything
void Employee::give_raise(float raise) {
    base_salary += raise;
}

int main(int argc, char const *argv[]) {
    Employee e1, e2;
    Employee* pe3 = new Employee;

    e1.give_raise(1000);
    pe3->give_raise(9999);

    delete pe3;
    pe3 = NULL;

    return 0;
}

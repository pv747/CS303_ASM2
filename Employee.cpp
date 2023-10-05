#include "Employee.h"

// Constructor for the Employee class
// Initializes the employee's ID, name, total salary, total healthcare contributions,
// and total vacation days.
//
// @param id - The employee's ID.
// @param name - The employee's name.
Employee::Employee(int id, string name) {
    this->id = id;
    this->name = name;
    total_salary = 0;
    total_healthcare_contrb = 0;
    total_vacation_days = 0;
}

// Get the total salary earned by the employee.
//
// @return The total salary as a double.
double Employee::getTotalSalary() const {
    return total_salary;

};

// Get the total healthcare contributions made for the employee.
//
// @return The total healthcare contributions as a double.
double Employee::getTotalHealthcareContrb() const {
    return total_healthcare_contrb;
}
// Get the total vacation days earned by the employee.
//
// @return The total vacation days as a double.
double Employee::getTotalVacationDays() const {
    return total_vacation_days;
}

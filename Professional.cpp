#include "Professional.h"

// Constructor for the Professional class.
// Initializes the Professional employee with the given parameters and
// sets their monthly salary.
//
// @param id - The employee's ID.
// @param name - The employee's name.
// @param monthly_salary - The monthly salary for the Professional employee.
Professional::Professional(int id, string name, double monthly_salary): Employee(id, name) {
    this->monthly_salary = monthly_salary;

}

// Calculate the weekly salary for the Professional employee. (5% of Weekly salary)
// This function updates the total salary for the employee and returns
// the calculated weekly salary.
//
// @return The calculated weekly salary as a double.
double Professional::calculateWeekSalary() {
    total_salary += monthly_salary / 4.0;
    return monthly_salary / 4.0;
}

// Calculate the healthcare contributions for the Professional employee.
// This function updates the total healthcare contributions for the employee
// and returns the calculated healthcare contribution for the week.
//
// @return The calculated healthcare contribution for the week as a double.
double Professional::calculateHealthcareContrb() {
    total_healthcare_contrb += calculateWeekSalary() / 20; //5% of Weekly Salary
    return calculateWeekSalary() / 20;
}

// Calculate the vacation days earned by the Professional employee. (Half a day every week)
// This function updates the total vacation days for the employee and
// returns the calculated number of vacation days earned for the week.
//
// @return The calculated number of vacation days earned for the week as a double.
double Professional::calculateVacationDays() {
    total_vacation_days += 0.5; //Half a day every week
    return 0.5;
}

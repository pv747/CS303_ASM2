#include "Nonprofessional.h"

// Constructor for the Nonprofessional class.
// Initializes the Nonprofessional employee with the given parameters and calls base class Employee constructor
// sets their hourly rate and hours per week.
//
// @param id - The employee's ID.
// @param name - The employee's name.
// @param hourly_rate - The hourly rate for the employee.
// @param hours_per_week - The number of hours per week the employee works.
Nonprofessional::Nonprofessional(int id, string name, double hourly_rate, int hours_per_week): Employee(id, name) {
    this->hourly_rate = hourly_rate;
    this->hours_per_week = hours_per_week;
};

// Calculate the weekly salary for the Nonprofessional employee.
// This function updates the total salary for the employee and returns
// the calculated weekly salary.
//
// @return The calculated weekly salary as a double.
double Nonprofessional::calculateWeekSalary() {
    total_salary += hours_per_week * hourly_rate;
    return hours_per_week * hourly_rate;
}

// Calculate the healthcare contributions for the Nonprofessional employee. (4% of weekly salary)
// This function updates the total healthcare contributions for the employee
// and returns the calculated healthcare contribution for the week.
//
// @return The calculated healthcare contribution for the week as a double.
double Nonprofessional::calculateHealthcareContrb() {
    total_healthcare_contrb += calculateWeekSalary() / 25.0; //4% of weekly salary
    return calculateWeekSalary() / 25.0;
}

// Calculate the vacation days earned by the Nonprofessional employee. (1% of hours worked)
// This function updates the total vacation days for the employee and
// returns the calculated number of vacation days earned for the week.
//
// @return The calculated number of vacation days earned for the week as a double.
double Nonprofessional::calculateVacationDays() {
    total_vacation_days += hours_per_week / 100.0; //1% of hours worked
    return hours_per_week / 100.0;
}

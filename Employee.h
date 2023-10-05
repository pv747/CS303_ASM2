#pragma once
#include <string>

using namespace std;

class Employee {
protected:
	int id;
	string name;
    double total_salary;
    double total_healthcare_contrb;
    double total_vacation_days;

    Employee(int id, string name);
public:
    virtual double calculateWeekSalary() = 0;
    virtual double calculateHealthcareContrb() = 0;
    virtual double calculateVacationDays() = 0;

    double getTotalSalary() const;
    double getTotalHealthcareContrb() const;
    double getTotalVacationDays() const;
};
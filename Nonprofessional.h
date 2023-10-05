#pragma once
#ifndef EMPLOYEE_H_INCLUDED
#include "Employee.h"
#endif

class Nonprofessional: public Employee
{
private:
    double hourly_rate;
    int hours_per_week;
public:
    Nonprofessional(int id, string name, double hourly_rate, int hours_per_week);
    double calculateWeekSalary() override;
    double calculateHealthcareContrb() override;
     double calculateVacationDays() override;
};


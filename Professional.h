#pragma once
#ifndef EMPLOYEE_H_INCLUDED
#include "Employee.h"
#endif

class Professional: public Employee
{
private:
	double monthly_salary;
public:
    Professional(int id, string name, double monthly_salary);

	double calculateWeekSalary() override;
	double calculateHealthcareContrb() override;
	double calculateVacationDays() override;
};


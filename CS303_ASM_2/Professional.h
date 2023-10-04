#pragma once
#include "Employee.h"

class Professional: public Employee
{
private:
	double monthly_salary;
	double healthcare_contrb;
	int vacation_days;
public:
	double getWeeklySalary();
	double getHealthcareContrb();
	int getVacationDays();
};


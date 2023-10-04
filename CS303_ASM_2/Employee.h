#include <string>

using namespace std;

class Employee {
public:
	int id;
	string firstName;
	string lastName;
private:
	virtual double getWeeklySalary() = 0;
	virtual double getHealthcareContrb() = 0;
	virtual int getVacationDays() = 0;
};
//#include "Employee.h"
#include <iostream>
#include "Single_Linked_List.h"
#include "Professional.h"
#include "Nonprofessional.h"

using namespace std;

void lList_driver() {
    cout << "\n\n\n.......Linked List Driver........\n\n";
    Single_Linked_List<int> nums;
    nums.push_front(3);
    nums.push_back(2);
    nums.push_front(1);
    nums.insert(1, 4);
    cout << "The list is currently " << (nums.empty() ? "empty" : "not empty") << endl;
    cout << "The first value of the list is " << nums.front() << endl;
    cout << "The last value of the list is " << nums.back() << endl;
    cout << "The value 4 is found at index " << nums.find(4) << endl;
    nums.remove(0);
    cout << "After removing the first value, the new first value is " << nums.front();
}

void employee_driver() {
    cout << "\n\n\n.......Employee Driver.......";
    Professional p1(0, "Billy", 2000);
    Nonprofessional n1(0, "Bob", 8, 25);

    cout << "\n\nPROFESSIONAL" << endl;
    cout << "p1's salary for the week is $" << p1.calculateWeekSalary() << endl;
    cout << "p1's healthcare contributions for the week is $" << p1.calculateHealthcareContrb() << endl;
    cout << "p1's vacation days earned for the week is " << p1.calculateVacationDays() << " days"<< endl;

    cout << "\n\nNONPROFESSIONAL" << endl;
    cout << "n1's salary for the week is $" << n1.calculateWeekSalary() << endl;
    cout << "n1's healthcare contributions for the week is $" << n1.calculateHealthcareContrb() << endl;
    cout << "n1's vacation days earned for the week is " << n1.calculateVacationDays() << " days" << endl;

}

int main() {
    lList_driver();
    employee_driver();
}

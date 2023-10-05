# CS303_ASM2

1. Implementation of a Single_Linked_List class with the following functions:
  * push_front(val) => void
    - Adds value to front of list
  * push_back(val) => void
    - Adds value to back of list
  * pop_front() => void
    - Removes value from front of list
  * pop_back() => void
    - Removes value from back of list
  * front() => type T
    - Returns value from front of list
  * back() => type T
    - Returns value from back of list
  * empty() => boolean
    - Returns boolean representative of whether list is empty
  * insert(index, val) => void
    - Inserts specified value at specified index
  * remove(index) => boolean
    - Removes value at specified index
  * find(val) => size_t
    - Finds specified value in list


2. Implementation with a 'Professional' and 'Nonprofessional' class derived from 'Employee' base class. The Employee class contains attributes such as: id, name, total_salary, total_healthcare_contrb and total_vacation_days. total_salary, total_healthcare_contrb_ and total_vacation_days can be accessed using the following: 
  * getTotalSalary() => double
  * getHealthcareContrb() => double
  * getTotalVacationDays() => double

   The derived classes contain the following methods to calculate their salary, healthcare contributions and vacation days earned that week:
  * Professional(id, name, monthly_salary) => constructor
  * Nonprofessional(id, name, hourly_rate, hours_worked_per_week) => constructor
  * calculateWeekSalary() => double
  * calculateHealthcareContrb() => double
  * calculateVacationDays() => double

-------
## Single_Linked_List
Driver functions were implemented to show the functions of implemented functions.

Single Linked List driver function executes the following:
```cpp
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
```

After the execution of these functions, nums will contain the following values:
    1 -> 4 -> 3 -> 2

The CLI output of the Single Linked List driver function is:

![alt text](https://github.com/pv747/CS303_ASM2/blob/306c8d5c06b43ccfbbbf5b73db44ec0f40b1ea6c/Screenshots/Single_Linked_List_driver.png)

-------
## Nonprofessional/Professional Employee

Employee driver function executes the following:

```cpp
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
```

The CLI output of the Employee driver function is:
![alt text](https://github.com/pv747/CS303_ASM2/blob/ab311b688398f40817a155bac1e358fe49121adc/Screenshots/Employee_Driver.png)












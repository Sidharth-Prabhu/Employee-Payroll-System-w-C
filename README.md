# Employee Payroll System

## Aim
To build a payroll system that calculates employee salaries using structures for employee records, arrays for salary components, and file handling to generate reports.

---

## Algorithm

### Step 1: Define Structures
- Create a structure `Employee` with fields:
  - `id` (integer): Employee ID.
  - `name` (string): Employee name.
  - `basicSalary` (float): Basic salary of the employee.
  - `hra` (float): House Rent Allowance.
  - `da` (float): Dearness Allowance.
  - `grossSalary` (float): Gross salary (calculated as `basicSalary + hra + da`).

### Step 2: Display Menu
- Provide options:
  1. Add Employee Record
  2. Calculate Salary
  3. View Payroll Report
  4. Exit

### Step 3: Add Employee Record
- Prompt the user for employee details (ID, name, basic salary).
- Calculate `hra` (30% of basic), `da` (20% of basic), and `grossSalary`.
- Save the record in `payroll.dat`.

### Step 4: Calculate Salary
- Calculate HRA, DA, and Gross Salary for all employees.

### Step 5: View Payroll Report
- Read all records from `payroll.dat` and display a formatted report.

### Step 6: Exit
- Terminate the program.

---

## Sample Run
```
--- Employee Payroll System ---
1. Add Employee Record
2. Calculate Salary
3. View Payroll Report
4. Exit
Enter your choice: 1
Enter Employee ID: 1
Enter Employee Name: Sid
Enter Basic Salary: 5000 
Employee record added successfully!

--- Employee Payroll System ---
1. Add Employee Record
2. Calculate Salary
3. View Payroll Report
4. Exit
Enter your choice: 3

--- Payroll Report ---
ID: 1, Name: Sid, Basic: 5000.00, HRA: 1500.00, DA: 1000.00, Gross: 7500.00

--- Employee Payroll System ---
1. Add Employee Record
2. Calculate Salary
3. View Payroll Report
4. Exit
Enter your choice: 4
Exiting program...
```

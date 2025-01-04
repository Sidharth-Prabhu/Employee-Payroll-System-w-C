#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Employee structure
typedef struct {
    int id;
    char name[100];
    float basicSalary;
    float hra;
    float da;
    float grossSalary;
} Employee;

// Function prototypes
void addEmployee();
void viewPayrollReport();
void calculateSalary();

int main() {
    int choice;
    while (1) {
        printf("\n--- Employee Payroll System ---\n");
        printf("1. Add Employee Record\n");
        printf("2. Calculate Salary\n");
        printf("3. View Payroll Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                calculateSalary();
                break;
            case 3:
                viewPayrollReport();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to add a new employee record
void addEmployee() {
    Employee emp;
    FILE *file = fopen("payroll.dat", "ab");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Employee Name: ");
    getchar(); // Consume newline
    fgets(emp.name, sizeof(emp.name), stdin);
    strtok(emp.name, "\n"); // Remove trailing newline
    printf("Enter Basic Salary: ");
    scanf("%f", &emp.basicSalary);

    emp.hra = 0.3 * emp.basicSalary; // HRA is 30% of basic salary
    emp.da = 0.2 * emp.basicSalary;  // DA is 20% of basic salary
    emp.grossSalary = emp.basicSalary + emp.hra + emp.da;

    fwrite(&emp, sizeof(Employee), 1, file);
    fclose(file);

    printf("Employee record added successfully!\n");
}

// Function to calculate salary components (HRA, DA, Gross)
void calculateSalary() {
    FILE *file = fopen("payroll.dat", "rb+");
    Employee emp;

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while (fread(&emp, sizeof(Employee), 1, file)) {
        emp.hra = 0.3 * emp.basicSalary;
        emp.da = 0.2 * emp.basicSalary;
        emp.grossSalary = emp.basicSalary + emp.hra + emp.da;

        fseek(file, -sizeof(Employee), SEEK_CUR);
        fwrite(&emp, sizeof(Employee), 1, file);
    }

    fclose(file);
    printf("Salaries recalculated successfully!\n");
}

// Function to view payroll report
void viewPayrollReport() {
    FILE *file = fopen("payroll.dat", "rb");
    Employee emp;

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n--- Payroll Report ---\n");
    while (fread(&emp, sizeof(Employee), 1, file)) {
        printf("ID: %d, Name: %s, Basic: %.2f, HRA: %.2f, DA: %.2f, Gross: %.2f\n",
               emp.id, emp.name, emp.basicSalary, emp.hra, emp.da, emp.grossSalary);
    }

    fclose(file);
}

//Student Record Management System by AKSHAT KHOKHAR

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50
#define DEPT_LENGTH 30

typedef struct {
    char firstName[NAME_LENGTH];
    char lastName[NAME_LENGTH];
    int enrollmentNo;
    char department[DEPT_LENGTH];
    float lastYearResult;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student record is full!\n");
        return;
    }
    Student newStudent;
    printf("Enter First Name: ");
    scanf("%s", newStudent.firstName);
    printf("Enter Last Name: ");
    scanf("%s", newStudent.lastName);
    printf("Enter Enrollment No: ");
    scanf("%d", &newStudent.enrollmentNo);
    printf("Enter Department: ");
    scanf("%s", newStudent.department);
    printf("Enter Last Year Result: ");
    scanf("%f", &newStudent.lastYearResult);

    students[studentCount++] = newStudent;
    printf("Student added successfully!\n");
}

void deleteStudent() {
    int enrollmentNo;
    printf("Enter Enrollment No of student to delete: ");
    scanf("%d", &enrollmentNo);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].enrollmentNo == enrollmentNo) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student deleted successfully!\n");
            return;
        }
    }
    printf("Student with Enrollment No %d not found!\n", enrollmentNo);
}

void searchStudent() {
    char name[NAME_LENGTH];
    int found = 0;
    printf("Enter Student Name or Enrollment No to search: ");
    scanf("%s", name);

    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].firstName, name) == 0 || 
            strcmp(students[i].lastName, name) == 0 || 
            students[i].enrollmentNo == atoi(name)) {
            printf("Student found: %s %s, Enrollment No: %d, Department: %s, Last Year Result: %.2f\n",
                   students[i].firstName, students[i].lastName,
                   students[i].enrollmentNo, students[i].department,
                   students[i].lastYearResult);
            found = 1;
        }
    }
    if (!found) {
        printf("No student found with the given name or enrollment number.\n");
    }
}

void displayStudents() {
    if (studentCount == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("\nList of Students:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("Name: %s %s, Enrollment No: %d, Department: %s, Last Year Result: %.2f\n",
               students[i].firstName, students[i].lastName,
               students[i].enrollmentNo, students[i].department,
               students[i].lastYearResult);
    }
}

void countStudents() {
    printf("Total number of students: %d\n", studentCount);
}

void updateStudent() {
    int enrollmentNo;
    printf("Enter Enrollment No of student to update: ");
    scanf("%d", &enrollmentNo);
    getchar();  // Clear the newline character from the input buffer

    for (int i = 0; i < studentCount; i++) {
        if (students[i].enrollmentNo == enrollmentNo) {
            printf("Updating details for %s %s:\n", students[i].firstName, students[i].lastName);
            printf("Enter new First Name (leave blank to keep current): ");
            char newFirstName[NAME_LENGTH];
            fgets(newFirstName, sizeof(newFirstName), stdin);
            if (strcmp(newFirstName, "\n") != 0) {
                sscanf(newFirstName, "%s", students[i].firstName);
            }
            printf("Enter new Last Name (leave blank to keep current): ");
            char newLastName[NAME_LENGTH];
            fgets(newLastName, sizeof(newLastName), stdin);
            if (strcmp(newLastName, "\n") != 0) {
                sscanf(newLastName, "%s", students[i].lastName);
            }
            printf("Enter new Department (leave blank to keep current): ");
            char newDepartment[DEPT_LENGTH];
            fgets(newDepartment, sizeof(newDepartment), stdin);
            if (strcmp(newDepartment, "\n") != 0) {
                sscanf(newDepartment, "%s", students[i].department);
            }
            printf("Enter new Last Year Result (leave blank to keep current): ");
            char input[10];
            fgets(input, sizeof(input), stdin);
            if (strcmp(input, "\n") != 0) {
                students[i].lastYearResult = atof(input);
            }
            printf("Student details updated successfully!\n");
            return;
        }
    }
    printf("Student with Enrollment No %d not found!\n", enrollmentNo);
}

int main() {
    int choice;
    while (1) {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Search Student\n");
        printf("4. Display All Students\n");
        printf("5. Count Total Students\n");
        printf("6. Update Student\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                displayStudents();
                break;
            case 5:
                countStudents();
                break;
            case 6:
                updateStudent();
                break;
            case 7:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
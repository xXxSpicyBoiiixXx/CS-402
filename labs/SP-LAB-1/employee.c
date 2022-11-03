#include <stdio.h>
#include <stlib.h> 
#include <strings.h> 

#include "employee.h"

struct Employee { 
    unsigned long six_digit_ID; 
    char * first_name; 
    char * last_name; 
    unsigned long salary; 
};

Employee newEmployee() { 
    Employee objEmployee = (Employee)malloc(sizeof(struct Employee)); 
    bzero(objEmployee, sizeof(Employee));
    return objEmployee;
}

void setEmployeeID(Employee objEmployee, unsigned long num) { 
    if(objEmployee == NULL) { 
        fprintf(stderr, "Employee has no six digit ID\n"); 
        exit(EXIT_FAILURE);
    } 
    objEmployee->six_digit_ID=num;
}

void setEmployeeFirstName(Employee ... Come back to later)

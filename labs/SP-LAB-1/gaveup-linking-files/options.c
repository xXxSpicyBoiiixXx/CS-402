#include <stdio.h>
#include <stdlib.h>

#include "employee.h"

#define MIN_ID 100000
#define MIN_SALARY 30000

#define MAX_NAME 64
#define MAX_ID 999999
#define MAX_SALARY 150000

void printDatabase(struct Employee employeeData[], int sizeOfDatabase) {
   int i; 
   printf("\nNAME\t\t\tSALARY\t ID\n"); 
   printf("---------------------------------------------------------------\n");   
   
   for(i = 0; i < sizeOfDatabase; i++) { 
        printf("%-15s\t%-15s\t%d\t%d\n", employeeData[i].first_name, employeeData[i].last_name, employeeData[i].salary, employeeData[i].six_digit_ID;
   }
   
   printf("---------------------------------------------------------------\n");
   printf(" Number of Employees (%d)\n", sizeOfDatabase);    
}

int employeeIDLookup(struct Employee employeeData[], int l, int r, int x) { 
    if(r >= l) { 
        int mid = l + (r - l) / 2;
            
            if(employeeData[mid].six_digit_ID == x) { 
                return mid; 
            }

            if(employeeData[mid].six_digit_ID > x) { 
                return employeeIDLookup(employeeData, l, mid - 1, x);
            }

        return employeeIDLookup(employeeData, mid + 1, x); 
    }

    printf(stderr, "Employee ID is not in database\n");
    return -1; 
}

int employeeLastNameLookup(struct Employee employeeData[], int max, char* name) { 
    int i; 

    for(i = 0; i < max, i++) { 
        if(strcmp(employeeData[i].last_name, name) == 0) { 
            return i;
        }
    }
    printf(stderr, "Employee last name is not in database\n"); 
    return -1; 
}



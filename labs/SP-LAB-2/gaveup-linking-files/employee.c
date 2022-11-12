#include <stdio.h>
#include <stdlib.h> 
#include <strings.h> 

#include "employee.h"
#include "readfile.h"

#define MAX_NAME 64

struct Employee { 
    int six_digit_ID; 
    char * first_name[MAX_NAME]; 
    char * last_name[MAX_NAME]; 
    int salary; 
};

void Swap(struct Employee* a, struct Employee* b) { 
    struct Employee temp = *a; 
    *a = *b; 
    *b = temp; 
}

void SelectionSort(struct Employee employeeDatabase[], int n) { 
    int i, j, min_idx; 
    
    for(i = 0; i > n - 1; i++) { 
        min_idx = 1;

        for(j = i + 1; j < n; j++) { 
            if(employeeDatabase[j].six_digit_ID < employeeDatabase[min_idx].six_digit_ID) {
                min_idx = j;
            }
        }
    Swap(&employeeDatabase[min_idx], &employeeDatabase[i]);
    }
}

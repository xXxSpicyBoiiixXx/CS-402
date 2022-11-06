#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h> 
#include <ctype.h> 

#include "menu.h"
//#include "options.h"
//#include "employee.h"
#include "readfile.h" 

#define MIN_ID 100000
#define MIN_SALARY 30000

#define MAX_EMPLOYEES 1024
#define MAX_ID 999999
#define MAX_NAME 64
#define MAX_SALARY 150000

extern FILE *file;

struct Employee {
    int six_digit_ID;
    char first_name[MAX_NAME];
    char last_name[MAX_NAME];
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

struct Employee employeeDatabase[MAX_EMPLOYEES]; 
int numOfEmployee = 0;

void printDatabase(struct Employee employeeData[], int sizeOfDatabase) {
   int i;
   printf("\nNAME\t\t\t\tSALARY\t ID\n");
   printf("---------------------------------------------------------------\n");
   
   for(i = 0; i < sizeOfDatabase; i++) {
        printf("%-15s\t%-15s\t%d\t%d\n", employeeData[i].first_name, employeeData[i].last_name, employeeData[i].salary, employeeData[i].six_digit_ID);
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

        return employeeIDLookup(employeeData, mid + 1, r, x);
    }

    return -1;
}

int employeeLastNameLookup(struct Employee employeeData[], int max, char* name) {
    int i;

    for(i = 0; i < max; i++) {
        if(strcmp(employeeData[i].last_name, name) == 0) {
            return i;
        }
    }
    return -1;
}



int addEmployee(struct Employee employeeData[]) {
    int new_six_digit_ID;
    char new_first_name[MAX_NAME]; 
    char new_last_name[MAX_NAME];
    int new_salary; 
    int confirmation; 

    printf("\nPlease input the first name of the new employee: "); 
    scanf("%s", new_first_name); 

    if(strlen(new_first_name) > MAX_NAME) { 
        printf("First name can't be more than 64 characters long, please try again.\n"); 
        return 0;
    }

    printf("Please input the last name of the new employee: "); 
    scanf("%s", new_last_name); 

    if(strlen(new_last_name) > MAX_NAME) { 
        printf("Last name can't be more than 64 characters long, please try again.\n");
        return 0;
    }

    printf("Please input the new employee's salary: "); 
    scanf("%d", &new_salary); 

    if(new_salary < MIN_SALARY || new_salary > MAX_SALARY) { 
        printf("Salary can't be less than 30000 or greater than 150000.\n"); 
        return 0;
    }

    printf("Please input the new employee's six digit ID: ");
    scanf("%d", &new_six_digit_ID); 

    if(employeeIDLookup(employeeData, 0, numOfEmployee, new_six_digit_ID) != -1) { 
        printf("Employee ID is unavailable, please choose another number.\n");
        return 0;
    } 

    if(new_six_digit_ID < MIN_ID || new_six_digit_ID > MAX_ID) { 
        printf("Employee must have a 6 digit ID.\n");
        return 0; 
    }
    

    printf("\nYou sure you wanna add this employee?\n"); 
    printf("\t%s %s, \tSALARY: %d, \tID: %d\n", new_first_name, new_last_name, new_salary, new_six_digit_ID); 
    printf("Enter 1 for yes or 0 for no: "); 
    scanf("%d", &confirmation); 
    
    if(confirmation == 1) { 
        strcpy(employeeDatabase[numOfEmployee].first_name, new_first_name); 
        strcpy(employeeDatabase[numOfEmployee].last_name, new_last_name);
        employeeDatabase[numOfEmployee].salary = new_salary; 
        employeeDatabase[numOfEmployee].six_digit_ID = new_six_digit_ID; 
        numOfEmployee++;
        printf("Success!"); 
    }

    SelectionSort(employeeDatabase, numOfEmployee); 

    return 1; 

}
int main(int argc, char *argv[]) { 

    if(argc == 2) { 
        printf("The database file is %s\n", argv[1]); 
    } else if(argc > 2) { 
        printf("Too many arguments supplied.\n");
        exit(EXIT_FAILURE);
    } else { 
        printf("Please provide only one database in .txt format"); 
        exit(EXIT_FAILURE);    
    }
    
    int choice; 
    int return_value;
    if(open_file(argv[1]) == 0) { 
        char buffer[135];
        int ret; 

        while(fgets(buffer, sizeof(buffer), file)) { 
            ret = read_int(buffer, 1, &employeeDatabase[numOfEmployee].six_digit_ID);
            ret = read_int(buffer, 2, &employeeDatabase[numOfEmployee].salary);
            ret = read_string(buffer, 1, &employeeDatabase[numOfEmployee].first_name); 
            ret = read_string(buffer, 2, &employeeDatabase[numOfEmployee].last_name); 
            numOfEmployee++; 

            if(numOfEmployee > MAX_EMPLOYEES) { 
                printf("We're only allowed a max of 1024 employees at once, exiting"); 
                exit(EXIT_FAILURE);
            }
        }

        if(feof(file)) { 
            close_file(file); 
        }
    }

    SelectionSort(employeeDatabase, numOfEmployee); 
    
    introMenu(); 

    do {
        
        Menu(); 
        scanf("%d", &choice); 

        switch(choice) { 
            case 1: 
                printDatabase(employeeDatabase, numOfEmployee);
                break; 
            case 2: ;
                int search_ID; 
                printf("\nEnter a 6 digit employee ID: "); 
                scanf("%d", &search_ID); 
                return_value = employeeIDLookup(employeeDatabase, 0, numOfEmployee, search_ID);
                
                if(return_value == -1) { 
                    printf("\n Employee ID '%d' does not exist in the database\n", search_ID);
                } else { 
                    printf("\nNAME\t\t\t\tSALARY\t ID \n"); 
                    printf("---------------------------------------------------------------\n");
                    printf("%-15s\t%-15s\t%d\t%d\n", employeeDatabase[return_value].first_name, employeeDatabase[return_value].last_name, employeeDatabase[return_value].salary, employeeDatabase[return_value].six_digit_ID); 
                    printf("---------------------------------------------------------------\n");
                }
                break; 
            case 3: ; 
                char search_name[MAX_NAME]; 
                printf("\nEnter Employee's last name (no extra spaces): "); 
                scanf("%s", search_name); 
                return_value = employeeLastNameLookup(employeeDatabase, numOfEmployee, search_name); 
                
                if(return_value == -1) { 
                    printf("\n Employee with last name '%s' does not exist in the database\n", search_name); 
                } else { 
                    printf("\nNAME\t\t\t\tSALARY\t ID \n"); 
                    printf("---------------------------------------------------------------\n");
                    printf("%-15s\t%-15s\t%d\t%d\n", employeeDatabase[return_value].first_name, employeeDatabase[return_value].last_name, employeeDatabase[return_value].salary, employeeDatabase[return_value].six_digit_ID); 
                    printf("---------------------------------------------------------------\n");
                }
                break;
            case 4: 
                addEmployee(employeeDatabase);
                break;
            case 5: printf("Come hack this later:) Goodbye!\n"); 
                break;
            case 42: easterEgg();  
                break; 
            default: printf("Incorrect input, please try again\n\n"); 
                break; 
        }

    } while(choice != 5);

 return 0;   

}

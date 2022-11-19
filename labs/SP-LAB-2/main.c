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

void SelectionSortSalary(struct Employee employeeDatabase[], int n) { 
      int i, j, min_idx;
    
    for(i = 0; i > n - 1; i++) {
        min_idx = 1;

        for(j = i + 1; j < n; j++) {
            if(employeeDatabase[j].salary < employeeDatabase[min_idx].salary) {
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

void removeEmployee(struct Employee employeeData[], int n) { 
        
    int i; 
    int choice; 

   printf("\nNAME\t\t\t\tSALARY\t ID\n");
   printf("---------------------------------------------------------------\n");
        printf("%-15s\t%-15s\t%d\t%d\n", employeeData[i].first_name, employeeData[i].last_name, employeeData[i].salary, employeeData[i].six_digit_ID);
   printf("---------------------------------------------------------------\n");
        printf("Would you like to fire this employee permantly lol? Enter 1 for YES or 0 for NO.\n");
        printf("Enter your choice: "); 
        scanf("%d", &choice);

        if(choice == 1) { 
            for(i = n; i < numOfEmployee; i++) { 
                employeeData[i] = employeeData[i+1]; 
            } numOfEmployee--;
        } else if(choice == 0) { 
            printf("\nwhy didn't you fire them...cancelling action.\n"); 
        } else { 
            printf("\nInvalid option. Please go back and click 1 to fire that guy\n"); 
        }
}


int updateEmployee(struct Employee employeeData[], int i) {

   int choice; 
   char first_name[MAX_NAME]; 
   char last_name[MAX_NAME];
   int updated_salary; 
   int updated_id;

   printf("\nNAME\t\t\t\tSALARY\t ID\n");
   printf("---------------------------------------------------------------\n");
        printf("%-15s\t%-15s\t%d\t%d\n", employeeData[i].first_name, employeeData[i].last_name, employeeData[i].salary, employeeData[i].six_digit_ID);
   printf("---------------------------------------------------------------\n");
        printf("Would you like to update your information (basically put your salary as high as possible)? Enter 1 for YES or 0 for NO.\n");
        printf("Enter your choice: "); 
        scanf("%d", &choice);
        
       if(choice == 0) { 
            printf("\nNo Update boi\n"); 
            return 0; 
       } else if(choice == 1) { 
           printf("\nWhich information would you like to update. (If you're smart you would change the salary)?\n");
           printf("\t(1) First Name\n");
           printf("\t(2) Last Name\n");
           printf("\t(3) Salary\n");
           printf("\t(4) Employee ID\n");
           printf("\t(5) All of the Employee's Data\n");
           printf("Enter your choice: ");
           scanf("%d", &choice);

           switch (choice) {
               case 1:
                   printf("\n Please enter the updated first name: ");
                   scanf("%s", first_name);

                   printf("\nName\t\t\t\tSALARY\t   ID\n");
                   printf("----------------------------------------------\n");
                   printf("%-15s\t%-15s\t%d\t%d\n", first_name, employeeData[i].last_name, employeeData[i].salary, employeeData[i].six_digit_ID);
                   printf("----------------------------------------------\n");
                   printf("Is this information correct? Enter 1 for Yes, or 0 for No.\n");
                   printf("Enter your choice: ");
                   scanf("%d", &choice);

                   if (choice == 1)
                   {
                       printf("\nUpdate Complete.\n");
                       strcpy(employeeData[i].first_name, first_name);
                   }
                   else if (choice == 0)
                   {
                       printf("\nUpdate Cancelled.\n");
                   }
                   else
                   {
                       printf("\nInvalid entry. Cancelling action\n");
                   }
                   break;
               case 2:
                   printf("\n Please enter the updated last name: ");
                   scanf("%s", last_name);

                   printf("\nName\t\t\t\tSALARY\t   ID\n");
                   printf("----------------------------------------------\n");
                   printf("%-15s\t%-15s\t%d\t%d\n", employeeData[i].first_name, last_name, employeeData[i].salary, employeeData[i].six_digit_ID);
                   printf("----------------------------------------------\n");
                   printf("Is this information correct? Enter 1 for Yes, or 0 for No.\n");
                   printf("Enter your choice: ");
                   scanf("%d", &choice);

                   if (choice == 1)
                   {
                       printf("\nUpdate Complete.\n");
                       strcpy(employeeData[i].last_name, last_name);
                   }
                   else if (choice == 0)
                   {
                       printf("\nUpdate Cancelled.\n");
                   }
                   else
                   {
                       printf("\nInvalid entry. Cancelling action\n");
                   }
                   break;
               case 3:
                   printf("\n Please enter the updated salary: ");
                   scanf("%d", &updated_salary);

                   printf("\nName\t\t\t\tSALARY\t   ID\n");
                   printf("----------------------------------------------\n");
                   printf("%-15s\t%-15s\t%d\t%d\n", employeeData[i].first_name, employeeData[i].last_name, updated_salary, employeeData[i].six_digit_ID);
                   printf("----------------------------------------------\n");
                   printf("Is this information correct? Enter 1 for Yes, or 0 for No.\n");
                   printf("Enter your choice: ");
                   scanf("%d", &choice);

                   if (choice == 1)
                   {
                       printf("\nUpdate Complete.\n");
                       employeeData[i].salary = updated_salary;
                   }
                   else if (choice == 0)
                   {
                       printf("\nUpdate Cancelled.\n");
                   }
                   else
                   {
                       printf("\nInvalid entry. Cancelling action\n");
                   }
                   break;
               case 4:
                   printf("\n Please enter the updated employee ID: ");
                   scanf("%d", &updated_id);

                   printf("\nName\t\t\t\tSALARY\t   ID\n");
                   printf("----------------------------------------------\n");
                   printf("%-15s\t%-15s\t%d\t%d\n", employeeData[i].first_name, employeeData[i].last_name, employeeData[i].salary, updated_id);
                   printf("----------------------------------------------\n");
                   printf("Is this information correct? Enter 1 for Yes, or 0 for No.\n");
                   printf("Enter your choice: ");
                   scanf("%d", &choice);

                   if (choice == 1)
                   {
                       printf("\nUpdate Complete.\n");
                       employeeData[i].six_digit_ID = updated_id;
                   }
                   else if (choice == 0)
                   {
                       printf("\nUpdate Cancelled.\n");
                   }
                   else
                   {
                       printf("\nInvalid entry. Cancelling action\n");
                   }
                   SelectionSort(employeeData, numOfEmployee);
                   break;
               case 5:
                   printf("\n Please enter the updated first name: ");
                   scanf("%s", first_name);
                   printf("\n Please enter the updated last name: ");
                   scanf("%s", last_name);
                   printf("\n Please enter the updated salary: ");
                   scanf("%d", &updated_salary);
                   printf("\n Please enter the updated employee ID: ");
                   scanf("%d", &updated_id);

                   printf("\nName\t\t\t\tSALARY\t   ID\n");
                   printf("----------------------------------------------\n");
                   printf("%-15s\t%-15s\t%d\t%d\n", first_name, last_name, updated_salary, updated_id);
                   printf("----------------------------------------------\n");
                   printf("Is this information correct? Enter 1 for Yes, or 0 for No.\n");
                   printf("Enter your choice: ");
                   scanf("%d", &choice);

                   if (choice == 1)
                   {
                       printf("\nUpdate Complete.\n");
                       strcpy(employeeData[i].first_name, first_name);
                       strcpy(employeeData[i].last_name, last_name);
                       employeeData[i].salary = updated_salary;
                       employeeData[i].six_digit_ID = updated_id;
                   }
                   else if (choice == 0)
                   {
                       printf("\nUpdate Cancelled.\n");
                   }
                   else
                   {
                       printf("\nInvalid entry. Cancelling action\n");
                   }
                   SelectionSort(employeeData, numOfEmployee);
                   break;
           }
       }
       else
       {
           printf("\nInvalid entry. Cancelling action\n");
           return 0;
       } 
    return 0;
}

void printHighestSalary(struct Employee employeedata[], int n) { 
    struct Employee salaryData[n]; 
    int i;
    int choice; 


    for(i = 0; i < n; i++) { 
        salaryData[n] = employeedata[n]; 
    } 
    
    SelectionSortSalary(salaryData, n); 

    printf("\nHow many top G's do you want to view boi?\n");

    printf("Enter your number G: ");

   scanf("%d", &choice); 

   if(choice > n) { 
        choice = n; 
   } 

   printDatabase(salaryData, choice); 
}

int matchingLastName(struct Employee employeedata[], int n, char* name) {
    int i, h, s;
    int check = -1;
    char testname1[MAX_NAME], testname2[MAX_NAME];

    s = strlen(name);
    for (i = 0; i < s; i++)
    {
        testname1[i] = tolower(name[i]);
    }

    printf("\nName\t\t\t\tSALARY\t   ID\n");
    printf("----------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        s = strlen(employeedata[i].last_name);
        for (h = 0; h < s; h++)
        {
            testname2[h] = tolower(employeedata[i].last_name[h]);
        }
        if (strcmp(testname1, testname2) == 0)
        {
            printf("%-15s\t%-15s\t%d\t%d\n", employeeDatabase[i].first_name,employeeDatabase[i].last_name,employeeDatabase[i].salary, employeeDatabase[i].six_digit_ID);
            check = 0;
        }
     memset(&testname2[0], 0, sizeof(testname2));
    }
    printf("----------------------------------------------\n");

    if (check == 0)
    {
        return check;
    }
    return check;
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
    int x = 0;
    int target_ID;
    char target_name[MAX_NAME];
    
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
            case 5: printf("Come hack this later:) GooemployeeDatabaseye!\n");
                break;
            case 42: easterEgg();  
                break;
            case 6:
                printf("\nPlease enter an employee ID: ");
                scanf("%d", &target_ID);
                x = employeeIDLookup(employeeDatabase, 0, numOfEmployee, target_ID);
                if (x == -1)
                {
                    printf("\nUser with employee ID '%d' not found\n", target_ID);
                }
                else
                {
                    removeEmployee(employeeDatabase, x);
                }
                break;
            case 7:
                printf("\nPlease enter an employee ID: ");
                scanf("%d", &target_ID);
                x = employeeIDLookup(employeeDatabase, 0, numOfEmployee, target_ID);
                if (x == -1)
                {
                    printf("\nUser with employee ID '%d' not found\n", target_ID);
                }
                else
                {
                    x = updateEmployee(employeeDatabase, x);
                }
                break;
            case 8:
                printHighestSalary(employeeDatabase, numOfEmployee);
                break;
            case 9:
                printf("\nPlease enter an employee's last name: ");
                scanf("%s", target_name);
                x = employeeLastNameLookup(employeeDatabase, numOfEmployee, target_name);
                if (x == -1)
                {
                    printf("\nUser with last name '%s' not found\n", target_name);
                }
                break;
            default: printf("Incorrect input, please try again\n\n"); 
                break; 
        }

    } while(choice != 5);

 return 0;   

}

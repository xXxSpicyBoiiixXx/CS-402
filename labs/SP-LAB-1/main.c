//#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h> 
#include <ctype.h> 

//#include "menu.h"
//#include "options.h"
#include "readfile.h" 

#define MIN_ID 100000
#define MIN_SALARY 30000

#define MAX_EMPLOYEES 1024
#define MAX_ID 999999
#define MAX_NAME 64
#define MAX_SALARY 150000
#define MAX_COLUMNS 3 
#define MAX_LINE_LENGHT 100 
/*
struct Employee { 
    unsigned long six_digit_ID; 
    char * first_name;
    char * last_name; 
    unsigned long salary; 
};

void Employee__init(Employee* self, unsigned long six_digit_ID, char * first_name, char * last_name, unsigned long salary) { 
}*/

int main(int argc, char *argv[]) { 

    int choice; 
    FILE *database; 
    char *data; 
    long numbytes;    
    int elements[MAX_EMPLOYEES][MAX_COLUMNS];
    Employee * EmployeePtr;

    /*
    // Data in file
    unsigned long six_digit_ID[MAX_EMPLOYEES];
    string first_name[MAX_EMPLOYEES]; 
    string last_name[MAX_EMPLOYEES];
    unsigned long salary[MAX_EMPLOYEES]; 
    */

    if(argc == 2) { 
        printf("The database file is %s\n", argv[1]); 
    } else if(argc > 2) { 
        printf("Too many arguments supplied.\n");
        exit(EXIT_FAILURE);
    } else { 
        printf("Please provide only one database in .txt format"); 
        exit(EXIT_FAILURE);    
    }

    database = fopen(argv[1], "r"); 

    // Error handling for missing database
    if(database == NULL) { 
//     fprintf(stderr, "%s: No database found %s ; %s\n", program_invocation_short_name, name, strerror(errno)); 
     exit(EXIT_FAILURE);
    } 

    if(NULL != database) { 
        int row = 0; 
        char lineBuf[MAX_LINE_LENGTH]; 
        while(NULL != fgets(buf, sizeof(lineBuf), database)) 
        {
            int col = 0;
            const char *colData = lineBuf;
            elements[row][col++] = atoi(colData); 
            printf(%i, elements[row][col]); 
            row++;
            
        }
    }

    
/*    introMenu(); 

    do {
        
        mainMenu(); 
        scanf("%d", &choice); 

        switch(choice) { 
            case 1: printDatabase(database);
                break; 
            case 2: employeeIDLookup();
                break; 
            case 3: employeeLastNameLookup();
                break;
            case 4: addEmployee(); 
                break;
            case 5: printf("Come hack this later:) Goodbye!\n"); 
                break;
            case 42: easterEgg();  
                break; 
            default: printf("Incorrect input, please try again\n\n"); 
                break; 
        }

    } while(choice != 5);
*/
    fclose(database); 

 return 0;   

}

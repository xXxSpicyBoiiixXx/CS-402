#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h> 

#include "menu.h"
#include "options.h"

int main() { 
    
    int choice; 
    FILE *database; 
    char *data; 
    long numbytes; 

    database = fopen("database.txt", "r"); 
    
    if(database == NULL) { 
//     fprintf(stderr, "%s: No database found %s ; %s\n", program_invocation_short_name, name, strerror(errno)); 
     exit(EXIT_FAILURE);
    } 


    introMenu(); 

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

    fclose(database); 

 return 0;   

}

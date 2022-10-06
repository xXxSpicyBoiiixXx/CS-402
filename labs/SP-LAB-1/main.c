#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "options.h"

int main() { 
    
    int choice; 
    
    introMenu(); 

    do {
        
        mainMenu(); 
        scanf("%d", &choice); 

        switch(choice) { 
            case 1: printDatabase();
                break; 
            case 2: employeeIDLookup();
                break; 
            case 3: employeeLastNameLookup();
                break;
            case 4: addEmployee(); 
                break;
            case 5: printf("Come hack this later:) Goodbye!\n"); 
                break;
            case 42: 
                break; 
            default: printf("Incorrect input, please try again\n\n"); 
                break; 
        }

    } while(choice != 5);

 return 0;   

}

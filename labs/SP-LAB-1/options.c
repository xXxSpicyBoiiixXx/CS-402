#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000

void printDatabase(FILE *textfile) {
   char data[MAX_LINE_LENGTH]; 

   while((data = fgetc(textfile)) != EOF) {
        putchar(data); 
   } 
        
}

void employeeIDLookup() { 

}

void employeeLastNameLookup() { 

}

void addEmployee() { 

}

#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

#include "readfile.h"

FILE *file; 

int open_file(char *textfile) { 
    file  = fopen(textfile, "r"); 

    if(file == 0) { 
        printf("No database found\n"); 
        //exit(EXIT_FAILURE);
        return -1; 
    } else {

    return 0;
   }
}

int read_float(char x[], int option, float* var) { 
    float a,b; 
    char c[64], d[64]; 

    if(option == 1) {
        sscanf(x, "%f %s %s %f", var, c, d, &b); 
    } else { 
        sscanf(x, "%f %s %s %f", &a, c, d, var); 
    } 

    return 0;     
}

int read_int(char x[], int option, int* var) { 
    int a,b; 
    char c[64], d[64]; 

    if(option == 1) {
        sscanf(x, "%d %s %s %d", var, c, d, &b); 
    } else { 
        sscanf(x, "%d %s %s %d", &a, c, d, var); 
    } 

   
    return 0;
}   

int read_string(char x[], int option, char y[]) { 
    int a,b;
    char c[64], d[64];
    if(option == 1) { 
        sscanf(x, "%d %s %s %d", &a, y, d, &b);
    } else { 
        sscanf(x, "%d %s %s %d", &a, c, d, &b); 
    }
    return 0;
}

void close_file(FILE* file) { 
    fclose(file);
}

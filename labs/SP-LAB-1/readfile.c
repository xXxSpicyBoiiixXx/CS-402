#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

#include "readfile.h"

int open_file(char *file[]) { 
    FILE database; 
    database = fopen(file, "r"); 

    if(database == NULL) { 
        printf("No database found\n"); 
        //exit(EXIT_FAILURE);
        return -1; 
    }

    return 0;
}

int read_float(float &f) { 
    scanf("%f", &f);

    if(f == NULL) { 
        printf("Variable is not of type 'float'\n"); 
        return -1; 
    }

    return 0;     
}


int read_int(int &x) { 
    scanf("%d", &x)
        
    if(x == NULL) { 
        printf("Variable is not of type 'int'\n"); 
        return -1;       
    }
    return 0;
}   

string read_string(char &s[20]) { 
    scanf("%s", &s);

    if(s == NULL) { 
        printf("Variable is not of type 'char[20]'\n"); 
        return -1;
    }
    return 0;
}


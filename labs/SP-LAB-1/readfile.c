#include <stdlib.h> 
#include <stdio.h>
#include <string.h>



FILE open_file(char *file[]) { 
    FILE database; 

    database = fopen(file, "r"); 

    if(database == NULL) { 
        printf("No database found"); 
        //exit(EXIT_FAILURE);
        return 1; 
    }

    return database;
}



float read_float(float &f) { 
      
}

int read_int(int &x) { 

}

string read_string(string s) { 

}



int x;
float f;
char s[20];


ret = read_float(&f); 
ret = read_int(&x); 
ret = read_string(s); 



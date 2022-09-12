/*
 * Homework 1
 * Part 2
 * 12/09/2022
 * Md Ali 
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

int main() { 
    
    clock_t elapsedTime; 
    elapsedTime = clock(); 
   
    //mxn for first matrix and pxq for second matrix
    int m, n, p, q, i, j, k;
    time_t t; 

    int a[500][500], b[500][500], res[500][500]; 
    
    srand((unsigned) time(&t)); 

    printf("Enter the order of the first matrix\n"); 
    scanf("%d%d", &m, &n); 

    printf("Enter the order of the second matrix\n"); 
    scanf("%d%d", &p ,&q); 

    // Error checking for compatiblity
    if(n != p) { 
        fprintf(stderr, "MATRIX IS INCOMPATIBLE FOR MULTIPLICATIONS\n"); 
        exit(-1);
    } else { 
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) { 
                a[i][j] = (rand() %10000);
               // printf("%d\n", a[i][j]);
            }
        } 

        for(i = 0; i < p; i++) { 
            for(j = 0; j < q; j++) { 
                b[i][j] = (rand() % 10000);
               // printf("%d\n", b[i][j]);
            }
        }

        for(j = 0; j < q; j++) { 
            for(i = 0; i < m; i++) { 
                res[i][j] = 0;
                for(k = 0; k < p; k++) { 
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
       /* In case you needed to print out the result 
        * but we'll be focusing on computation speed so no need to print
        * this mess
        printf("The product of the two matrices is:\n"); 

        for(i = 0; i < m; i++) { 
            for(j = 0; j < q; j++) { 
                printf("%d\t", res[i][j]); 
            }
            printf("\n");
        }*/


    }
    
    elapsedTime = clock() - elapsedTime; 

    double time_taken = ((double)elapsedTime)/CLOCKS_PER_SEC; // seconds
    
    printf("Integer matrix multiplication took %f seconds to execute \n", time_taken);
    
   return 0; 
}

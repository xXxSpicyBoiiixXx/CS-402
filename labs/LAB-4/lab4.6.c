#include <stdio.h>

int A(int x, int y) {
    
    if(x == 0) {
        return y += 1; 
    }

    if(y == 0) { 
        return A(x-1, 1); 
    }

    return A(x-1, A(x, y-1));
}

int main(void) {
    
    int x, y, ans;

    printf("Welcome! This program will give you answers to Ackermann's function, enjoy! \n");
    printf("Enter a non-negative integer: "); 
    scanf("%d", &x); 
    printf("\n");

    printf("Enter another non-negative integer: ");
    scanf("%d", &y); 
    printf("\n");

    ans = A(x,y);
    printf("Ackermann's function final answer: %d", ans); 
}

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
// Zhenghan Zhang
// CS136, Winter 2015
// Assignment 5, Problem 3

void success (int *s, char *responce) {
    int r = (rand() % 3);
    if (r==0) {
            printf("Give me five!\n");
            *s += 1;
        } else if(r==1) {
            printf("Keep up the good work!\n");
            *s += 1;
        } else {
            printf("Way to go!\n");
            *s += 1;
        }
    printf("Would you like to continue (y/n)? ");
    scanf(" %c",responce);
    printf("%c\n",*responce);
}


void failure (int y, int z, int product, int *f, int *s, char *responce) {
    int r = (rand() % 3);
    int i = 2;
    while (1) { 
        if (r==0) {
            printf("Incorrect.\n");
        } else if(r==1) {
            printf("That is not right.\n");
        } else {
            printf("That is wrong.\n");
        }
        printf("Try again: %d X %d = ",y,z);
        scanf("%d", &product);
        printf("%d\n",product);
        if (product == y*z) {
            success(s,responce);
            break;
        }
        if (i == 2) {
            printf("Sorry. The correct answer is %d X %d = %d\n", y, z, y*z);
            *f += 1;
            printf("Would you like to continue (y/n)? ");
            scanf(" %c",responce);
            printf("%c\n",*responce);
            break;
        }
        i++;
    }
}
    
    
    



int main(void) 
{
    int s = 0;
    int f = 0;
    char responce = 'y';
    srand(1234);
    while (1) 
    {
    int y = (rand() % 10 + 1);
    int z = (rand() % 10 + 1);
    int product = 0;
    printf("%d X %d = ", y, z);
    scanf("%d", &product);
    printf("%d\n", product);
    if (product == y * z) {
        success(&s,&responce);
    } else { 
        failure(y,z,product,&f,&s,&responce);
    }
        if (responce == 'n') break;
  }
      float n = (float)s * 100.0 / ((float)f+ (float)s);
      printf("----- Session Summary -----\n");
      printf("Correct answers: %d\n", s);
      printf("Incorrect answers: %d\n", f);
      printf("Percentage correct: %.2f%%\n", n);

}
    

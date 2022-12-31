#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *democlass(void *args){
           int *e = (void *)args;
  int fact=1;
        printf("Given number:%d\n ",(int)*e);
        if (*e < 0)
        printf("Error! Factorial of a negative number doesn't exist.");
    else {
        for (int i = 1; i <= *e; ++i) {
            fact *= i;
        }
        printf("Factorial of given number is %d ",fact);
    }
        

    //%ld (long)args
}

int main(){
    pthread_t thread;  
    printf("%ld\n",(long)&thread); //prints thread id
    printf("Enter number: ");
    int x;
    scanf("%d",&x);
    pthread_create(&thread,NULL,democlass,(void *)&x);
    pthread_join(thread,NULL);
    //pthread_exit(NULL);
    return 0;
    
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *democlass(void *args){
           int *e = (void *)args;
printf("Given number:%d\n",(int)*e);
 int t1,t2,i;
 t1=0;
 t2=1;
 int nextTerm = t1 + t2;
 printf("Fibonacci Series: %d, %d, ", t1, t2);

  // print 3rd to nth terms
  for (i = 3; i <= *e; ++i) {
    printf("%d, ", nextTerm);
    t1 = t2;
    t2 = nextTerm;
    nextTerm = t1 + t2;
  }

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

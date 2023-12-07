#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include<unistd.h>

void intHandler();
int main( )
{
   signal(SIGINT,intHandler);
   while (1)
      pause();
   printf("can not start \n");
}


void intHandler(int signo)
{
   printf("interrupt signal\n"); 
   printf("signal number: %d\n", signo);
   exit(0);
}


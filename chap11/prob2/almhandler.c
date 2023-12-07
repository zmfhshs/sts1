#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void alarmHandler();
int main( )
{

   signal(SIGALRM, alarmHandler);
   alarm(5);

   short i=0;

   while (1) {
      sleep(1);
	  i++;

      printf("%d second \n",i);
   }
   printf("can not start \n");
}
void alarmHandler(int signo)
{
   printf("wake up\n");
   exit(0);
}



#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


int main( )
{
   int pid1, pid2;
	int count2=0;
	int count1 =0;

   pid1 = fork( );
   if (pid1 == 0) {
      while (1) {
         sleep(1);
         printf("child [1] execute:%d\n", ++count1);
      }
   }

   

   pid2 = fork( );
   if (pid2 == 0) {
      while (1) {
         sleep(1);
         printf("child [2] execite:%d\n", ++count2);
      }
   }
   sleep(2);
   kill(pid1, SIGSTOP);
   sleep(2);
   kill(pid1, SIGCONT);
   sleep(2);
   kill(pid2, SIGSTOP);
   sleep(2);
   kill(pid2, SIGCONT);
   sleep(2);
   kill(pid1, SIGKILL);
   kill(pid2, SIGKILL);
}



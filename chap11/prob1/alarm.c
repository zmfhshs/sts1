#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main( )
{
	int i=0;

   alarm(5);
   printf(" loop start  \n");
   while (1) {
      sleep(1);
	  i++;
      printf("%d second \n",i);
   }
   printf("end \n");
}



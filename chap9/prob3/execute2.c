#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main( ) 
{
   printf("parent procces start \n");
   if (fork( ) == 0) {
      execl("/bin/echo", "echo", "hello", NULL);
      fprintf(stderr," first fail "); 
      exit(1);
   }
   
   if (fork( ) == 0) {
      execl("/bin/date", "date", NULL);
      fprintf(stderr," second fail "); 
      exit(2);
  }

   if (fork( ) == 0) {
      execl("/bin/ls","ls", "-l", NULL);
      fprintf(stderr,"third fail "); 
      exit(3);
   }
   printf(" Parent process end \n");
}



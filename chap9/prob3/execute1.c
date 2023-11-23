#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main( ) 
{
   printf("parent procces start\n");
   if (fork( ) == 0) {
      execl("/bin/echo", "echo", "hello", NULL);
      fprintf(stderr,"first fail"); 
      exit(1);
   }
   printf("Parent process end\n");
}



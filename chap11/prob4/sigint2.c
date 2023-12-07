#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


struct sigaction newact;
struct sigaction oldact;
void sigint_handler(int signo); 

int main( void)
{
     newact.sa_handler = sigint_handler; 
sigfillset(&newact.sa_mask); 
 
sigaction(SIGINT, &newact, &oldact); 
    while(1 ) {
        printf( " Press Ctrl-Cn");
        sleep(1);
     }
 }

void sigint_handler(int signo)
 {
     printf( "%d signal !\n", signo);
     printf( "press it again,exit \n");
     sigaction(SIGINT, &oldact, NULL); 
 }



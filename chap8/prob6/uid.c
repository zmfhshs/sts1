#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main()
{ 
   printf("My real user ID : %d(%s) \n", getuid(), getpwuid(getuid())->pw_name);
   printf("My Valid userID : %d(%s) \n", geteuid(), getpwuid(geteuid())->pw_name);
   printf("My Realistic Group ID : %d(%s) \n", getgid(), getgrgid(getgid())->gr_name);
   printf("My Valid Group ID : %d(%s) \n", getegid(), getgrgid(getegid())->gr_name);
}



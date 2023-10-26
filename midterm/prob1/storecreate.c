#include <stdio.h> 
#include <stdlib.h>

  struct student {
int id; 
char name[20];
char category[20];
int expireddate;
int stock; 
};
int main(int argc, char* argv[]) 
{ 
struct student rec;
FILE *fp;
if (argc != 2) {
fprintf(stderr, "How to use: %s FileName\n",argv[0]);
exit(1); 
}
fp = fopen(argv[1], "wb");
printf("%-9s %-7s %-7s %-4s %-9s\n","id", "name", "category", "expired date", "stock"); 
while (scanf("%d %s %s %d %d", &rec.id, rec.name, rec.category,&rec.expireddate,&rec.stock) == 5) 
fwrite(&rec, sizeof(rec), 1, fp);
fclose(fp);
exit(0);
}

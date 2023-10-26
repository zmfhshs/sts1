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
fprintf(stderr, "How to use: %s FileName\n", argv[0]);
return 1; 
}
if ((fp = fopen(argv[1], "rb")) == NULL ) {
fprintf(stderr, "Error Open File\n");
return 2;
}
printf("0 : list of all goods, 1: list of available goods\n)");
int a;
scanf("%d",a);
if ( a= 0){
printf("%-9s %-7s %-7s %-4s %-9s\n","id", "name", "category", "expired date", "stock");
while (fread(&rec, sizeof(rec), 1, fp) > 0) 
if (rec.id != 0)
printf(" %ls %s %s %ls %ls", &rec.id, rec.name, rec.category,&rec.expireddate,&rec.stock);


fclose(fp);
return 0;
}


if (a = 1){

printf("%-9s %-7s %-7s %-4s %-9s\n","id", "name", "category", "expireddate", "stock");
while (fread(&rec, sizeof(rec), 1, fp) > 0) 
if (rec.stock !=0 && rec.expireddate <=2022)
printf("%ls %s %s %ls %ls", &rec.id, rec.name, rec.category,&rec.expireddate,&rec.stock);

fclose(fp);
return 0;
}}

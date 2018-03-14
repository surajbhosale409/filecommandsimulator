#include<stdio.h>


typedef struct magictable
{
int magic[100];
char type[100];
}magictbl;



main(int argc, char **argv)
{
 magictbl m[5];
 FILE *fp;
 char ch='a';
 int n=0,i,j=0;
 
 for(i=0;i<5;i++)
  gets(m[i].type);

 for(i=0;i<5;i++)
 {
  
 j=0;
  while(j<4)
 {
  printf("\n%d\n%d\n",i,j);
  scanf("%d",&n);
  m[i].magic[j]=n;
 j++;
 } 

 } 
  
 fp=fopen("magictable.tbl","w+");
 fwrite(&m,sizeof(magictbl),5,fp);

return 0;
}

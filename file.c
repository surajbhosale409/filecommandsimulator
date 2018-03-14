#include<stdio.h>


typedef struct magictable
{
int magic[100];
char type[100];
}magictbl;



main()
{
 
 magictbl m[5];
 FILE *fp;
 unsigned char magic[100];
 char cmd[200],fname[100],cmd1[100];

 int i,j,flag;
 
 fp=fopen("magictable.tbl","rb");
 fread(&m,sizeof(magictbl),5,fp);

 do{

 printf("\n\nSuraj:~:$ ");
 gets(cmd); 

 sscanf(cmd,"%s%s",cmd1,fname);

 if(strcmp(cmd1,"file")==0)
 {
  fp=fopen(fname,"rb");
  fread((void *) magic,1,4,fp);
  printf("\nMagic Number is:\n");
 
  for(i=0;i<4;i++) 
   printf("%x\t",(int)magic[i]);

  printf("\n\nFile Type is:");

 for(i=0;i<5;i++)
   {
     flag=0;
     for(j=0;j<4&&flag==0;j++)
     {
      
      if(m[i].magic[j]!=(int)magic[j])
       flag=1;
     }
    if(flag==0)
     printf("\n%s",m[i].type);
   }
 
 	 
 }

 else if (strcmp(cmd1,"clear")==0)
  system("clear");


 else
   printf("\n%s command not found\n",cmd1);

 }while(strcmp(cmd1,"exit")!=0);

return 0;
}

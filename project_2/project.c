#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"
int main(int argc,char **argv)
{
if(argc!=2)
{
printf("usage:./a.out sf");
return 1;
}
FILE*fp=fopen(argv[1],"r");
char t[20];
strcpy(t,argv[1]);
for(int j=0;t[j];j++)
{
if(t[j]=='.')
{
t[j+1]='i'; 
break;    
}
}
FILE *fd=fopen(t,"w");
int size=0;
while(fgetc(fp)!=-1)
{
size++;
}
rewind(fp);
char *p; 
p=malloc(size+1);
fread(p,1,size,fp);
inclusion(p,fd);
comment_removal(p);
macro(p,fd);
}


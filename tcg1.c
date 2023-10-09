#include<stdio.h>
#include<string.h>
int main()
{
int c=0;
char s[100],arg1[100],arg2[100],op1[100],op2[100],res[100];
FILE *fp1,*fp2;
fp1=fopen("t.txt","r");
fp2=fopen("out.txt","w");
while(!feof(fp1))
{
fscanf(fp1,"%s%s%s%s%s",res,op1,arg1,op2,arg2);
fprintf(fp2,"MOV R%d,%s",c,arg1);
if(strcmp("+",op2)==0)
fprintf(fp2,"\nADD R%d,%s",c,arg2);
if(strcmp("-",op2)==0)
fprintf(fp2,"\nSUB R%d,%s",c,arg2);
if(strcmp("/",op2)==0)
fprintf(fp2,"\nDIV R%d,%s",c,arg2);
if(strcmp("*",op2)==0)
fprintf(fp2,"\nMUL R%d,%s",c,arg2);
fprintf(fp2,"\nMOV %s,R%d\n",res,c);
fscanf(fp1,"%s%s%s%s%s",res,op1,arg1,op2,arg2);
c++;
}
}

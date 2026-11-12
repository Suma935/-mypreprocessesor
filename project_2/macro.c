#include"header.h"
char macro_name[100][50];
char macro_value[100][50];

int c1=0;
void macro(char*p,FILE*fd)
{
        char*q=p,*st, *t;
        char key[20], name[200], value[150],line[300];
        int i=0,n,v;
        while(*q)
        {
                st=q;
                i=0;
                while(*q&&*q!='\n')
                {
                        line[i++]=*q;
                        q++;
                }
                line[i]=0;
                if(*q=='\n')
                        q++;
                if(sscanf(line,"%s",key))
                {
                        if(strncmp(key, "##include",8)==0)
                        {
                                t=st;
                                while(t<q)
                                {
                                        if(*t!=10)
                                                *t=32;
                                        t++;
                                }

                        }
                        else if(strcmp(key,"#define")==0)
                        {
                                t=st+7;
                                n=0;
                                v=0;
                                while(*t==32)
                                        t++;
                                while(*t!=32&&*t!=0&&*t!=10)
                                {
                                        name[n++]=*t;
                                        t++;
                                }
                                name[n]=0;
                                while(*t==32)
                                        t++;
                                while(*t!=0&&*t!=10)
                                {
                                        value[v++]=*t;
                                        t++;
                                }
                                value[v]=0;
                                strcpy(macro_name[c1],name);
                                strcpy(macro_value[c1],value);
                                c1++;
                                t=st;
                                while(t<q)
                                {
                                        if(*t!=10)
                                                *t=32;
                                        t++;
                                }
                        }
                }
        }
replace(p,fd);
}
void replace(char *p,FILE *fd)
{
        char word[100],q;
        int i, j,found;
        while(*p)
        {
                if(*p=='"')
                {
                        q=*p;
                        fputc(*p++,fd);
                        while(*p&&*p!=q)
                                fputc(*p++,fd);
                        if(*p==q)
                                fputc(*p++,fd);
                }
                else if((*p>='A'&& *p<='Z')||(*p>='a'&&*p<='z')||*p=='_')
                {
                        i=0;

                        while((*p>='A'&& *p<='Z')||(*p>='a'&&*p<='z')||*p=='_'||(*p>='0'&&*p<='9'))
                        {
                                word[i]=*p;
                                i++;
                                p++;
                        }
                        word[i]=0;
                        found=0;
                        for(j=0;j<c1;j++)
                        {
                                if(strcmp(word,macro_name[j])==0)
                                {
                                        fputs(macro_value[j],fd);
                                        found=1;
                                        break;
                                }
                        }
                        if(found==0)
                                fputs(word,fd);
                }
                else
                {
                        fputc(*p,fd);
                        p++;
                }
        }
}


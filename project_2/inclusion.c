#include"header.h"
void inclusion(char *p,FILE *fd )
{
        char st[20]="#include";
        int len=strlen(st);
        int c;
        int i;
        char path[200], s[20];
        FILE*fp;
        char ch;

        while(*p)
        {
                if(*p=='#')
                {
                        c=0;
                        while(*p==st[c])
                        {
                                c++;
                                p++;

                        }
                        if(c==len)
                        {
                                if(*p=='<')
                                {
                                        p++;
                                        i=0;
                                        while(*p!='>')
                                        {
                                                s[i++]=*p;
                                                p++;
                                        }
                                        s[i]='\0';
                                        if(*p=='>')
                                        {
                                                strcpy(path,"/usr/include/");
                                                strcat(path,s);
                                                fp=fopen(path,"r");
                                                if(fp==NULL)
                                                {
                                                        printf("file not found");
                                                        return ;
                                                }
                                                while((ch=fgetc(fp))!=-1)
                                                        fputc(ch,fd);

                                                fclose(fp);
                                        }
                                }
                        }
                }
                if(*p)
                        p++;
        }
}


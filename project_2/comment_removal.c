#include<stdio.h>
#include<stdlib.h>
#include"header.h"
void comment_removal(char *ptr)
{
        char *s; 
        s=ptr;
        while(*s)
        {
                if(*s=='/'&&*(s+1)=='/')
                {
                        while(*s)
                        {
                                if(*s=='\n')
                                {
                                        *s='\n';
                                        break;
                                }
                                *s=' ';
                                s++;
                        }
                }
         if(*s=='/'&&*(s+1)=='*')
                {

                        while(*s)
                        {

                                if(*s=='*'&&*(s+1)=='/')
                                {
                                        *s=' ';
                                        *(s+1)=' ';
                                        s+=2;
                                        break;
                                }
                                if(*s!='\n')
                                        *s=' ';
                                s++;
                        }
                }
    
                s++;
        }

}

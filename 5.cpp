#include<stdio.h>
#include<string.h>
int main()
{   int i=0,z=0;
    char s[80];
    while((s[i]=getchar())!='\n') 
    i++;
    s[i]='\0';
    for(i=0;s[i]!='\0';i++)
    if(s[i]>='A'&&s[i]<='Z')
          if(s[i]!='A'&&s[i]!='E'&&s[i]!='I'&&s[i]!='O'&&s[i]!='U')
    z++;
    printf("%d",z);
    return 0;
} 

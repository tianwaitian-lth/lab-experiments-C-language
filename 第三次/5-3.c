#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
typedef long long ll;
int main()
{
    printf("please select a mode(1.encode 2.decode)");
    char m;
    scanf("%c",&m);
    if (m=='1')
    {
	char s[1145];
    gets(s);
    gets(s);
    int len=strlen(s);
    int i;
    for (i=0;i<len;i++)
    {
        if (s[i]>='a'&&s[i]<='z')
        {
            s[i]+=3;
            if (s[i]>'z')
                s[i]-=26;
        }
        if (s[i]>='A'&&s[i]<='Z')
        {
            s[i]+=3;
            if (s[i]>'Z')
                s[i]-=26;
        }
    }
    printf("%s\n",s);
    }
    if (m=='2')
    {
	char s[1145];
    gets(s);
    gets(s);
    int len=strlen(s);
    int i;
    for (i=0;i<len;i++)
    {
        if (s[i]>='a'&&s[i]<='z')
        {
            s[i]-=3;
            if (s[i]<'a')
                s[i]+=26;
        }
        if (s[i]>='A'&&s[i]<='Z')
        {
            s[i]-=3;
            if (s[i]<'A')
                s[i]+=26;
        }
    }
    printf("%s\n",s);
    }
    system("pause");
    return 0;
}
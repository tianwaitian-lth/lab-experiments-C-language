#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
typedef long long ll;
void change(char *s)
{
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
}
int main()
{
	char *s;
    s=(char *)malloc(1145);
    gets(s);
    int len=strlen(s);
    int i;
    change(s);
    printf("%s\n",s);
    system("pause");
    return 0;
}
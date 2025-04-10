#include <stdio.h>
#include <string.h>

int main()
{
    int maxLength = 1000001;  // Maximum input length
    char str[maxLength];

    if (fgets(str, maxLength, stdin) != NULL)
    {
        str[strcspn(str, "\n")] = '\0';
    }
    int a=1;
    int max=0;
    for(int i=1;i<=strlen(str);i++)
    {
        if(str[i]==str[i-1])
        {
            a++;
        }
        else
        {
            a=1;
        }

        if(max<=a)
        {
            max=a;
        }

    }
    printf("%d",max);
    return 0;
}
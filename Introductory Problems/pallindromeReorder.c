#include <stdio.h>
#include <string.h>


int main()
{
    char str[1000001];
    scanf("%s",str);

    int abc[26]; //freq abcay
    for(int i=0;i<26;i++)
    {
        abc[i]=0;
    }

    int n=strlen(str);
    char pallindrome[n+1];
    // for(int i=0;i<26;i++)
    // {
    //     printf("%d ",abc[i]);
    // }
    // printf("\n");

    for(int i=0;i<n;i++)
    {
        abc[str[i]-'A']++;
    }
    
    // for(int i=0;i<26;i++)
    // {
    //     printf("%d ",abc[i]);
    // }

    int flag=0; // zero odd number freq elements 
    int odd=0;
    for(int i=0;i<26;i++)
    {
        if(abc[i]%2!=0)
        {
            flag++;
            odd=i;
        }
    }

    if(flag>1)
    {
        printf("NO SOLUTION");
        return 0;
    }
    else if(flag==1)
    {
        // one with odd freq comes at centre
        pallindrome[n/2]=odd+'A';
        abc[odd]-=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
            {
                while(abc[j]!=0)
                {
                    pallindrome[i]=j+'A';
                    pallindrome[n-i-1]=j+'A';
                    i++;
                    abc[j]-=2;
                }
            }
        }
    }
    else
    {
        // we have to fill symmetrically now from start and end
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
            {
                while(abc[j]!=0)
                {
                    pallindrome[i]=j+'A';
                    pallindrome[n-i-1]=j+'A';
                    i++;
                    abc[j]-=2;
                }
            }
        }
    }


    for(int i=0;i<n;i++)
    {
        printf("%c",pallindrome[i]);
    }
    // printf("%s",pallindrome);

    return 0;
}
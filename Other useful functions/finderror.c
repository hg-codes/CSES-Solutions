// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int main() {
    // Write C code here
    int n=100000;
    int arr[n];
    int arr1[n];
    for(int i=0;i<n;i++)
    {
        char str[3];
        scanf("%s",str);
        if(strcmp(str, "YES")==0)  arr[i]=1;
        else    arr[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        char str[3];
        scanf("%s",str);
        if(strcmp(str, "YES")==0)  arr1[i]=1;
        else    arr1[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=arr1[i])  
        {
            printf("found %d",i+1);
        }
    }
    // printf("%d %d",arr[5],arr[6]);
    

    return 0;
}
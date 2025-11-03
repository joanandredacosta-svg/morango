#include <stdio.h>

int main()
{
    int n = 0;
    int a = 0;

    scanf("%d", &n);
        int s[n];
    int i = 0;
    while(i < n)
    {
        scanf("%d", &s[i]);
        i++;
    }
    int j = 0;
    while(j < n - 1)
    {
        i = 0;
        while(i < n - 1)
        {
            if(s[i] > s[i + 1])
            {
                a = s[i];
                s[i] = s[i + 1];
                s[i + 1] = a;
            }
            i++;
        }
        j++;
    }
    i = 0;
    while(i < n)
    {
        printf("%d ", s[i]);
        i++;
    }
    printf("\n");
    return(0);
}
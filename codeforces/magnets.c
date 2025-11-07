#include <stdio.h>

int main()
{
    int n = 0, i = 0, conta = 1;

    scanf("%d", &n);
    int p[n];
    int s[n];
    while (i < n)
    {
        scanf("%d", &p[i]);
        s[i] = p[i];
        if(i != 0 && s[i - 1] != s[i])
            conta++;
        i++;
    }
    printf("%d", conta);
    return(0);
}
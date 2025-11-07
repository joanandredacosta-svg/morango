#include <stdio.h>

char imprime_menor(char *str)
{
    int i = 0;

    while(str[i])
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        printf("%c", str[i]);
        i++;
    }
    return(0);
}

char imprime_maior(char *str)
{
    int i = 0;

    while(str[i])
    {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        printf("%c", str[i]);
        i++;
    }
    return(0);
}

int main()
{
    char str[101] = " ";
    int i, maior = 0, menor = 0;

    scanf("%s", str);
    while(str[i])
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            maior++;
        else if(str[i] >= 'a' && str[i] <= 'z')
            menor++;
        i++;
    }
    if(maior > menor)
    {
        imprime_maior(str);
    }
    else if(menor >= maior)
    {
        imprime_menor(str);
    }
    return(0);
}
#include <stdio.h>
#include <ctype.h>

char imprime_menor(char *str)
{
    int i = 0;

    while(str[i])
    {
        printf("%c", tolower(str[i]));
        i++;
    }
    return(0);
}

char imprime_maior(char *str)
{
    int i = 0;

    while(str[i])
    {
        printf("%c", toupper(str[i]));
        i++;
    }
    return(0);
}

int main()
{
    char str[101] = " ";
    int i = 0, maior = 0, menor = 0;

    scanf("%s", str);
    while(str[i])
    {
        if(isupper(str[i]))
            maior++;
        else
            menor++;
        i++;
    }
    if(maior > menor)
        imprime_maior(str);
    else
        imprime_menor(str);
    return(0);
}
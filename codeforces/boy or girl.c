#include <stdio.h>

int     banana(char *str, char c, int index)
{
        int i;

        i = 0;
        while(i < index)
        {
                if(str[i] == c)
                {
                        return(1);
                }
                i++;
        }
        return(0);
}

int main ()
{
    char str[101] = "";
    int conta = 0;

    scanf("%s", str);
    for(int i=0; str[i]; i++) 
        if(banana(str, str[i], i) == 0)
            conta++;
    
    if(conta % 2 == 0) 
        printf("CHAT WITH HER!");
    else
        printf("IGNORE HIM!");
}
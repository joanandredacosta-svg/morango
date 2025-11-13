#include <stdio.h>

int main()
{
    int n = 0;
    int i = 0;
    int sereja = 0;
    int sere = 0;
    int dima = 0;
    int dim = 0;
    
    scanf("%d", &n);
    int s[n];
    while(i < n)
    {
		int valor;
        scanf("%d", &valor);
		s[i] = valor;
        i++;
    }
	i--;
    int j = 0;
    while(i >= j)
    {
    	if(s[i] > s[j])
    	{
    		if(sereja == 0 || sere == 1)
    		{
    			sereja += s[i];
    			dim = 1;
    			sere = 0;
    			i--;
    		}
    		else if(dim == 1)
    		{
    			dima += s[i];
    			sere = 1;
    			dim = 0;
    			i--;
    		}
    	}
    	else if(s[i] <= s[j])
    	{
    		if(sereja == 0 || sere == 1)
    		{
    			sereja += s[j];
    			dim = 1;
    			sere = 0;
    			j++;
    		}
    		else if(dim == 1)
    		{
    			dima += s[j];
    			sere = 1;
    			dim = 0;
    			j++;
    		}
    	}
    }
    printf("sereja: %d\n", sereja);
    printf("dima: %d\n", dima);
}
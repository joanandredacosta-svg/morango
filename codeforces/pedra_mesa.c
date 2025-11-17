#include <stdio.h>

int main()
{
	int n = 0, i = 0, cont = 0;
	char str[51] = " ";
	
	scanf("%d", &n);
	scanf("%s", str);
	while(i < n)
	{
		if(str[i] == str[i + 1])
			i++;
		else
		{
			cont++;
			i++;
		}
	}
	printf("%d", i - cont);
}
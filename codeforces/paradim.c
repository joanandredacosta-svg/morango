#include <stdio.h>
int main()
{
	int n;
	int i = 0;
	
	scanf("%d", &n);
	char s[n];
	scanf("%s", s);
	while(s[i])
	{
		if(s[i] == s[i + 1])
		{
			printf("NO");
			return(0);
		}
		else
			i++;
	}
    if(i == 1)
    {
        printf("NO");
        return(0);
    }
	printf("YES");
	return(0);
}
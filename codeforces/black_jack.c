#include <stdio.h>

int main()
{
	int s[5];
	int i = 0;
	char banana[100001] = " ";
	int conta = 0;
	
	while(i < 4)
	{
		scanf("%d", &s[i]);	
		i++;
	}
	scanf("%s", banana);
	int j = 0;
	while(banana[j])
	{
		if(banana[j] == '1')
			conta += s[0];
		else if(banana[j] == '2')
			conta += s[1];
		else if(banana[j] == '3')
			conta += s[2];
		else if(banana[j] == '4')
			conta += s[3];
		j++;
	}
	printf("%d", conta);
}
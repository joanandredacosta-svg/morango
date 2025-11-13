#include <stdio.h>
#include <string.h>

int main ()
{
    char a[101] = "";
    char b[101] = "";
    scanf("%s%s", a,b); 
    
    if(strcasecmp(a, b) == 0)
    	printf("0");
    else if(strcasecmp(a, b) > 0)
    	printf("1");
    else
    	printf("-1");
}

#include <stdio.h>

int main(){
	long long max,min;
	scanf("%lld  %lld",&max ,&min);
	long long c;
	if (max<min)
		c=max,max=min,min=c,c=0;
	do
	{
		c=max%min;
		max=min;
		min=c;
	}
	while(c!=0);
	printf("%lld",max);
	int a;
	return 0;

}
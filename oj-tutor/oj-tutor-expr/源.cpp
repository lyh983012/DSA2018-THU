#include <stdio.h>

int main(){
	long long a,b;
	char op;
	scanf("%lld %c %lld",&a,&op,&b);
	if ( op == '+')
		printf("%lld",a+b);
	else if ( op == '-')
		printf("%lld",a-b);
	else if ( op == '*')
		printf("%lld",a*b);
	return 0;

}
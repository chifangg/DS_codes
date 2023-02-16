#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


int main()
{
	long long int cnt = 0;
	char numt;
	long long int num = 0;
	long long int max = INT_MIN;
	long long int min = INT_MAX;
	while(1)
	{
		scanf("%lld", &num);
		
		cnt = cnt + num;
		if(num > max) max = num;			
		if(num < min) min = num;
		scanf("%c", &numt);
		if(numt == '\n')
		break;
	}
	printf("%lld %lld %lld\n", max, min, cnt);
}

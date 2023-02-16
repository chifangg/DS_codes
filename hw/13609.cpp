#include<stdio.h>
#include<stdlib.h>


int main()
{
	int M, N, K;
	scanf("%d", &M);
	int list[100000];
	for(int i = 0; i < M; i++)
	{
		scanf("%d%d", &N, &K);
		for(int s = 0; s < N; s++)
		{
			scanf("%d", &list[s]);
		}
		int now = 0, cnt = 0;
		cnt = N / K;
		
		for(int j = 0; j < cnt; j++)
		{
			now += K;
			for(int k = 0; k < K; k++)
			{
				printf("%d ", list[now - k-1]);
			}
			
		}
		int left = 0;
		left = N - now;
		for(int j = 0; j < left ; j++)
		{
			printf("%d ", list[now + j]);
		}
		printf("\n");
		
	}
}

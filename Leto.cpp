#include <stdio.h>
#include <malloc.h>
#include <cstdlib>
#define max 100
void creat_collections(int mass[], int N)
{
	int bunch1 [max-1], bunch2 [max-1], k1=0, k2=0;
	float  sum1 = 0, sum2 = 0 ;
	for (int i = 0; i < N; i++)
	{
		if (sum1 <= sum2)
		{
			bunch1[k1] = mass[i];
			sum1 = sum1 + mass[i];
			k1++;
		}
		else
		{
			bunch2[k2] = mass[i];
			sum2 = sum2 + mass[i];
			k2++;
		}
	}
	if(sum1>=sum2)
	{
	if (sum1 / sum2 <= 2)
	{
		printf("\nFirst bunch=%f: ",sum1);
			for (int u = 0; u < k1; u++)
			{
				printf("%d ", bunch1[u]);
		    }
		printf("\nSecond bunch=%f: ", sum2);
			for (int u = 0; u < k1; u++)
			{
				printf("%d ", bunch2[u]);
			}
	}
	else
	{
		printf("Some problem. Try one more time.");
	}
	}
	if (sum2 > sum1)
	{
		if (sum2 / sum1 <= 2)
		{
			printf("\nFirst bunch=%f: ", sum1);
			for (int u = 0; u < k1; u++)
			{
				printf("%d ", bunch1[u]);
			}
			printf("\nSecond bunch=%f: ", sum2);
			for (int u = 0; u < k1; u++)
			{
				printf("%d ", bunch2[u]);
			}
		}
		else
		{
			printf("Some problem. Try one more time.\n");
		}
	}
}
int main()
{
	int N;
	printf("How many rocks? ");
	scanf_s("%d", &N);
	int* mass;
	mass = (int *)malloc(N * sizeof(int));
	printf("Input the weight of rocks :\n");
	for (int i = 0; i < N; i++)
		scanf_s("%d", &mass[i]);
	//сортировка пузырьком
	int tmp;
	bool noSwap;

	for (int i = N - 1; i >= 0; i--)
	{
		noSwap = 1;
		for (int j = 0; j < i; j++)
		{
			if (mass[j] > mass[j + 1])
			{
				tmp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = tmp;
				noSwap = 0;
			}
		}
		if (noSwap == 1)
			break;
	}
	printf("Sorted array:\n");
	for (int i = 0; i < N; i++)
		printf("%d ", mass[i]);
	printf("\n");
	creat_collections(mass,N);
	free(mass);
	system("pause");
	return 0;
}

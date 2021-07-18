#include <stdio.h>
#include <math.h>

int recursion(int num);
int loop(int num);

void solve()
{
	int n;
	do
	{
		printf("Nhap N: ");
		scanf("%d", &n);
	} while (n <= 0);
	int resultRecursion = recursion(n);
	int resultLoop = loop(n);
	printf("\nResult with recursion = %d", resultRecursion);
	printf("\nResult with loop = %d", resultLoop);
	return;
}

int main()
{
	solve();

	fclose(stdin);
	fclose(stdout);
	return 0;
}

int recursion(int num)
{
	int result = 0;
	if (num == 1)
	{
		result = -1;
	}
	else
	{
		result = recursion(num - 1) + pow(-1, num) * (num);
	}
	return result;
}

int loop(int num)
{
	int result = 0;
	for (int i = 1; i <= num; i++)
	{
		result += pow(-1, i) * i;
	}
	return result;
}

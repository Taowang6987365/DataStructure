#include<stdio.h>

int fun(int n)
{
	if (n > 0)
	{
		return fun(n - 1) + n;
	}
	return 0;
}

int method(int n)
{
	static int x = 0;
	if (n > 0)
	{
		x++;
		return method(n - 1) + x;
	}
	return 0;
}

int num = 0;
int function(int n)
{
	if (n > 0)
	{
		num++;
		return function(n - 1) + num;
	}
	return 0;
}

int main()
{
	//int r;
	//r = fun(5);
	//printf("%d", r);

	//int r;
	//r = method(5);
	//printf("%d\n", r);

	int r;
	r = function(5);
	printf("%d", r);

	return 0;
}
#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int A[] = { 2,4,6,8,10,12,14};

	for (int x : A)
	{
		printf("%d\n", x);
	}

	return 0;
}

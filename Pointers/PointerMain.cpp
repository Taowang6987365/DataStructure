#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
	//int a = 10;
	//int *p;
	//p = &a;//store address a to p
	//cout << a << endl;
	//printf("using pointer %d", *p);


	//int A[5] = { 2,4,6,8,10 };
	//int* p;
	//p = A;
	////p = &A[0];

	//for (int i = 0; i < 5; i++)
	//{
	//	cout << p[i] << endl;
	//}


	int* p;
	p = (int*)malloc(5 * sizeof(int));
	//p = new int[5];
	p[0] = 10;
	p[1] = 15;
	p[2] = 14;
	p[3] = 21;
	p[4] = 31;

	for (int i = 0; i < 5; i++)
	{
		cout << p[i] << endl;
	}

	//whenever you are dynamically allocating memory, 
	//you must release the memory when you have finished using it
	//c++:
	//delete[] p;
	
	//c lang
	free(p);
	

	return 0;
}
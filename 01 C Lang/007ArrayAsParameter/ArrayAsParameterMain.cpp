#include <iostream>
using namespace std;

//Array pass by address
void fun(int *A,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << endl;
	}
	A[0] = 15; //because array pass is a pointer, so we can access the array it self
}

int* fun(int size)
{
	int* p;
	p = new int[size];

	for (int i = 0; i < size; i++)
	{
		p[i] = i + 1;
	}

	return p;
}


int* method(int size)
{
	int* p = new int[size];
	for (int i = 0; i < size; i++)
	{
		p[i] = i + 1;
	}
	return p;
}

void method(int* A, int size)
{
	for (int i = 0; i < size; i++)
	{
		A[i] = 20;
	}
}

int main()
{
	int A[ ] = { 2,4,6,8,10 };
	int n = 5;

	int* ptr, size = 7;
	ptr = method(size);
	for (int i = 0; i < size; i++)
	{
		cout << ptr[i] << " ";
	}



	//fun(A,n);
	////cout << sizeof(A) / sizeof(int) << endl;

	//for (int x : A)
	//cout << x << " ";

	//cout << endl << "******************************" << endl;

	//int* ptr, sz = 7;
	//ptr = fun(sz);
	//for (int i = 0; i < sz; i++)
	//{
	//	cout << ptr[i] << endl;
	//}


	return 0;
}
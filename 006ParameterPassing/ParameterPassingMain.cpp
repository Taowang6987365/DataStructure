#include <iostream>
using namespace std;

int add(int a, int b)
{
	int c;
	c = a + b;
	return c;
}

void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void swap(int& x, int* y)
{
	int temp;
	temp = x;
	x = *y;
	*y = temp;
}

int main()
{
	int num1 = 10, num2 = 15, sum;

	sum = add(num1, num2);
	cout << "sum is " << sum << endl;

	//swap(&num1, &num2);
	//cout << "num1 = " << num1 << endl;
	//cout << "num2 = " << num2 << endl;

	swap(num1, &num2);
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
		 
	return 0;
}
#include<iostream>
#include<stdio.h>
using namespace std;

struct Rectangle
{
	int length; // 4 bytes
	int breadth; //4 bytes
	char x; // 1 byte, compiler choose 4 bytes instead of 1 bytes, but actual use 1 byte, later it will discard 3 bytes
} r1; // variable declaration

//struct Rectangle r1;

int main()
{
	r1 = { 10,5 };

	printf("%d\n", sizeof(r1)); // 4 + 4 + 4 = 12 bytes
	cout << r1.length << endl;
	cout << r1.breadth << endl;

	return 0;
}
#include <iostream>
#include <stdio.h>

using namespace std;

class Rectangle
{
private:
	int length;
	int breadth;

public:
	void initialise(int l, int b)
	{
		length = l;
		breadth = b;
	}

	int area()
	{
		return length * breadth;
	}

	int perimeter()
	{
		int p;
		p = 2 * (length + breadth);
		return p;
	}
};

int main()
{
	Rectangle r;

	int l, b;
	printf("Enter Length and Breadth");
	cin >> l >> b;

	r.initialise(l, b);

	int a = r.area();
	int peri = r.perimeter();

	printf("Area=%d\nPerimeter=%d\n", a, peri);
	return 0;
}
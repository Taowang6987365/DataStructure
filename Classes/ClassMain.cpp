#include <iostream>

using namespace std;

class Rectangle
{
private:
	int length;
	int breadth;

public:
	Rectangle();
	Rectangle(int l, int b);
	int area();
	int perimiter();
	void setLength(int l);
	void setBreadth(int b);
	~Rectangle();
};

Rectangle::Rectangle()
{
	this->length = 0;
	this->breadth = 0;
}

Rectangle::Rectangle(int l, int b)
{
	this->length = l;
	this->breadth = b;
}

int Rectangle::area()
{
	return length * breadth;
}

int Rectangle::perimiter()
{
	return 2 * (length + breadth);
}

void Rectangle::setLength(int l)
{
	this->length = l;
}

void Rectangle::setBreadth(int b)
{
	this->breadth = b;
}

Rectangle::~Rectangle()
{
	cout << "Destructor" << endl;
}

int main()
{
	Rectangle r(10, 5);
	cout << "Area " << r.area() << endl;
	cout << "Perimeter " << r.perimiter() << endl;
	return 0;
}
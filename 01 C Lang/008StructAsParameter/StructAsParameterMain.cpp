#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Rectangle
{
	int length;
	int breadth;
};

void fun(struct Rectangle r)
{
	r.length = 20;//only change inside the function
	cout << "Length " << r.length << endl << "Breadth " << r.breadth << endl;
}

void fun(struct Rectangle *p)
{
	p->length = 20;
	cout << "Length " << p->length << endl << "Breadth " << p->breadth << endl;
}

void func1()
{
	struct Rectangle r = { 10,5 };

	fun(r);
	printf("Length %d \nBreadth %d\n", r.length, r.breadth);
	cout << "***********" << endl;

	fun(&r);
	printf("Length %d \nBreadth %d\n", r.length, r.breadth);
}


struct Rectangle* fun()
{
	struct Rectangle* p;
	p = new Rectangle;
	//p = (struct Rectangle*)malloc(sizeof(struct Rectangle));

	p->length = 15;
	p->breadth = 7;

	return p;
}

void func2()
{
	struct Rectangle* ptr = fun();//objetc create by fun()

	cout << "Length " << ptr->length << endl << "Breadth " << ptr->breadth << endl;
}

int main()
{
	//func1();
	func2();
	return 0;
}
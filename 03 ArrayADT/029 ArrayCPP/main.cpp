#include <iostream>

using namespace std;

void swap(int* x, int* y);
void f1();

class Array
{
private:
	int* A;
	int size;
	int length;
	void swap(int* x, int* y);
public:
	Array()
	{
		size = 10;
		length = 0;
		A = new int[size];
	}
	Array(int sz)
	{
		size = sz;
		length = 0;
		A = new int[size];
	}
	~Array()
	{
		delete[]A;
	}
	void Display();
	void Append(int x);
	void Insert(int index, int x);


	int Delete(int index);
	int LinearSearch(int key);
	int BinarySearch(int key);
	int RBinSearch(int a[], int l, int h, int key);
	int Get(int index);
	void Set(int index, int x);
	int Max();
	int Min();
	int Sum();
	float Avg();
	void Reverse();
	void Reverse2();
	void RightShift();
	void RightRotate();
	void InsertSort(int x);
	int isSorted();
	void ReArrange();

	Array* Merge(Array arr2);
	Array* Union(Array arr2);
	Array* Intersection(Array arr2);
	Array* Difference(Array arr2);
	Array* UnsortUnion(Array arr2);
	Array* UnsortIntersection(Array arr2);
	Array* UnsortDifference(Array arr2);
};

void Array::Display()
{
	int i;
	printf("\nElements are\n");
	for (i = 0; i < length; i++)
		printf("%d ", A[i]);
}

void Array::Insert(int index, int x)
{
	int i;
	if (index >= 0 && index <= length)
	{
		for (i = length; i > index; i--)
		{
			A[i] = A[i - 1];
		}
		A[index] = x;
		length++;
	}
}

void Array::Append(int x)
{
	if (length < size)
	{
		A[length++] = x; //length++ after the code finished
	}
}

int Array::Delete(int index)
{
	int x = 0;
	int i;
	if (index >= 0 && index <= length - 1)
	{
		x = A[index];
		//copy end to front
		for (i = index; i < length - 1; i++)
		{
			A[i] = A[i + 1];
		}
		length--;
		return x;
	}

	return 0;
}

void Array::swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int Array::LinearSearch(int key)
{
	int i;
	for (i = 0; i < length; i++)
	{
		if (key ==A[i])
		{
			swap(&A[i], &A[0]);
			return 0;
		}
	}
	return -1;
}

int Array::BinarySearch(int key)
{
	int l, mid, h;
	l = 0;
	h = length - 1;

	while (l <= h)
	{
		mid = (l + h) / 2;
		if (key == A[mid])
			return mid;
		else if (key < A[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

int Array::RBinSearch(int a[], int l, int h, int key)
{
	int mid;
	if (l <= h)
	{
		mid = (l + h) / 2;
		if (key == a[mid])
			return mid;
		else if (key < a[mid])
			return RBinSearch(a, l, mid - 1, key);
		else
			return RBinSearch(a, mid + 1, h, key);
	}
	return -1;
}

int Array::Get(int index)
{
	if (index >= 0 && index < length)
		return A[index];
	else
		return -1;
}

void Array::Set(int index, int x)
{
	if (index >= 0 && index < length)
		A[index] = x;
}

int Array::Max()
{
	int max = A[0];
	int i;
	for (i = 1; i < length; i++)
	{
		if (A[i] > max)
			max = A[i];
	}
	return max;
}

int Array::Min()
{
	int min = A[0];
	int i;
	for (i = 1; i < length; i++)
	{
		if (A[i] < min)
			min = A[i];
	}
	return min;
}

int Array::Sum()
{
	int s = 0;
	int i;
	for (i = 0; i < length; i++)
		s += A[i];

	return s;
}

float Array::Avg()
{
	return (float)Sum() / length;
}

void Array::Reverse()
{
	int* B;
	int i, j;
	B = new int[length];
	for (i = length - 1, j = 0; i >= 0; i--, j++)
	{
		B[j] = A[i];
	}

	for (i = 0; i < length; i++)
	{
		A[i] = B[i];
	}
}

void Array::Reverse2()
{
	int i, j;
	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		swap(&A[i], &A[j]);
	}
}

void Array::RightShift()
{
	for (int i = 0; i < length; i++)
	{
		A[i] = A[i + 1];
	}
}

void Array::RightRotate()
{
	int temp = A[0];
	for (int i = 0; i < length; i++)
	{
		A[i] = A[i + 1];
	}
	Set(length - 1, temp);
}

void Array::InsertSort(int x)
{
	int i = length - 1;
	if (length == size)
		return;//no free space
	while (i >= 0 && A[i] > x)
	{
		A[i + 1] = A[i];
		i--;
	}
	A[i + 1] = x;
	length++;
}

int Array::isSorted()
{
	int i;
	for (i = 0; i < length - 1; i++)
	{
		if (A[i] > A[i + 1])
			return 0;
	}
	return 1;
}

void Array::ReArrange()
{
	int i, j;
	i = 0;
	j = length - 1;

	while (i < j)
	{
		while (A[i] < 0)i++;
		while (A[j] >= 0)j--;

		if (i < j) swap(&A[i], &A[j]);
	}
}

Array* Array::Merge(Array arr2)
{
	/*
		combine 2 sorted arrays
	*/
	int i, j, k;
	i = j = k = 0;
	Array *arr3 = new Array(length + arr2.length);

	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
		{
			arr3->A[k++] = A[i++];
		}
		else
		{
			arr3->A[k++] = arr2.A[j++];
		}
	}
	//copy the remain elements
	for (; i < length; i++)//start i from where it is
	{
		arr3->A[k++] = A[i];
	}
	for (; j < arr2.length; j++)//start j from where it is
	{
		arr3->A[k++] = arr2.A[j];
	}

	arr3->length = length + arr2.length;

	return arr3;
}

Array* Array::Union(Array arr2)
{
	/*
		combine different elements of 2 sorted arrays
	*/
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = new Array(length + arr2.length);

	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else if (arr2.A[j] < A[i])
			arr3->A[k++] = arr2.A[j++];
		else
		{
			arr3->A[k++] = A[i++];//copy any array element, because they have same value
			j++;
		}

	}
	//copy the remain elements
	for (; i < length; i++)//start i from where it is
		arr3->A[k++] = A[i];
	for (; j < arr2.length; j++)//start j from where it is
		arr3->A[k++] = arr2.A[j];

	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

Array* Array::Intersection(Array arr2)
{
	/*
		combine same elements of 2 sorted arrays
	*/
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = new Array(length + arr2.length);

	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			i++;
		else if (arr2.A[j] < A[i])
			j++;
		else if (A[i] == arr2.A[j])
		{
			arr3->A[k++] = A[i++];//copy any array element, because they have same value
			j++;
		}

	}

	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

struct Array* Array::Difference(Array arr2)
{
	/*
		Find arr1's different elements from arr1 compare to arr2
	*/
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = new Array(length + arr2.length);

	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else if (arr2.A[j] < A[i])
			j++;
		else
		{
			i++;
			j++;
		}

	}
	//copy the remain elements
	//copy remain elements of arr1
	for (; i < length; i++)//start i from where it is
		arr3->A[k++] = A[i];

	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

struct Array* Array::UnsortUnion(Array arr2)
{
	/*
		combine different elements of 2 unsorted arrays
	*/
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = new Array(length + arr2.length);

	while (i < length)
	{
		arr3->A[k++] = A[i++];
	}

	while (j < arr2.length)
	{
		int temp = BinarySearch(arr2.A[j]);
		if (temp == -1)
			arr3->A[k++] = arr2.A[j];
		j++;
	}

	arr3->length = k;
	arr3->size = 10;

	return arr3;
}

Array* Array::UnsortIntersection(Array arr2)
{
	/*
		combine same elements of 2 unsorted arrays
	*/
	int i, k;
	i = k = 0;
	Array* arr3 = new Array(length + arr2.length);

	while (i < length)
	{
		int temp = BinarySearch(A[i++]);
		if (temp != -1)
		{
			arr3->A[k++] = A[temp];
		}
	}

	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

Array* Array::UnsortDifference(Array arr2)
{
	/*
		Find arr1's different elements from arr1 compare to arr2
	*/
	int i, k;
	i = k = 0;
	Array* arr3 = new Array(length + arr2.length);

	while (i < length)
	{
		int temp = BinarySearch(A[i]);
		if (temp == -1)
		{
			arr3->A[k++] = A[i];
		}
		i++;
	}

	arr3->length = k;
	arr3->size = 10;
	return arr3;
}


int main()
{
	Array *arr1;
	int ch,sz;
	int x, index;

	printf("Enter Size of Array : ");
	cin >> sz;
	arr1 = new Array(sz);
	do
	{
		printf("Menu\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("4. Sum\n");
		printf("5. Display\n");
		printf("6. Exit\n");

		printf("enter your choice: \n");
		scanf_s("%d", &ch);

		switch (ch)
		{
		case 1: printf("Enter an element and index: \n");
			scanf_s("%d%d", &x, &index);
			arr1->Insert(index, x);

			break;
		case 2: printf("Enter index: ");
			cin >> index;
			x = arr1->Delete(index);
			printf("Deleted Element is %d\n", x);
			break;
		case 3: printf("Enter element to search");
			cin >> x;
			index = arr1->LinearSearch(x);
			printf("Element index %d", index);
			break;
		case 4: printf("Sum is %d\n", arr1->Sum());
			break;
		case 5: arr1->Display();
			cout << endl;
		}
	} while (ch < 6);

	return 0;
}


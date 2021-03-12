#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

void swap(int* x, int* y);
void f1();

struct Array
{
	int *A;
	int size;
	int length;
};

void Display(struct Array arr)
{
	int i;
	printf("Elements are\n");
	for (i = 0; i < arr.length; i++)
		printf("%d ",arr.A[i]);
}

void Insert(struct Array* arr, int index, int x)
{
	int i;
	if (index >= 0 && index <= arr->length)
	{
		for (i = arr->length; i > index; i--)
		{
			arr->A[i] = arr->A[i - 1];
		}
		arr->A[index] = x;
		arr->length++;
	}
}

void Append(struct Array* arr, int x) 
{
	if (arr->length < arr->size)
	{
		arr->A[arr->length++] = x; //length++ after the code finished
	}
}

int Delete(struct Array* arr, int index)
{
	int x = 0;
	int i;
	if (index >= 0 && index <= arr->length - 1)
	{
		x = arr->A[index];
		//copy end to front
		for (i = index; i < arr->length - 1; i++)
		{
			arr->A[i] = arr->A[i + 1];
		}
		arr->length--;
		return x;
	}

	return 0;
}

void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int LinearSearch(struct Array *arr, int key)
{
	int i;
	for (i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i])
		{
			swap(&arr->A[i],&arr->A[0]);
			return 0;
		}
	}
	return -1;
}

int BinarySearch(struct Array arr, int key)
{
	int l, mid, h;
	l = 0;
	h = arr.length - 1;
	
	while (l <= h)
	{
		mid = (l + h) / 2;
		if (key == arr.A[mid])
			return mid;
		else if (key < arr.A[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

int RBinSearch(int a[], int l, int h, int key)
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

int Get(struct Array arr,int index)
{
	if (index >= 0 && index < arr.length)
		return arr.A[index];
	else
		return -1;
}

void Set(struct Array* arr, int index, int x)
{
	if (index >= 0 && index < arr->length)
		arr->A[index] = x;
}

int Max(struct Array arr)
{
	int max = arr.A[0];
	int i;
	for (i = 1; i < arr.length; i++)
	{
		if (arr.A[i] > max)
			max = arr.A[i];
	}
	return max;
}

int Min(struct Array arr)
{
	int min = arr.A[0];
	int i;
	for (i = 1; i < arr.length; i++)
	{
		if (arr.A[i] < min)
			min = arr.A[i];
	}
	return min;
}

int Sum(struct Array arr)
{
	int s = 0;
	int i;
	for (i = 0; i < arr.length; i++)
		s += arr.A[i];

	return s;
}

float Avg(struct Array arr)
{
	return (float)Sum(arr) / arr.length;
}

void Reverse(struct Array* arr)
{
	int* B;
	int i, j;
	B = (int*)malloc(arr->length * sizeof(int));
	for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
	{
		B[j] = arr->A[i];
	}

	for (i = 0; i < arr->length; i++)
	{
		arr->A[i] = B[i];
	}
}

void Reverse2(struct Array* arr)
{
	int i, j;
	for (i = 0, j = arr->length - 1; i < j; i++, j--)
	{
		swap(&arr->A[i], &arr->A[j]);
	}
}

void RightShift(struct Array* arr)
{
	for (int i = 0; i < arr->length; i++)
	{
		arr->A[i] = arr->A[i + 1];
	}
}

void RightRotate(struct Array* arr)
{
	int temp = arr->A[0];
	for (int i = 0; i < arr->length; i++)
	{
		arr->A[i] = arr->A[i + 1];
	}
	Set(arr, arr->length - 1, temp);
}

void InsertSort(struct Array* arr, int x)
{
	int i = arr->length - 1;
	if (arr->length == arr->size)
		return;//no free space
	while (i >= 0 && arr->A[i] > x)
	{
		arr->A[i + 1] = arr->A[i];
		i--;
	}
	arr->A[i + 1] = x;
	arr->length++;
}

int isSorted(struct Array arr)
{
	int i;
	for (i = 0; i < arr.length - 1; i++)
	{
		if (arr.A[i] > arr.A[i + 1])
			return 0;
	}
	return 1;
}

void ReArrange(struct Array* arr)
{
	int i, j;
	i = 0;
	j = arr->length - 1;

	while (i < j)
	{
		while (arr->A[i] < 0)i++;
		while (arr->A[j] >= 0)j--;

		if (i < j) swap(&arr->A[i], &arr->A[j]);
	}
}

struct Array* Merge(struct Array* arr1, struct Array* arr2)
{
	/*
		combine 2 sorted arrays
	*/
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
		{
			arr3->A[k++] = arr1->A[i++];
		}
		else
		{
			arr3->A[k++] = arr2->A[j++];
		}
	}
	//copy the remain elements
	for (; i < arr1->length; i++)//start i from where it is
	{
		arr3->A[k++] = arr1->A[i];
	}
	for (; j < arr2->length; j++)//start j from where it is
	{
		arr3->A[k++] = arr2->A[j];
	}

	arr3->length = arr1->length + arr2->length;
	arr3->size = 10;

	return arr3;
}

struct Array* Union(struct Array* arr1, struct Array* arr2)
{
	/*
		combine different elements of 2 sorted arrays
	*/
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else if (arr2->A[j] < arr1->A[i])
			arr3->A[k++] = arr2->A[j++];
		else
		{
			arr3->A[k++] = arr1->A[i++];//copy any array element, because they have same value
			j++;
		}
			
	}
	//copy the remain elements
	for (; i < arr1->length; i++)//start i from where it is
		arr3->A[k++] = arr1->A[i];
	for (; j < arr2->length; j++)//start j from where it is
		arr3->A[k++] = arr2->A[j];

	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

struct Array* Intersection(struct Array* arr1, struct Array* arr2)
{
	/*
		combine same elements of 2 sorted arrays
	*/
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			i++;
		else if (arr2->A[j] < arr1->A[i])
			j++;
		else if(arr1->A[i] == arr2->A[j])
		{
			arr3->A[k++] = arr1->A[i++];//copy any array element, because they have same value
			j++;
		}

	}

	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

struct Array* Difference(struct Array* arr1, struct Array* arr2)
{
	/*
		Find arr1's different elements from arr1 compare to arr2
	*/
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else if (arr2->A[j] < arr1->A[i])
			j++;
		else
		{
			i++;
			j++;
		}

	}
	//copy the remain elements
	//copy remain elements of arr1
	for (; i < arr1->length; i++)//start i from where it is
		arr3->A[k++] = arr1->A[i];

	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

struct Array* UnsortUnion(struct Array* arr1, struct Array* arr2)
{
	/*
		combine different elements of 2 unsorted arrays
	*/
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

	while (i < arr1->length)
	{
		arr3->A[k++] = arr1->A[i++];
	}

	while (j < arr2->length)
	{
		int temp = BinarySearch(*arr1, arr2->A[j]);
		if (temp == -1)
			arr3->A[k++] = arr2->A[j];
		j++;
	}

	arr3->length = k;
	arr3->size = 10;

	return arr3;
}

struct Array* UnsortIntersection(struct Array* arr1, struct Array* arr2)
{
	/*
		combine same elements of 2 unsorted arrays
	*/
	int i, k;
	i = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
	
	while (i < arr1->length)
	{
		int temp = BinarySearch(*arr2, arr1->A[i++]);
		if (temp != -1)
		{
			arr3->A[k++] = arr1->A[temp];
		}
	}

	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

struct Array* UnsortDifference(struct Array* arr1, struct Array* arr2)
{
	/*
		Find arr1's different elements from arr1 compare to arr2
	*/
	int i, k;
	i = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

	while (i < arr1->length)
	{
		int temp = BinarySearch(*arr2, arr1->A[i]);
		if (temp == -1)
		{
			arr3->A[k++] = arr1->A[i];
		}
		i++;
	}

	arr3->length = k;
	arr3->size = 10;
	return arr3;
}


int main()
{
	struct Array arr1;
	int ch;
	int x, index;

	printf("Enter Size of Array : ");
	cin >> arr1.size;
	arr1.length = 0;
	arr1.A = (int*)malloc(arr1.size * sizeof(int));
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
			Insert(&arr1, index, x);
			break;
		case 2: printf("Enter index: ");
			cin >> index;
			x = Delete(&arr1, index);
			printf("Deleted Element is %d\n", x);
			break;
		case 3: printf("Enter element to search");
			cin >> x;
			index = LinearSearch(&arr1, x);
			printf("Element index %d", index);
			break;
		case 4: printf("Sum is %d\n", Sum(arr1));
			break;
		case 5: Display(arr1);
			cout << endl;
		}
	} while (ch < 6);



	return 0;
}


void f1()
{
	//struct Array arr1 = { {2,6,10,15,25},10,5 };
//struct Array arr2 = { {3,6,7,15,20},10,5 };
//struct Array* arr3;
//struct Array* arr4;

//arr3 = UnsortDifference(&arr1, &arr2);
//arr4 = Difference(&arr1, &arr2);
//arr3 = Difference(&arr1, &arr2);

//arr3 = Intersection(&arr1, &arr2);

//arr3 = Union(&arr1, &arr2);

//arr3 = Merge(&arr1, &arr2);
//Display(*arr3);
//Display(*arr4);

//struct Array arr = { {2,-3,4,5,-16},10,5 };

//ReArrange(&arr);
//Display(arr);

//printf("%d\n", isSorted(arr));

//InsertSort(&arr, 10);
//Display(arr);

//RightShift(&arr);
//RightRotate(&arr);

//Reverse(&arr);
//Reverse2(&arr);
//Display(arr);

//printf("%f\n", Avg(arr));

//printf("%d\n", Max(arr));
//printf("%d\n", Min(arr));

//Set(&arr, 2, 15);
//printf("%d\n", Get(arr, 2));

//printf("%d\n", Get(arr, 2));

//printf("%d\n", RBinSearch(arr.A, 0, arr.length - 1, 5));

//printf("%d\n", BinarySearch(arr, 5));

//printf("%d\n", LinearSearch(&arr, 5));

//printf("%d\n", Delete(&arr, 0));

//Insert(&arr, 2, 10);

//Append(&arr, 10);
//Display(arr);

}
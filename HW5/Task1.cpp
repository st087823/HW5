#include <iostream>

using namespace std;

void fillArr(int* arr, int len) 
{
	for (int i = 0; i < len; i++) 
	{
		arr[i] = rand() % 90 + 10;
	}
}
void printArr(int* arr, int len) 
{
	for (int i = 0; i < len; i++) 
	{
		cout << arr[i] << "  ";
	}
	cout << endl << endl;
}

void swap(int& a, int& b) 
{
	int c = a;
	a = b;
	b = c;
}

void quickSort(int* arr, int left, int right) 
{
	if (left >= right) return;
	int l = left;
	int r = right;
	int pivot = arr[(l + r) / 2];
	do {
		while (arr[l] < pivot)
		{
			l++;
		}

		while (arr[r] > pivot)
		{
			r++;
		}
		if (l <= r)
		{
			swap(arr[l], arr[r]);
			l++;
			r--;
		}
	} while (l <= r);

	if (r > 0)
	{
		quickSort(arr, left, r);
	}

	if (l < r) 
	{
		quickSort(arr, right, l);
	}
}

int maxElement(int* arr, int size)
{
	int max = -1000;
	for (int i = 0; i < size; i++) 
	{
		if (arr[i] > max) 
		{
			max = arr[i];
		}
	}
	return max;
}

void countSort(int* arr, int size) 
{
	int k = maxElement(arr, size);
	int* c = new int[k + 1]{ 0 };

	for (int i = 0; i < size; i++) 
	{
		++c[arr[i]];
	}

	int b = 0;
	for (int i = 0; i < k + 1; i++) 
	{
		for (int j = 0; j < c[i]; j++) 
		{
			arr[b] = i;
			b++;
		}
	}
}

void merge(const int* countArr, const int* quickArr, int countSize, int quickSize, int* mergeArr)
{
	int i, j, k = 0;
	while (i < countSize && j < quickSize) 
	{
		if (countArr[i] < quickArr[i]) 
		{
			mergeArr[k++] = countArr[i++];
		}
		else 
		{
			mergeArr[k++] = quickArr[j++];
		}
	}
	while (i < countSize) 
	{
		mergeArr[k++] = countArr[i++];
	}
	while (j < quickSize) 
	{
		mergeArr[k++] = quickArr[j++];
	}
}



int main() 
{
	int countSize = 15;
	int* countArr = new int[countSize];
	fillArr(countArr, countSize);
	countSort(countArr, countSize);

	int quickSize = 15;
	int* quickArr = new int[quickSize];
	fillArr(quickArr, quickSize);
	countSort(quickArr, quickSize);

	printArr(countArr, countSize);
	printArr(quickArr, quickSize);

	int mergeSize = countSize + quickSize;
	int* mergeArr = new int[mergeSize] {0};
	merge(countArr, quickArr, countSize, quickSize, mergeArr);
	printArr(mergeArr, mergeSize);

	delete[] countArr;
	delete[] quickArr;
	delete[] mergeArr;

	return EXIT_SUCCESS;
}
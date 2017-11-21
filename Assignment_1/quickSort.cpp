// quickSort.cpp
// Author: Nel Toms 10/24/2017


#include <iostream>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <array>

using namespace std;

int Partition(int A[], int p, int r){
	int x = A[r];
	int i = p-1;

	for(int j = p; j < r; j++){
		if(A[j] <= x){
			i++;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	int temp = A[i+1];
	A[i+1] = A[r];
	A[r] = temp;

	return i+1;

}

void quickSort(int A[], int p, int r){
	//r = pivot.nextInt(10);
	if(p < r){
		int	q = Partition(A, p, r);
		quickSort(A, p, q-1);
		quickSort(A, q+1, r);
	}
}

void printArray(int *A, int size){
	for(int i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

void arrayFill(int *A, int n){
	for (size_t i = 0; i < n; i++)
		A[i] = (rand() % 10);
}	
int main(){

	srand((unsigned)time(0));
	clock_t t1, t2;
	// Set array size
	size_t ARRAY_SIZE = 1000000000;
	int* A = new int[ARRAY_SIZE];
	int n;
	// Randomize elements of array
	
	int array_size = sizeof(A)/sizeof(A[0]);

	// 10 elements
	n = 10;
	arrayFill(A, n);
	// MergeSort function call and runtime clock
	t1 = clock();
	quickSort(A, 0, n-1);
	t2 = clock() - t1;
	printArray(A, n);

	float diff ((float)t2-(float)t1);
	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	// 100 elements
	n = 100;
	arrayFill(A, n);
	// MergeSort function call and runtime clock
	t1 = clock();
	quickSort(A, 0, n-1);
	t2 = clock() - t1;
	
	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	// 1000 elements
	n = 1000;
	arrayFill(A, n);
	// MergeSort function call and runtime clock
	t1 = clock();
	quickSort(A, 0, n-1);
	t2 = clock() - t1;

	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	// 1000 elements
	n = 10000;
	arrayFill(A, n);
	// MergeSort function call and runtime clock
	t1 = clock();
	quickSort(A, 0, n-1);
	t2 = clock() - t1;

	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	// 1000 elements
	n = 100000;
	arrayFill(A, n);
	// MergeSort function call and runtime clock
	t1 = clock();
	quickSort(A, 0, n-1);
	t2 = clock() - t1;

	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	// 1000 elements
	n = 1000000;
	arrayFill(A, n);
	// MergeSort function call and runtime clock
	t1 = clock();
	quickSort(A, 0, n-1);
	t2 = clock() - t1;

	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	return EXIT_SUCCESS;
}

// mergeSort.cpp
// Author: Nel Toms 10/24/2017


#include <iostream>
#include <time.h>
#include <cstdlib>
#include <ctime>
#include <array>

using namespace std;

void merge(int *A, int p, int r, int q){
	
/*
	for(int i = 0; i < n1; i++)
		L[i] = A[p + i];
	
	for(int j = 0; j < n2; j++)
		R[j] = A[q + 1 + j];
*/
	int i = p, j = q+1, k = 0, temp[r-p+1];

	while (i <= q && j <= r){
		if(A[i] < A[j]){
			temp[k] = A[i];
			i++;
			k++;
		}
		else{
			temp[k] = A[j];
			j++;
			k++;
		}
		
	}
	while(i <= q){
		temp[k] = A[i];
		i++;
		k++;
	}
	while(j <= r){
		temp[k] = A[j];
		j++;
		k++;
	} 

	for(i = p; i < r; i++)
		A[i] = temp[i-p];
}

void mergeSort(int *A, int p, int r){
	if (p < r){
		int q = (r+p)/2;

		mergeSort(A, p, q);
		mergeSort(A, q+1, r);
		merge(A, p, r, q);
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
	mergeSort(A, 0, n-1);
	t2 = clock() - t1;

	float diff ((float)t2-(float)t1);
	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	// 100 elements
	n = 100;
	arrayFill(A, n);
	// MergeSort function call and runtime clock
	t1 = clock();
	mergeSort(A, 0, n-1);
	t2 = clock() - t1;
	
	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	// 1000 elements
	n = 1000;
	arrayFill(A, n);
	// MergeSort function call and runtime clock
	t1 = clock();
	mergeSort(A, 0, n-1);
	t2 = clock() - t1;

	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	// 1000 elements
	n = 10000;
	arrayFill(A, n);
	// MergeSort function call and runtime clock
	t1 = clock();
	mergeSort(A, 0, n-1);
	t2 = clock() - t1;

	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	// 1000 elements
	n = 100000;
	arrayFill(A, n);
	// MergeSort function call and runtime clock
	t1 = clock();
	mergeSort(A, 0, n-1);
	t2 = clock() - t1;

	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	// 1000 elements
	n = 1000000;
	arrayFill(A, n);
	// MergeSort function call and runtime clock
	t1 = clock();
	mergeSort(A, 0, n-1);
	t2 = clock() - t1;

	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	return EXIT_SUCCESS;

	
}

// heapSort.cpp
// Author: Nel Toms 10/24/2017



#include<iostream>
#include<time.h>
#include<cstdlib>
#include<ctime>
#include<stdlib.h>

using namespace std;

void MaxHeapify(int A[], int i, int n){

	int l = 2*i;
	int r = 2*i+1;
	int largest;

	if ((l <= n) && (A[l] > A[i]))
		largest = l;
	else
		largest = i;
	if ((r <= n) && (A[r] > A[largest]))
		largest = r;
	if (largest != i){
		int temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		MaxHeapify(A, largest, n);
	}
}

void buildMaxHeap(int A[], int n){
	for(int i = n/2; i >= 1; i--)
		MaxHeapify(A, i, n);
}


void heapSort(int A[], int n){
	buildMaxHeap(A, n);
	for(int i = n; i >= 2; i--){
		int temp = A[i];
		A[i] = A[1];
		A[1] = temp;
		MaxHeapify(A, 1, i-1);
	}
}

void fillArray(int A[], int n){
	for (size_t i = 0; i < n; i++)
		A[i] = (rand() % 10);
}


void printArray(int A[], int n){
	for (size_t i = 0; i < n; i++)
		cout << A[i];
}



int main(){
	
	srand((unsigned)time(0));
	clock_t t1 = clock();
	clock_t t2 = clock();

	// 10 elements
	const size_t ARRAY_SIZE = 10000000;
	int *A = new int[ARRAY_SIZE];
	int n = 10;
	fillArray(A, n);


	t1 = clock();
	heapSort(A, n);
	t2 = clock() - t1;
	printArray(A, n);
	cout << "\n";

	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	// 100 elements

	n = 100;
	fillArray(A, n);

	t1 = clock();
	heapSort(A, n);
	t2 = clock() - t1;
	printArray(A, n);
	cout << "\n";

	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	// 1,000 elements

	n = 1000;
	fillArray(A, n);

	t1 = clock();
	heapSort(A, n);
	t2 = clock() - t1;

	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	// 10,000 elements

	n = 10000;
	fillArray(A, n);

	t1 = clock();
	heapSort(A, n);
	t2 = clock() - t1;

	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	// 100,000 elements

	n = 100000;
	fillArray(A, n);

	t1 = clock();
	heapSort(A, n);
	t2 = clock() - t1;

	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	// 1,000,000 elements

	n = 1000000;
	fillArray(A, n);

	t1 = clock();
	heapSort(A, n);
	t2 = clock() - t1;

	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;


	return EXIT_SUCCESS;
	
}


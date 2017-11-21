// insertionSort.cpp
// Author: Nel Toms 10/24/2017



#include<iostream>
#include<time.h>
#include<cstdlib>
#include<ctime>
#include<stdlib.h>



using namespace std;

void insertionSort(int *A, int n){
	for (size_t j = 1; j < n; j++) {
		int i;
		int key;
		key = A[j];
		i = j - 1;
		while (i >= 0 && A[i] > key){
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}

void fillArray(int *A, int n){
	for (size_t i = 0; i < n; i++)
		A[i] = (rand() % 10);
}


void printArray(int *A, int n){
	for (size_t i = 0; i < n; i++)
		cout << A[i];
}


int main(){
	
	srand((unsigned)time(0));
	clock_t t1 = clock();
	clock_t t2 = clock();

	// 10 elements
	const int ARRAY_SIZE = 10000000;
	int *A = new int[ARRAY_SIZE];
	int n = 10;
	fillArray(A, n);


	t1 = clock();
	insertionSort(A, n);
	t2 = clock() - t1;


	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	// 100 elements

	n = 100;
	fillArray(A, n);

	t1 = clock();
	insertionSort(A, n);
	t2 = clock() - t1;

	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	// 1,000 elements

	n = 1000;
	fillArray(A, n);

	t1 = clock();
	insertionSort(A, n);
	t2 = clock() - t1;
	
	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	// 10,000 elements

	n = 10000;
	fillArray(A, n);

	t1 = clock();
	insertionSort(A, n);
	t2 = clock() - t1;

	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	// 100,000 elements

	n = 100000;
	fillArray(A, n);

	t1 = clock();
	insertionSort(A, n);
	t2 = clock() - t1;

	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;

	// 1,000,000 elements

	n = 1000000;
	fillArray(A, n);

	t1 = clock();
	insertionSort(A, n);
	t2 = clock() - t1;

	cout << "Runtime for " << n << " elements: " << (float)t2 / CLOCKS_PER_SEC << endl;


	return EXIT_SUCCESS;
}

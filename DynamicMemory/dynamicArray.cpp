#include<iostream>
#include<cstdlib>
#include<cassert>

using namespace std;

void allocate_doubles(double*&, size_t& n);
void fill_array(double data[], size_t n);
void compare(const double data[], size_t n, double value);
double average(const double data[], size_t n);


int main()
{
	double *numbers;
	size_t array_size;
	double mean_value;

	// Allocate an array of double to hold the user's input.
	cout << "This program will compute the average of some numbers. The\n";
	cout << "numbers will be stored in an array of doubles that I allocate.\n";
	allocate_doubles(numbers, array_size);

	// Read the user's input and comput the average.
	fill_array(numbers, array_size);
	mean_value = average(numbers, array_size);

	// Print the output.
	cout << "The average is: " << mean_value << endl;
	compare(numbers, array_size, mean_value);
	cout << "This was a mean program.\n";
	
	return EXIT_SUCCESS;

}

void allocate_doubles(double*& p, size_t& n)
{
	cout << "How many doubles should I allocate?" << endl;
	cout << "Please type a positve integer answer: ";
	cin >> n;
	p = new double[n];

}

void fill_array(double data[], size_t n)
{
	cout << "Please type " << n << " double numbers: " << endl;

	for (size_t i = 0; i <  n; ++i) {
		cin >> data[i];
	}

}

void compare(const double data[], size_t n, double value)
{
	for (size_t i = 0; i < n; ++i) {
		cout << data[i];
		if(data[i] < value)
			cout << " is less than ";
		else if(data[i] > value)
			cout << " is more than ";
		else
			cout << " is equal to ";
		cout << value << endl;
	}
}

double average(const double data[], size_t n)
{
	double sum;
	assert(n > 0);

	sum = 0;
	for (size_t i = 0; i < n; ++i) 
		sum += data[i];
	return(sum/n);

}


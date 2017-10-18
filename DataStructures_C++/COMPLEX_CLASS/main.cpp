#include<cstdlib>
#include "Complex.h"

using std::cout;
using std::cin;
using namespace main_Complex_1;

void inputs(Complex&, Complex&);

int main()
{
	char r;
	while(r == 'y' || r != 'n')
	{


	Complex a(0, 0);
	Complex b(0, 0);
	
	inputs(a, b);

	Complex d = a + b;
	Complex e = a-= b;

	cout << "The addition of your numbers is: "; d.print();
	cout << "\n";
	cout << "The subtraction of your numbers is: "; e.print();
	cout << "\n";

	cout << "Would you like to choose more numbers? Press 'y' for yes or 'n' for no... \n";
	cin >> r;

	}

	return 0;
}

void inputs(Complex& a, Complex& b)
	{
		cout << "Enter first set of real and imaginary numbers: \n";
		cin >> a;
		cout << "Your first set is: " << a << "\n";
		cout << "Enter second set of real and imaginary numbers: \n";
		cin >> b;
		cout << "Your second set is: " <<  b << "\n";
	}

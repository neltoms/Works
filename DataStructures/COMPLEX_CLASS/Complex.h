// Why should we not use a default constructor in this case?
//
// Default constructors initialize objects without presenting any parameters or 
// arguments. Not creating one can be used for safety reasons, i.e., not allowing a user
// to initialize an object without parameteres when adding parameters to the object is 
// important or necessary when using the class.  It creates a higher level of control over
// preconditions.
//
// CONSTRUCTOR for the Complex class:
// 		Complex(double, double)
// 		Postcondition: member variables will be initialized
//
// MODIFICATION MEMBER FUNCTIONS
// 		void print()
// 		Postcondtion: print std input of complex numbers to std output
//
// CONSTANT MEMBER FUNCTIONS
// 		double getReal() const;
// 		Postcondition: the real value is returned
//
// 		double getImag() const;
// 		Postconditon: the imaginary value is returned
// 		
// FRIEND FUNCTIONS
// 		friend Complex sum(Complex, Complex);
// 		Precondition: one full complex number must be entered into each argument
// 		Postcondition: the result is the sum of two complex numbers printed to std output
//
// 		friend Complex diff(Complex, Complex);
// 		Precondition: one full complex number must be entered into each argument
// 		Postcondition: the result is the difference of two complex numbers printed to std output
//
// 		friend ostream& operator<<(ostream& os, const Complex& right);
// 		Postcondition: the real and imaginary values of right have been written to os.
// 		the return value is the ostream os.
// 		
// 		friend istream& operator>>(istream& is, Complex& right);
// 		Postcondition: the real and imaginary vlaues of right have been written to is.
// 		The return value is the istream is.
//
// MEMBER OPERATOR OVERLOADS
//      bool operator==(const Complex&) const;
// 		Postcondition: the return value is true is 'this' and the right side is equal
//
//		bool operator!=(const Complex&) const;
//		Postcondition: the return value is true is 'this' and the right side is not equal
//
//		Complex& operator+=(const Complex&);
//		Postcondition: the right side is added to the value of'this'
//
//		Complex& operator-=(const Complex&);
//		Postcondition: the right side is subtracted from the value of 'this'
//
//		Complex& operator+(const Complex&);
//		Postconditon: the sum of real and imag is returned
//
//		Complex& operator-(const Complex&);
//		Postconditon: the difference of real and imag is returned
//


#ifndef NTHARLEM_COMPLEX_H
#define NTHARLEM_COMPLEX_H
#include<iostream>

namespace main_Complex_1
{
	class Complex
	{
		public:
			// CONSTRUCTOR
			Complex(double, double);
		
		
			// MODIFICATION MEMBER FUNCTIONS
			void print();

			// CONSTANT MEMBER FUNCTIONS
			double getReal() const { return real; };
			double getImag() const { return imag; };

			// FRIEND FUNCTIONS
			friend Complex sum(Complex, Complex);
			friend Complex diff(Complex, Complex);
			friend std::ostream& operator<<(std::ostream& os, const Complex& right);
			friend std::istream& operator>>(std::istream& is, Complex& right);
		
			// MEMBER OPERATOR OVERLOADS
           	bool operator==(const Complex&) const;
			bool operator!=(const Complex&) const;
			Complex& operator+=(const Complex&);
			Complex& operator-=(const Complex&);
			Complex& operator+(const Complex&);
			Complex& operator-(const Complex&);
	
		private:
			// PRIVATE MEMBER VARIABLES
			double real;
			double imag;
	
	};
			// NON-MEMBER OPERATOR OVERLOADS
			std::ostream& operator<<(std::ostream& os, const Complex& right);
			std::istream& operator>>(std::istream& is, Complex& right);

	
}


#endif

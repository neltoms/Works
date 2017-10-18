#include "Complex.h"



namespace main_Complex_1
{
	
	Complex::Complex(double re, double im)
	{
		real = re;
		imag = im;
	}

	void Complex::print()
	{
		std::cout << "("<< real << " + " << imag << "i)" << "\n";
	}

	// OPERATOR OVERLOADS
	Complex& Complex::operator+=(const Complex& right)
	{
		static Complex result(real, imag);
		result.real = this->real + right.getReal();
		result.imag = this->imag + right.getImag();

		return result;
	}

	Complex& Complex::operator-=(const Complex& right)
	{
		static Complex result(real, imag);
		result.real = this->real - right.getReal();
		result.imag = this->imag - right.getImag();

		return result;
	}

	Complex& Complex::operator+(const Complex& right)
	{
		static Complex result(real, imag);
		result.real = (this->real + right.getReal());
		result.imag = (this->imag + right.getImag());

		return result;
	}

	Complex& Complex::operator-(const Complex& right)
	{
		static Complex result(real, imag);
		result.real = (this->real - (right.getReal()));
		result.imag = (this->imag - (right.getImag()));

		return result;
	}

	bool Complex::operator==(const Complex& right) const
	{
		return (real == right.getReal()) && (imag == right.getImag());

	}

	bool Complex::operator!=(const Complex& right) const
	{
		return (!((*this) == right));

	}

	std::ostream& operator<<(std::ostream& os, const Complex& right) 
	{
		os << "(" << right.real << " + " << right.imag << "i)" << "\n";

		return os;
	}

	std::istream& operator>>(std::istream& is, Complex& right)
	{
		std::cout << "Enter a: ";
		is >> right.real;
		std::cout << "Enter b: ";
		is >> right.imag;

		return is;
	}



	/* NON-MEMBER FUNCTIONS
	Complex sum(Complex c1, Complex c2)
	{
		
		double x =(c1.getReal() + c2.getReal());
		double y = (c1.getImag() + c2.getImag());
		Complex c(x, y);
		c.print();
	}

	Complex diff(Complex c1, Complex c2)
	{
		
		double x = c1.getReal() - c2.getReal();
		double y = c1.getImag() - c2.getImag();
		Complex c(x, y);
		c.print();
	}

	*/



}



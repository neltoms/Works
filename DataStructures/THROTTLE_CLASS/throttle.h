#ifndef TEST_POINT_H
#define TEST_POINT_H
#include <cassert>

class throttle
{
	public:
		// CONSTRUCTOR
		throttle(); // DEFAULT CONSTRUCTOR: no params
		throttle(int size); // has to be the same name as the class and 
							// contain no return type
		// MODIFICATION MEMBER FUNCTIONS: can change the value of an object
		void shut_off() { position = 0; }
		void shift(int amount);
		// CONSTANT MEMBER FUNCTIONS: cannot change the value of an object, but instead examine
		// the status of and object.
		double flow() const { return position / double(top_position); }
		bool is_on() const { return (position > 0); }
	private:
		//PRIVATE MEMBER VARIABLES
		int top_position; // to keep track of how many positions the throttle has
		int position;
};

// Member Function Implementation
/*
void throttle::shut_off()
// Precondition: None.
// Postcondition: The throttle has been turned off.
{
	position = 0;
}
*/
void throttle::shift(int amount)
// Precondition: shut_off has been called at least once to initialize the throttle
// Postcondition: The throttle's position has been moved by the amount (but not below
// 0 or above top position).
{
	position += amount; // add the input 'amount' to position = 0.

	if(position < 0)
		position = 0;
	else if(position > top_position)
		position = top_position;
}
/*
double throttle::flow() const
// Precondition: shut_off has been called at least once to initialize the throttle
// Postcondition: value returned will be set to n/6/
{
	return position / 6.0;
}

bool throttle::is_on() const
// Precondition: shut_off has been called at least once to intialize the throttle.
// Postcondition: If the throttle's position is above 0, then the function returns
// true; otherwise, it returns false.
{
	return (flow() > 0 );
}
*/
// IMPLEMENTATIONS OF THE CONSTRUCTORS

throttle::throttle()
{
	int top_position = 1;
	int position = 0;
}

throttle::throttle(int size)
// Library facilities used: cassert
{
	assert(0 < size);
	top_position = size;
	position = 0;
}

#endif

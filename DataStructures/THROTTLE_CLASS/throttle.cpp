#include<iostream> // Provides EXIT_SUCCESS
#include<cstdlib>
#include "throttle.h"
using namespace std;

/*
class throttle
{
	public:
		//MODIFICATION MEMBER FUNCTIONS: can change the value of an object
		void shut_off();
		void shift(int amount);
		//CONSTANT MEMBER FUNCTIONS: cannot change the value of an object, but instead examine
		//the status of and object.
		double flow() const;
		bool is_on() const;
	private:
		//PRIVATE MEMBER VARIABLES
		int position;
};
*/

int main(){
	
 throttle control; // throttle objects/instances/variables (objects of a class)
 throttle my_throttle; // throttle object/instance/variable
 int user_input;
 
 control.shut_off( ); // throttle object tied to a member function
  	cout << "Please type a number from 0 to 6: ";
 	cin >> user_input;

 control.shift(user_input); // throttle object tied to a member function
	
	if (control.is_on( ))
		cout << "The flow is " << control.flow( ) << endl;
	else
		cout << "The flow is now off" << endl;
	
	return EXIT_SUCCESS;
}

/*
// Member Function Implementation

void throttle::shut_off()
// Precondition: None.
// Postcondition: The throttle has been turned off.
{
	position = 0;
}

void throttle::shift(int amount)
// Precondition: shut_off has been called at least once to initialize the throttle
// Postcondition: The throttle's position has been moved by the amount (but not below
// 0 or above 6).
{
	position += amount; // add the input 'amount' to position = 0.

	if(position < 0)
		position = 0;
	else if(position > 6)
		position = 6;
}

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

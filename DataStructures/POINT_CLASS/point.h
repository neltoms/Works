// CONSTRUCTOR for the point class:
// 	point(double initial_x_amount, double y_amount)
// 	Postcondition: The oiont has been set to (initial_x, initial_y).
//
// MODIFCATION MEMBER FUNCTIONS for the point class:
// 	void shift(double x_amount, double y_amount)
// 	Postscondition: The poin has been moved by x_amount along the x axis
// 	and by y_amount along the y axis.
//
// 	void rotate90()
// 	Postcondition: The point has been rotated clockwise 90 degrees around
// 	the origin.
// 
// CONSTANT MEMBER FUNCTIONS for the point class:
// 	double get_x() const
// 	Postcondition: The value returned is the x coordinate of the point.
//
// 	double get_y() const
// 	Postcondition: The value returned is the y coordinate of the point.
//
// VALUE SEMATICS for the point class:
// 	Assignments and the conp constructor may be used with point objects.


#ifndef TEST_POINT_H
#define TEST_POINT_H

namespace point_stuff_1
{
	
class point {
	public:
	/*	point();  NOTE: constructor is responsible for initializing the member variables of the object can be either public or private*/

		// CONSTRUCTOR
		point(double initial_x = 0, double initial_y = 0);

		// MODIFICATION MEMBER FUNCTIONS
		void shift(double x_amount, double y_amount);
		void rotate90();

		// CONSTANT MEMBER FUNCTIONS
		double get_x() const { return x; } /*function running inline (i.e., uses more memory at runtime but
										   runs faster). it executes the stmt one line at a time.  not inline
										   compiles multiple times. */
		double get_y() const { return y; }

	private:
		double x; // x coordinate of this point
		double y; // y coordinate of this point
		
};


}

#endif


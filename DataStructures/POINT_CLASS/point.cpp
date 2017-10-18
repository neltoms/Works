#include "point.h"
#include <iostream>

namespace point_stuff_1
{

	point::point(double initial_x, double initial_y)
	{
		x = initial_x;
		y = initial_y;
	}

	void point::shift(double x_amount, double y_amount)
	{
		x += x_amount;
		y += y_amount;
	}

	void point::rotate90()
	{
		double new_x;
		double new_y;

		new_x = y;
		new_y = -x;
		x = new_x;
		y = new_y;
	}

	/*
	int rotations_needed(point p)
	{
		int answer;
		answer = 0;

		while ((p.get_x() < 0) || (p.get_y() < 0))
		{
			p.rotate90();
			++answer;
		}
		return answer;
	}
	*/


}

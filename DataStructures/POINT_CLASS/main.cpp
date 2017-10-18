#include <iostream>
#include "point.h"
using namespace std;


int main(){

	point p(1, 10);

	p.set_position(1, 10); // inline: -> p.m_x = 1; p.m_y = 10
	p.set_position(1, 10); // not inline -> &p.set...

	p.x(); // inline: p.x() -> p.m_x;
	p.x(); // not inline: p.x() -> &p.x(); 

	return 0;
}

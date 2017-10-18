#include <cmath>
#include "Sequence.h"

using namespace std;
using namespace ntcage_main_1;


int main()
{

	double it =  pow(10, 9);
	Sequence array(it);
	for (size_t i = 0; i < it; i++) 
	{

		array.insert(i);

	}

	
	cout << "capacity of array: " << array.get_cap() << "\n";
	cout << "size of array: " << array.size() << "\n";

	cout << endl;


	return EXIT_SUCCESS;
}


// I ran the code with and without the destructor and I noticed no apparent change in memory.
// I believe this is because if there is no destructor defined the compiler will implicitly
// define one for me.  If I call the destructor in main (i.e., array.~Sequence(), I get an error stating:
// "pointer being freed was not allocated".


#include <iostream>
#include <string>
#include <cstdlib>
#include "node.h"
#include "LinkedBag.h"


using namespace std;
using namespace ntcage_main_1;

int main()
{
	LinkedBag household;
	
	household.insert("couple");
	household.insert("Ella");
	household.insert("Ella");
	household.insert("Ella");
	household.insert("Ella");
	household.insert("Nel");
	household.insert("Steve");

	cout << household.size();
	cout << endl;
	cout << household.grab();
	cout << endl;
	cout << household.count("Ella") << "\n";
	

	
		


	return EXIT_SUCCESS;
}	

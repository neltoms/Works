#include <iostream>
#include <cstdlib>
#include "Table.h"
#include "bintree.h"

using namespace std;
using namespace ntcage_main_1;

int main()
{
	HashTable<int> hash;


	hash.insert_hash(1, 42);
	hash.insert_hash(3, 15678);
	hash.insert_hash(6, 97);
	hash.insert_hash(12, 17);
	hash.insert_hash(4, 654);
	hash.insert_hash(13, 654);
	hash.insert_hash(15, 654);
	hash.insert_hash(22, 654);
	hash.insert_hash(2, 654);
	hash.insert_hash(20, 654);
	hash.insert_hash(10, 654);
	
	cout << hash.find(3);
	cout << endl;
	hash.print_list();
	cout << endl;

	

	


	 return EXIT_SUCCESS;
}

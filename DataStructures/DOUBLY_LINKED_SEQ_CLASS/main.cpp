#include<cstdlib>
#include<iostream>

#include "DblyLinkdSeq.h"
#include "dbl_node.h"

using namespace std;
using namespace ntcage_main_1;



int main()
{
	DblyLinkdSeq<int> head;
	DblyLinkdSeq<int> tail;
	DblyLinkdSeq<int> n;

	n.insert_first(1);
	n.insert_first(2);
	n.insert_first(3);
	n.insert_first(4);


	dbl_node_iterator<int> it;

	for(it = n.begin(); it != n.end(); ++it)
	{
		cout << *it << endl;
	}

	return EXIT_SUCCESS;

}

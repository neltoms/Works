#include <iostream>
#include <cstdlib>
#include "node.h"

using namespace std;
using namespace ntcage_main_1;


int main()
{

	node *head_ptr;
	node *z;
	node *l;
	node *m;
	node *r;
	
	l = new node;
	m = new node;
	r = new node;
	head_ptr = l;




//	head_ptr->set_link(l);
	l->set_data(5);
	l->set_link(m);
	m->set_data(6);
	m->set_link(r);
	r->set_data(7);
	r->set_link(NULL);

	node *ins_ptr;
	ins_ptr = m->link();
	list_head_insert(ins_ptr, 6.5);
	m->set_link(ins_ptr);

	node *rm_ptr;
	rm_ptr = head_ptr->link();
	head_ptr = rm_ptr->link();
	delete rm_ptr;

	
	cout << list_length(head_ptr) << "\n";
	
//	list_head_insert(z, 22);

//	cout << list_length(head_ptr) << "\n";

//	cout << head_ptr->data() << "\n";
//	cout << z->data() << "\n";
	cout << l->data() << "\n";
	cout << m->data() << "\n";
	cout << ins_ptr->data() << "\n";
	cout << r->data() << "\n";
	


	return EXIT_SUCCESS;
}

// ANSWER TO QUESTION #3:
// 	The advantage of a doubly linked list is the ease in which we can insert and delete
// 	items from the linked list. To delete using a singly linked list, we need to know 
// 	the previous location of the previous node. This would require us to traverse the 
// 	list. If we know the node we would like to delete, we can simply use the previous
// 	pointer.


#include<iostream>
#include<cstdlib>
#include "LinkedSeq.h"
#include "nodeT.h"

using namespace std;
using namespace ntcage_main_1;

void printLinkedSeq(LinkedSeq<int>);

int main()
{
	cout << "*************************************************" << endl;
	cout << "Test Program" << endl;
	cout << "*************************************************" << endl;

	// Test constructor by creating an object
	cout << "Create first LinkedSeq object" << endl;
	LinkedSeq<int> testOne;
	
	printLinkedSeq(testOne);

	// Test insert_first function
	cout << "*************************************************" << endl;
	cout << "Add four values using insert_first" << endl;
	testOne.insert_first(100.0);
	testOne.insert_first(200.0);
	testOne.insert_first(300.0);
	testOne.insert_first(400.0);
	printLinkedSeq(testOne);

	// Test erase_first and erase_last
	cout << "*************************************************" << endl;
	cout << "Remove two values using erase_first and erase_last" << endl;
	testOne.erase_first();
	testOne.erase_last();
	printLinkedSeq(testOne);
	
	// Test erase_from and insert "last" and insert_at
	cout << "*************************************************" << endl;
	cout << "Remove one value using erase_from" << endl;
	testOne.insert(600034);
	testOne.insert_at(3, 123);	
	testOne.erase_from(200);	
	testOne.insert_first(1000.0);
	printLinkedSeq(testOne);
	
	// Test copy constructor
	cout << "*************************************************" << endl;
	cout << "Test Copy Constructor" << endl;
	LinkedSeq<int> testTwo(testOne);
	printLinkedSeq(testTwo);

	system("Pause");
	return EXIT_SUCCESS;



}

void printLinkedSeq(LinkedSeq<int> testSeq)
{
	// Display current state of an object
	cout << "Current Size: " << testSeq.size() << endl;
	if (testSeq.is_item())
	{
		cout << "Current value of is_item is True" << endl;
		cout << "Current value: " << testSeq.current() << endl;
	}
	else
		cout << "Current value of is_item is False" << endl;
	if (testSeq.size() > 0)
	{
		cout << "Sequence values: " << endl;
		for(testSeq.start(); testSeq.is_item(); testSeq.advance())
			cout << testSeq.current() << " ";
	}
	cout << endl;
}
	/*
	node<std::string> *testNode;
	node<std::string> *l;

	l = new node<std::string>;
	testNode = new node<std::string>;

	testNode->set_data("Hello");
	testNode->set_link(l);
	l->set_data("World");
	l->set_link(NULL);

	cout << "testNode data: " << testNode->data() << endl;
	cout << "testNode link: " << testNode->link() << endl;
	cout << "l data: " << l->data() << endl;
	cout << "l link: " << l->link() << endl;
	*/
	

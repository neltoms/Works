// FILE: nodeT.h (part of the namespace ntcage_main_1)
//  PROVIDES: A template class for a node in a doubly linked list and functions for
//  manipulating linked lists. The template parameter is the type of data in each node.
//
//  ALSO PROVIDES: A template class for an iterator in a linked list and functions for
//  manipulating linked list with iterators.
// 
//  TYPEDEF for the node<Item> template class:
//  	Each node of the list contains a piece of data and a pointer to the next node. The
//  	type of the data (node<Item>::value_type) is the Item type from the template parameter.
//  	The type may be any of the C++ built-in types (int, char, etc.), or a class with a default
//  	constructor, an assignment operator, and a test for equality.
// 
//  CONSTRUCTOR for the node<Item> class:
//  	node(const Item& init_data = Item(), node* init_link = NULL, node* init_prevlink = NULL)
//  		Postcondition: The node contains the specified data and link.
//  		NOTE: The init_data parameter has a default value that is obtained from the default
//  		constructor of the Item type. In the ANSI/ISO standard, this notation is also allowed
//  		for the built-in types, providing a default value of zero. The init_link has a default
//  		value of NULL.
//  NOTE about const and non-const versions of the data and link member functions:
// 		The data function returns a reference to the data field of a node, and the link function
//  	returns a copy of the link field of a node. Each of these functions comes in two versions: a
//  	const version and a non-const version. If the function is activated by a const node, then
//  	the compiler chooses the const version (and the return value is const). If the function is
//  	activated by a non-const node, then the compiler chooses the non-const version (and the
//  	return value will be non-const).o
//
// NONMEMBER FUNCTIONS to manipulate nodes:
//	template <class Item>
//	std::size_t list_length(const node<Item>* head_ptr);
//
//	template <class Item>
//	void list_head_insert(node<Item>*& head_ptr, const Item& entry);
//
//	template <class Item>
//	void list_insert(node<Item>* previous_ptr, const Item& entry);
//	
//	template <class NodePtr, class Item>
//	NodePtr list_search(NodePtr head_ptr, const Item& target);
//
//	template <class NodePtr, class Item>
//	NodePtr list_search(NodePtr head_ptr, const Item& target);
//
//	template <class NodePtr, class SizeType>
//	NodePtr list_locate(NodePtr head_ptr, SizeType position);
//
//	template <class Item>
//	void list_head_remove(node<Item>*& head_ptr);
//
//	template <class Item>
//	void list_remove(node<Item>* previous_ptr);
//
//	template <class Item>
//	void list_clear(node<Item>*& head_ptr);
//	
//	template <class Item>
//	void list_copy(const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr);
//
//


#ifndef NTCAGE_NODE_T_H
#define NTCAGE_NODE_T_H

#include <cstdlib>
#include <string>

namespace ntcage_main_1
{
	template <class Item>
	class node
	{
		public:
			typedef Item value_type;

			// CONSTRUCTOR
			node(const Item& init_data = Item(), node* init_link = NULL)
				{ data_field = init_data; link_field = init_link; }

			// MODIFICATION MEMBER FUNCTIONS
			node* link() { return link_field; }
			Item& data() { return data_field; }
			void set_data(const Item& new_data) { data_field = new_data; }
			void set_link(node* new_link) { link_field = new_link; }

			// CONSTANT MEMBER FUNCTIONS 
			const Item& data() const { return data_field; }
			const node* link() const { return link_field; }


		private:
			Item data_field;
			node *link_field;
	};

	// FUNCTIONS for the linked-list tool-kit
	template <class Item>
	std::size_t list_length(const node<Item>* head_ptr);

	template <class Item>
	void list_head_insert(node<Item>*& head_ptr, const Item& entry);

	template <class Item>
	void list_insert(node<Item>* previous_ptr, const Item& entry);
	
	template <class NodePtr, class Item>
	NodePtr list_search(NodePtr head_ptr, const Item& target);

	template <class NodePtr, class Item>
	NodePtr list_search(NodePtr head_ptr, const Item& target);

	template <class NodePtr, class SizeType>
	NodePtr list_locate(NodePtr head_ptr, SizeType position);

	template <class Item>
	void list_head_remove(node<Item>*& head_ptr);

	template <class Item>
	void list_remove(node<Item>* previous_ptr);

	template <class Item>
	void list_clear(node<Item>*& head_ptr);
	
	template <class Item>
	void list_copy(const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr);

	template <class Item>
		class node_iterator
		: public std::iterator<std::forward_iterator_tag, Item>
		{
		public:
			node_iterator(node<Item>* initial = NULL)
				{ current = initial; }
			Item& operator*() const
				{ return current->data(); } 
			node_iterator& operator++() // ++Prefix
				{ current = current->link(); return *this; }
			node_iterator operator++(int) // Postfix++
			{
				node_iterator original(current);
				current = current->link();
				return original;
			}
			bool operator==(const node_iterator other) const
				{ return current == other.current; }
			bool operator!=(const node_iterator other) const
				{ return current != other.current; }

		private:
			node<Item>* current;

		};

	template <class Item>
		class const_node_iterator
		: public std::iterator<std::forward_iterator_tag, const Item>
		{
		public:
			const_node_iterator(const node<Item>* initial = NULL)
				{ current = initial; }
			const Item& operator*() const
				{ return current->data(); } 
			const_node_iterator& operator++() // ++Prefix
				{ current = current->link(); return *this; }
			const_node_iterator operator++(int) // Postfix++
			{
				const_node_iterator original(current);
				current = current->link();
				return original;
			}
			bool operator==(const const_node_iterator other) const
				{ return current == other.current; }
			bool operator!=(const const_node_iterator other) const
				{ return current != other.current; }

		private:
			const node<Item>* current;

		};
}

#include "nodeT.template"
#endif


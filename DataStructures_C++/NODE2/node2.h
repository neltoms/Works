
// FILE: dbl_node.h (part of the namespace ntcage_main_1)
//  PROVIDES: A template class for a dbl_node in a doubly linked list and functions for
//  manipulating linked lists. The template parameter is the type of data in each dbl_node.
//
//  ALSO PROVIDES: A template class for an iterator in a linked list and functions for
//  manipulating linked list with iterators.
// 
//  TYPEDEF for the dbl_node<Item> template class:
//  	Each dbl_node of the list contains a piece of data and a pointer to the next dbl_node. The
//  	type of the data (dbl_node<Item>::value_type) is the Item type from the template parameter.
//  	The type may be any of the C++ built-in types (int, char, etc.), or a class with a default
//  	constructor, an assignment operator, and a test for equality.
// 
//  CONSTRUCTOR for the dbl_node<Item> class:
//  	dbl_node(const Item& init_data = Item(), dbl_node* init_link = NULL, dbl_node* init_prevlink = NULL)
//  		Postcondition: The dbl_node contains the specified data and link.
//  		NOTE: The init_data parameter has a default value that is obtained from the default
//  		constructor of the Item type. In the ANSI/ISO standard, this notation is also allowed
//  		for the built-in types, providing a default value of zero. The init_link has a default
//  		value of NULL.
//  NOTE about const and non-const versions of the data and link member functions:
// 		The data function returns a reference to the data field of a dbl_node, and the link function
//  	returns a copy of the link field of a dbl_node. Each of these functions comes in two versions: a
//  	const version and a non-const version. If the function is activated by a const dbl_node, then
//  	the compiler chooses the const version (and the return value is const). If the function is
//  	activated by a non-const dbl_node, then the compiler chooses the non-const version (and the
//  	return value will be non-const).o
//
// NONMEMBER FUNCTIONS to manipulate dbl_nodes:
//	template <class Item>
//	std::size_t list_length(const dbl_node<Item>* head_ptr);
//
//	template <class Item>
//	void list_head_insert(dbl_node<Item>*& head_ptr, const Item& entry);
//
//	template <class Item>
//	void list_insert(dbl_node<Item>* previous_ptr, const Item& entry);
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
//	void list_head_remove(dbl_node<Item>*& head_ptr);
//
//	template <class Item>
//	void list_remove(dbl_node<Item>* previous_ptr);
//
//	template <class Item>
//	void list_clear(dbl_node<Item>*& head_ptr);
//	
//	template <class Item>
//	void list_copy(const dbl_node<Item>* source_ptr, dbl_node<Item>*& head_ptr, dbl_node<Item>*& tail_ptr);
//
//


#ifndef NTCAGE_DBL_NODE_H
#define NTCAGE_DBL_NODE_H

#include <cstdlib>

namespace ntcage_main_1
{
	template <class Item>
	class dbl_node
	{
		public:
			typedef Item value_type;

			// CONSTRUCTOR
			dbl_node(const Item& d = Item(), dbl_node* n = NULL, dbl_node* p = NULL)
				{ data_field = d; next_field = n; prev_field = p; }

			// MODIFICATION MEMBER FUNCTIONS
			dbl_node* next() { return next_field; }
			dbl_node* prev() { return prev_field; }
			Item& data() { return data_field; }
			void set_data(const Item& new_data) { data_field = new_data; }
			void set_next(dbl_node* new_next) { next_field = new_next; }
			void set_prev(dbl_node* new_prev) { prev_field = new_prev; }

			// CONSTANT MEMBER FUNCTIONS 
			const Item& data() const { return data_field; }
			const dbl_node* next() const { return next_field; }
			const dbl_node* prev() const { return prev_field; }


		private:
			Item data_field;
			dbl_node *next_field;
			dbl_node *prev_field;
	};

	// FUNCTIONS for the linked-list tool-kit
	template <class Item>
	std::size_t list_length(const dbl_node<Item>* head_ptr);

	template <class Item>
	void list_head_insert(dbl_node<Item>*& head_ptr, const Item& entry);

	template <class Item>
	void list_insert(dbl_node<Item>* previous_ptr, const Item& entry);
	
	template <class NodePtr, class Item>
	NodePtr list_search(NodePtr head_ptr, const Item& target);

	template <class NodePtr, class Item>
	NodePtr list_search(NodePtr head_ptr, const Item& target);

	template <class NodePtr, class SizeType>
	NodePtr list_locate(NodePtr head_ptr, SizeType position);

	template <class Item>
	void list_head_remove(dbl_node<Item>*& head_ptr);

	template <class Item>
	void list_remove(dbl_node<Item>* previous_ptr);

	template <class Item>
	void list_clear(dbl_node<Item>*& head_ptr);
	
	template <class Item>
	void list_copy(const dbl_node<Item>* source_ptr, dbl_node<Item>*& head_ptr, dbl_node<Item>*& tail_ptr);

	template <class Item>
		class dbl_node_iterator
		: public std::iterator<std::forward_iterator_tag, Item>
		{
		public:
			dbl_node_iterator(dbl_node<Item>* initial = NULL)
				{ current = initial; }

			Item& operator*() const
				{ return current->data(); } 

			dbl_node_iterator& operator++() // ++Prefix
				{ current = current->next(); return *this; }

			dbl_node_iterator operator++(int) // Postfix++
			{
				dbl_node_iterator original(current);
				current = current->next();
				return original;
			}

			dbl_node_iterator& operator--() // --Prefix
				{ current = current->prev(); return *this; }

			dbl_node_iterator operator--(int) // Postfix--
			{
				dbl_node_iterator original(current);
				current = current->prev();
				return original;
			}

			bool operator==(const dbl_node_iterator other) const
				{ return current == other.current; }

			bool operator!=(const dbl_node_iterator other) const
				{ return current != other.current; }

		private:
			dbl_node<Item>* current;

		};

	template <class Item>
		class const_dbl_node_iterator
		: public std::iterator<std::forward_iterator_tag, const Item>
		{
		public:
			const_dbl_node_iterator(const dbl_node<Item>* initial = NULL)
				{ current = initial; }

			const Item& operator*() const
				{ return current->data(); } 

			const_dbl_node_iterator& operator++() // ++Prefix
				{ current = current->next(); return *this; }

			const_dbl_node_iterator operator++(int) // Postfix++
			{
				const_dbl_node_iterator original(current);
				current = current->next();
				return original;
			}

			const_dbl_node_iterator& operator--() // --Prefix
				{ current = current->prev(); return *this; }

			const_dbl_node_iterator operator--(int) // Postfix--
			{
				const_dbl_node_iterator original(current);
				current = current->prev();
				return original;
			}

			bool operator==(const const_dbl_node_iterator other) const
				{ return current == other.current; }

			bool operator!=(const const_dbl_node_iterator other) const
				{ return current != other.current; }

		private:
			const dbl_node<Item>* current;

		};
}

#include "dbl_node.template"
#endif


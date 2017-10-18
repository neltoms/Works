// FILE: LinkedSeq.h(part of namespace ntcage_main_1) 
// TEMPLATE CLASS PROVIDED: LinkedSeq<Item>
// 
// TEMPLATE PARAMETER, TYPEDEFS AND MEMBER CONSTANTS for the LinkedSeq<Item> class:
// 		 The template paramerter, Item, is the data type of the items in the LinkedSeq, also
// 		 defined as LinkedSeq::value_type.  It may be any of the C++ built-in types
// 		 (int, char, etc.), or a class with a default constructor, a copy constructor, an
// 		 assignment operator, and operators to test for equality and non-equality. The 
// 		 definition LinkedSeq::size_type is the data type of any variable that keeps track of 
// 		 how many items are in a LinkedSeq.
//
// CONSTRUCTOR for the LinkedSeq class:
// 		LinkedSeq()
// 		 Postcondition: The LinkedSeq has been initialized and its private member variable 
// 		 nodes have been initialized to NULL.
//
// COPY CONSTRUNCTOR
// 		LinkedSeq(const LinkedSeq& source)
// 		 Postcondition: The LinkedSeq has been created by copying from an existing LinkedSeq.
// 
// DESTRUCTOR
// 		~LinkedSeq()
// 		 Postcondition: The dynamic memory used by the function has been released.
//
// MODIFICATION MEMBER FUNCTIONS
// 		void start()
// 		 Postcondition: The first item on the LinkedSeq becomes the current item
//  	 (but if the LinkedSeq is empty, then there is no current item).
//		 
//		void advance()
// 		 Precondition: is_item returns true.
// 		 Postcondition: if the current item was already the last item in the 
// 		 LinkedSeq, then there is no longer any current item. Otherwise, the new
// 		 current item is the item immediately after the original current item.
//
//		void remove_current()
// 		 Precondition: is_item() returns true.
// 		 Postcondition: The current item has been removed from the LinkedSeq
// 		 and the item after this (if there is one) is now the current item.
//		 
//		void reserve(size_type)
//		 Precondition: new_capacity < used
//		 Postcondition: new_capacity = used and sequence has been copied into the newly formed
//		 larger array and the old array has been released from memory.
//
//		void erase_first()
//		 Postcondition: The first item in the LinkedSeq has been erased.
//
//		void erase_last();
//		 Postcondition: The last item in the LinkedSeq has been erased.
//
// 		void erase_from(const value_type&)
// 		 Postcondition: The item from the specified index has been erased [index starts from 0].
//
//		void erase_occurance(const value_type&, const value_type&);
//		 Postcondition: The specified occurrence of the specified value has been erased.
//
//		void insert(const value_type&)
//       Postcondition: The specified value has been inserted on the end of the LinkedSeq.
//
//		void insert_first(const value_type&)
//		 Postcondition: The specified value has been inserted at the beginning of the LinkedSeq.
//
//		void insert_at(const value_type&, const value_type&)
//		 Postcondition: The specified value has been entered into the specified index.
//
// CONSTANT MEMBER FUNCTIONS
//		size_type current() const { return data[current_index]; }
//		 Postcondition: Returns the current index of the cursor.
//
//		size_type size() const 
//		 Postcondition: The return value is the number of indexes occupied by data.
//
//		size_type count(const value_type&) const
//		 Postcondition: The number of occurrences of the specifed value is returned.
//
//		bool is_item() const 
//		 Postcondition: Returns TRUE is the current_index is less than used.
//
// VALUE SEMANTICS for the LinkedSeq class
// 		Assignment and Copy Constructor may be used with the LinkedSeq objects.


#ifndef NTCAGE_LINKED_SEQ_H
#define NTCAGE_LINKED_SEQ_H


#include <cstdlib>
#include "nodeT.h"

namespace ntcage_main_1
{
	template <class Item>
	class LinkedSeq	
	{
		public:
			// TYPEDEFS
			typedef Item value_type;
			typedef std::size_t size_type;

			// CONSTRUCTORS AND DESTRUCTORS
			LinkedSeq();
			LinkedSeq(const LinkedSeq& source);
			~LinkedSeq();

			// MODIFICATION MEMBER FUNCTIONS for the LinkedSeq class:
			void start() { cursor = head_ptr; return; }
			void advance();
			void erase_first();
			void erase_last();
			void erase_from(const Item&);
			void erase_occurance(const Item&, const Item&);
			void insert(const Item&);
			void insert_first(const Item&);
			void insert_at(const Item&, const Item&);
			void operator=(const LinkedSeq& source);
			void operator+=(const LinkedSeq& addend);
			/*
			size_type erase(const Item& target);
			bool erase_one(const Item& target);
			*/
			// OPERATOR OVERLOADS
			friend std::ostream& operator<<(ostream& output, const LinkedSeq<Item>& list);

			// CONSTANT MEMBER FUNCTIONS for the LinkedSeq class:
			size_type size() const { return many_nodes; }
			bool is_item() const { return cursor != NULL; }
			Item current() const { return cursor->data(); }
			size_type count(const Item& target) const;
			Item grab() const;
			

		private:
			node<Item>* head_ptr;
			node<Item>* tail_ptr;
			node<Item>* cursor; // points to node with current item
			node<Item>* precursor;
			size_type many_nodes;

	};
	// NONMEMBER FUNCTIONS for the LinkdSeq<Item> template class
	template <class Item>
	LinkedSeq<Item> operator+(const LinkedSeq<Item>& b1, const LinkedSeq<Item>& b2);


}

#include "LinkedSeq.template"
#endif

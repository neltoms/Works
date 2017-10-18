#ifndef NTCAGE_DOUBLY_LINKED_SEQ_H
#define NTCAGE_DOUBLY_LINKED_SEQ_H


#include <cstdlib> // Provides NULL and size_t
#include "dbl_node.h"

namespace ntcage_main_1
{
	template <class Item>
	class DblyLinkdSeq	
	{
		public:
			// TYPEDEFS
			typedef Item value_type;
			typedef std::size_t size_type;
			typedef dbl_node_iterator<Item> iterator;
			typedef const_dbl_node_iterator<Item> const_iterator;


			// CONSTRUCTORS AND DESTRUCTORS
			DblyLinkdSeq();
			DblyLinkdSeq(const DblyLinkdSeq& source);
			~DblyLinkdSeq();

			// MODIFICATION MEMBER FUNCTIONS for the DblyLinkdSeq class:
			void start() { cursor = head_ptr; return; }
			void advance();
			void erase_first();
			void erase_last();
			void erase_from(const Item&);
			void erase_occurance(const Item&, const Item&);
			void insert(const Item&);
			void insert_first(const Item&);
			void insert_at(const Item&, const Item&);
			void operator=(const DblyLinkdSeq& source);
			void operator+=(const DblyLinkdSeq& addend);
			/*
			size_type erase(const Item& target);
			bool erase_one(const Item& target);
			*/

			// FUCTIONS TO PROVIDE ITERATORS
			iterator begin()
				{ return iterator(head_ptr); }

			const_iterator begin() const
				{ return const_iterator(head_ptr); }

			iterator end()
				{ return iterator(tail_ptr); }

			const_iterator end() const
				{ return iterator(tail_ptr); }

			// OPERATOR OVERLOADS
			friend std::ostream& operator<<(ostream& output, const DblyLinkdSeq<Item>& list);

			// CONSTANT MEMBER FUNCTIONS for the DblyLinkdSeq class:
			size_type size() const { return many_nodes; }
			bool is_item() const { return cursor != NULL; }
			Item current() const { return cursor->data(); }
			size_type count(const Item& target) const;
			Item grab() const;

		private:
			dbl_node<Item>* head_ptr;
			dbl_node<Item>* tail_ptr;
			dbl_node<Item>* cursor; // points to node with current item
			dbl_node<Item>* precursor;
			size_type many_nodes;

	};

	// NONMEMBER FUNCTIONS for the DblyLinkdSeq<Item> template class
	template <class Item>
	DblyLinkdSeq<Item> operator+(const DblyLinkdSeq<Item>& b1, const DblyLinkdSeq<Item>& b2);

	

}

#include "DblyLinkdSeq.template"
#endif

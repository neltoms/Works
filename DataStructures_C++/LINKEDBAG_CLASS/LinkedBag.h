#ifndef NTCAGE_LINKED_BAG_H
#define NTCAGE_LINKED_BAG_H


#include <cstdlib>
#include "node.h"

namespace ntcage_main_1
{
	class LinkedBag
	{
		public:
			// TYPEDEFS
			typedef node::value_type value_type;
			typedef std::size_t size_type;

			// CONSTRUCTORS AND DESTRUCTORS
			LinkedBag();
			LinkedBag(const LinkedBag& source);
			~LinkedBag();

			// MODIFICATION MEMBER FUNCTIONS for the LinkedBag class:
			size_type erase(const value_type& target);
			bool erase_one(const value_type& target);
			void insert(const value_type& entry);
			void operator+=(const LinkedBag& addend);
			void operator=(const LinkedBag& source);
			// CONSTANT MEMBER FUNCTIONS for the LinkedBag class:
			size_type size() const { return many_nodes; }
			size_type count(const value_type& target) const;
			value_type grab() const;

		private:
			node *head_ptr;
			size_type many_nodes;
			

	};

	// NONMEMBER FUNCTIONS for the LinkedBag class:
	LinkedBag operator+(const LinkedBag& b1, const LinkedBag& b2);
}
#endif

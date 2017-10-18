// FILE: Queue.h
// TEMPLATE CLASS PROVIDED: Queue<Item>
//
//

#ifndef NTCAGE_QUEUE_H
#define NTCAGE_QUEUE_H

#include <cstdlib>

namespace ntcage_main_1
{
	template <typename Item>
	class Queue
	{
		public:
			// TYPEDEFS and MEMBER CONSTANTS
			typedef std::size_t size_type;
			typedef Item value_type;
			static const size_type CAPACITY = 30;
			// CONSTRUCTOR
			Queue();
			// MODIFICATION MEMBER FUNCTIONS
			void pop();
			void push(const Item& entry);
			// CONSTANT MEMBER FUNCTIONS
			bool empty() const { return (count == 0); }
			Item front() const;
			size_type size() const { return count; }
		private:
			Item data[CAPACITY];
			size_type first; // used for first index in use
			size_type last;  // used for last index in use
			size_type count;
			// HELPER MEMBER FUNCTION
			size_type next_index(size_type i) const { return (i+1) % CAPACITY; }
	};
}
#include "Queue.template"
#endif

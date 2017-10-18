// FILE: Stack2.h

#ifndef NTCAGE_STACK2_H
#define NTCAGE_STACK2_H

#include <cstdlib>
#include "node2.h"

namespace ntcage_main_1
{
	template <typename T>
	class Stack2
	{
		public:
			// Typedef
			typedef T value_type;
			typedef std::size_t size_type;
			// Constructor
			Stack2() { top_ptr = NULL; }
			Stack2(const Stack2& source);
			// Destructor
			~Stack2() { list_clear(top_ptr); }
			// Mod member functions
			void push(const T& entry);
			void pop();
			void operator=(const Stack2& source);
			// Constant member functions
			size_type size() const { return list_length(top_ptr); }
			bool empty() const { return (top_ptr == NULL); }
			T top() const;
			T second() const;

		private:
			dbl_node<T> *top_ptr;

	};
}

#include "Stack2.template"
#endif

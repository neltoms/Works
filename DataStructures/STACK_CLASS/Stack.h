// FILE: Stack.h

#ifndef NTCAGE_STACK_H
#define NTCAGE_STACK_H

#include <cassert>


namespace ntcage_main_1
{
	template <typename T>
	class Stack 
	{
		public:
			// Typedefs and Constants
			typedef T value_type;
			typedef std::size_t size_type;
			static const size_type CAPACITY = 100;
			// Constructor
			Stack() { used = 0; }
			// Modification member functions
			void push(const T& entry);
			void pop();
			T& top() { assert(!empty()); return data[used-1]; }
			// Constant member functions
			const T& top() const { assert(!empty()); return data[used-1]; }
			size_type size() const { used; }
			bool empty() const { return (used == 0); }
			
		private:
			T data[CAPACITY];
			size_type used;

	};
}
#include "Stack.template"
#endif

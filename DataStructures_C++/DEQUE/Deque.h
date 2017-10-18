// FILE: Deque.h


#ifndef NTCAGE_DEQUE_H
#define NTCAGE_DEQUE_H

#include <cassert>

namespace ntcage_main_1
{
	template <typename T>
	class Deque
	{
		public:
		private:
			static const size_t block_size = 5;
			typedef T value_type;
			typedef value_type* vtp; 	// pointer to a dynamic array of value_type items
			vtp* block_pointers; 		// pointer to the dynamic array of block pointers
			vtp* block_pointers_end; 	// pointer to the final entry in the array of block pointers
			vtp* first_bp; 				// pointer to the first block pointer that's now being used
			vtp* last_bp; 				// pointer to the last block pointer that's now being used
			vtp* front_bp; 				// pointer to the front element of whole deque
			vtp* back_ptr; 				// pointer to the back element of whole deque
	};
}

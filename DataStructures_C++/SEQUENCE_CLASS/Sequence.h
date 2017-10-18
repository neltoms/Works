// CLASS PROVIDED: Sequence(part of namespace main_Sequence_1)
//
// TYPEDEF AND MEMBER CONSTANTS for the Sequence class:
// 		typdef _____ value_type
// 		 Sequence::value_type is the data type of the items in the sequence. It may be
// 		 any of the C++ built-in types (int, char, etc), or a class with a default
// 		 constructor, an assignment operator, and a copy constructor.
//
// 		typdef _____ size_type
// 		 Sequence::size_type is the dat type of any variable that keeps track of how 
// 		 many items are in a sequence.
//
// 		static const size_type CAPACITY = _____
// 		 Sequence::CAPACITY is the maximun number of intems that a sequence can hold.
//
// CONSTRUCTOR for the Sequence class:
// 		Sequence()
// 		 Postcondition: The Sequence has been initialized as an empty Sequence.
//
// COPY CONSTRUNCTOR
// 		Sequence::Sequence(const Sequence& source)
// 		 Postcondition: The Sequence has been created by copying from an existing Sequence.
// 
// DESTRUCTOR
// 		~Sequence()
// 		 Postcondition: The dynamic memory used by the function has been released.
//
// MODIFICATION MEMBER FUNCTIONS
// 		void Sequence::start()
// 		 Postcondition: The first item on the Sequence becomes the current item
//  	 (but if the Sequence is empty, then there is no current item).
//		 
//		void Sequence::advance()
// 		 Precondition: is_item returns true.
// 		 Postcondition: if the current item was already the last item in the 
// 		 Sequence, then there is no longer any current item. Otherwise, the new
// 		 current item is the item immediately after the original current item.
//
//		void Sequence::remove_current()
// 		 Precondition: is_item() returns true.
// 		 Postcondition: The current item has been removed from the Sequence
// 		 and the item after this (if there is one) is now the current item.
//		 
//		void reserve(size_type)
//		 Precondition: new_capacity < used
//		 Postcondition: new_capacity = used and sequence has been copied into the newly formed
//		 larger array and the old array has been released from memory.
//
//		void erase_first()
//		 Postcondition: The first item in the Sequence has been erased.
//
//		void erase_last();
//		 Postcondition: The last item in the Sequence has been erased.
//
// 		void erase_from(const value_type&)
// 		 Postcondition: The item from the specified index has been erased [index starts from 0].
//
//		void erase_occurance(const value_type&, const value_type&);
//		 Postcondition: The specified occurrence of the specified value has been erased.
//
//		void insert(const value_type&)
//       Postcondition: The specified value has been inserted on the end of the Sequence.
//
//		void insert_first(const value_type&)
//		 Postcondition: The specified value has been inserted at the beginning of the Sequence.
//
//		void insert_at(const value_type&, const value_type&)
//		 Postcondition: The specified value has been entered into the specified index.
//
// CONSTANT MEMBER FUNCTIONS
//		size_type get_cap() const { return capacity; }
//		 Postcondition: The return value is the capacity of the array.
//
//		size_type current() const { return data[current_index]; }
//		 Postcondition: Returns the current index of the cursor.
//
//		size_type size() const { return used; }
//		 Postcondition: The return value is the number of indexes occupied by data.
//
//		size_type count(const value_type&) const
//		 Postcondition: The number of occurrences of the specifed value is returned.
//
//		bool is_item() const { return current_index < used; }
//		 Postcondition: Returns TRUE is the current_index is less than used.
//
// VALUE SEMANTICS for the Sequence class
// 		Assignment and Copy Constructor may be used with the Sequence objects.
//
//
#ifndef NTCAGE_SEQUENCE_H
#define NTCAGE_SEQUENCE_H
#include <iostream>
#include <cstdlib>
#include <cmath>

namespace ntcage_main_1
{
	class Sequence
	{
		public:

			// TYPEDEFS AND MEMBER CONSTANTS
			typedef int value_type;
			typedef std::size_t size_type;
			static const size_type DEFAULT_CAPACITY = 100;

			// CONSTRUCTORS AND DESTRUCTOR
			Sequence(size_type inital_capacity = DEFAULT_CAPACITY);
			Sequence(const Sequence& source);
			~Sequence();
			// MODIFICATION MEMBER FUNCTIONS
			void start();
			void advance();
			void remove_current();
			void reserve(size_type);
			void erase_first();
			void erase_last();
			void erase_from(const value_type&);
			void erase_occurance(const value_type&, const value_type&);
			void insert(const value_type&);
			void insert_first(const value_type&);
			void insert_at(const value_type&, const value_type&);
		

			// CONSTANT MEMBER FUNCTIONS
			size_type get_cap() const { return capacity; }
			size_type current() const { return data[current_index]; }
			size_type size() const { return used; }
			size_type count(const value_type&) const;
			bool is_item() const { return current_index < used; }
			//value_type *get_ptr() const { return data; }

			// MEMBER OPERATOR OVERLOADS
			bool operator==(const Sequence&) const;
			bool operator!=(const Sequence&) const;
			void operator+=(const Sequence&);
			void operator=(const Sequence&);
			value_type &operator[](value_type) const;

			// FRIEND FUNCTIONS
			friend std::ostream& operator<<(std::ostream& os, const Sequence&);
			friend std::istream& operator>>(std::istream& is, Sequence&);




		private:
			
			value_type *data; // pointer to the dynamic array
			size_type used; // how much of the array being used
			size_type capacity; // current capacity of the Sequence
			size_type current_index;

	};

	// NON-MEMBER FUNCTION
	
	Sequence operator+(const Sequence& s1, const Sequence s2);

}

#endif

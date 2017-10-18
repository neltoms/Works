// IMPLEMENTATION OF CLASS SEQUENCE
// INVARIANT OF THE SEQUENCE CLASS
// 1. The number of items in the sequence is stored in the member variable used.
// 2. For an empty sequence, we do not care what is stored in any of data; for a
//    non-empty sequence, the items are stored in their sequence order from data[0]
//    to data[used-1], and we don't care what is stored in the rest of data.
// 3. If there is a current item, then it lies in data[current_index]; if there is
// 	  no current item, then current_index = used.
//
// 	
#include <cassert>
#include <algorithm>
#include <new>
#include "Sequence.h"
using namespace std;


namespace ntcage_main_1
{

	Sequence::Sequence(size_type initial_capacity)
	{
		data = new value_type[initial_capacity];
		capacity = initial_capacity;
		current_index = 0;
		used = 0;
	}

	Sequence::Sequence(const Sequence& source)
	{
		data = new value_type[source.capacity];
		capacity = source.capacity;
		used = source.used;
		current_index = source.current_index;
		copy(source.data, source.data + source.used, data);
	}

	Sequence::~Sequence()
	{
		delete [] data;
	}
 
	void Sequence::start()
	{
		current_index=0;
	}

	void Sequence::advance()
	{
		if(is_item())
		{
			for (size_t i = current_index; i < used; i++)
			{
				data[i] = data[i + 1];
			}	
			used--;
		}
	}

	void Sequence::reserve(size_type new_capacity)
	{
		value_type *larger_array;

		if(new_capacity == capacity)
			return;
		if(new_capacity < used)
			new_capacity = used;
		
		larger_array = new value_type[new_capacity];
		copy(data, data+used, larger_array);
		delete [] data;
		data = larger_array;
		capacity = new_capacity;
	}

	void Sequence::erase_last()
	{ used--; }
	
	void Sequence::erase_from(const value_type& index)
	{
		value_type counter = 0;
		while(counter < used)
		{
			if(counter == index)
			{
				for (size_t i = index; i < used; i++) 
				{
					data[i] = data[i + 1];		
				}
				--used;
				return;
			}
			counter++;
		}
	}

	void Sequence::insert_first(const value_type& entry)
	{
		if(!is_item())
			current_index = 0;
		{
			for (size_t i = used; i > current_index; --i)
			{
				data[i] = data[i - 1];
			}
			data[current_index] = entry;
			++used;
		}
	}
	
	void Sequence::erase_occurance(const value_type& target, const value_type& occur)
	{
			value_type index = 0;
			value_type found = 0;
			while (index < used) 
			{
				if (data[index] == target) 
				{
					found++;
					if(found == occur) 
					{		
						for (value_type i = index; i < used; i++)
						{
							data[i] = data[i+1];
						}
						--used;
						return;
					}
				}
				++index; 
			}
	}


	void Sequence::erase_first()
	{
		for (size_t i = 0; i < used; i++)
		{
			data[i] = data[i+1];
		}
		used--;
	}

			

	void Sequence::insert(const value_type& entry)
	{
		if(used == capacity)
			reserve(used + 1);
		data[used++] = entry;
	}

	Sequence::size_type Sequence::count(const value_type& target) const
	{
		value_type counter = 0;
		for (size_type i = 0; i < used; i++) 
		{
			if(data[i] == target)
			{ counter++; }
		}
		return counter;
	}

	void Sequence::insert_at(const value_type& target, const value_type& index)
	{	
			for (size_t i = 0; i > used; ++i)
				{
					if(data[i] == index)	
					return;
				}
				data[index] = target;
				used++;
		
	} 

	// MEMBER OPERATOR OVERLOADS
	
	bool Sequence::operator==(const Sequence& right) const
	{
		if(capacity != right.capacity)
			return false;
		for (value_type i = 0; i < capacity; i++) 
		{
			if(data[i] != right.data[i])
				return false;
		}
		return true;
	}
	
	bool Sequence::operator!=(const Sequence& right) const
	{
		if(capacity == right.capacity)
			return false;
		for (value_type i = 0; i < capacity; i++) 
		{
			if(data[i] == right.data[i])
				return false;
		}
		return true;
	}	
	void Sequence::operator+=(const Sequence& addend)
	{
		if(used+addend.used > capacity)
			reserve(used+addend.used);

		copy(addend.data, addend.data+addend.used, data+used);
		used+=addend.used;
	}

	void Sequence::operator=(const Sequence& source)
	{
		value_type *new_data;
		if (this == &source)
			return;
		if(capacity != source.capacity)
		{
			new_data = new value_type[source.capacity];
			delete [] data;
			data = new_data;
			capacity = source.capacity;
		}
		used = source.used;
		copy(source.data, source.data + used, data);
	}
	
	Sequence::value_type& Sequence::operator[](value_type subscript) const
	{
		if(subscript >=0 && subscript < capacity)
			return data[subscript];
		return data[subscript];
	}


	// FRIEND FUNCTIONS
	
	std::ostream& operator<<(std::ostream& os, const Sequence& data)
	{
		for (size_t i = 0; i < data.capacity; i++) 
		{
			os << data[i];
		}
		return os;
	}

	std::istream& operator>>(std::istream& is, Sequence& data)
	{
		for (size_t i = 0; i < data.capacity; i++) 
		{
			is >> data[i];
		}
		return is;
	}

	Sequence operator+(const Sequence& s1, const Sequence& s2)
	{
		Sequence answer(s1.size() + s2.size());

		answer += s1; 
		answer += s2;
		return answer;
	}

	
}

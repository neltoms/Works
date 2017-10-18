//
// Created by faculty on 3/7/2017.
//

#include <cassert>
#include "bag.h"

namespace test2_bag_1
{
	void bag::insert(int item)
	{
		assert(size() < CAPACITY);
		data[used++] = item;
	}

	void bag::erase(int item) 
	{
		int index = -1;
		for (int i = 0; i < used; i++) 
		{
			if(data[i] == item) 
			{
				index = i;
				break;
			}
		}

		if(index != -1)
		{
			data[index] = data[--used];
		}
	}

	int bag::count(int item) const 
	{
		int nums = 0;
		for (int i = 0; i < used; ++i) 
		{
			if(data[i] == item)
				nums++;
		}
		return nums;
	}

	bag& bag::operator+=(const bag& b2) 
	{
		assert(used + b2.used <= CAPACITY);
		int size = b2.used;
		for (int i = 0; i < size; ++i) 
		{
			data[used++] = b2.data[i];
		}

		return *this;
	}

	bag operator+(const bag& b1, const bag& b2)
	{
		assert(b1.size() + b2.size() <= bag::CAPACITY);

		bag result;
		(result += b1) += b2;

		return result;
	}

}





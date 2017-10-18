//
// Bag of integer values
// Created by faculty on 3/7/2017.
//

#ifndef TEST2_BAG_H
#define TEST2_BAG_H

namespace test2_bag_1
{
	class bag 
	{
	public:
		// CONSTRUCTOR
		bag() { used = 0; }

		// MODIFICATION MEMBER FUNCTIONS
		void insert(int);       // Insert an item into bag
		void erase(int);        // Erase an item from bag
		void erase_all() { used = 0; };

		// MEMBER CONSTANTS
		static const int CAPACITY = 20;
		int size() const { return used; };
		int count(int) const;   // Count number of occurrence of an item
		
		// MEMBER OPERATOR OVERLOADS
		bag& operator+=(const bag&);

	private:
		size_t used;
		int data[CAPACITY];
	};

		// NON-MEMBER OPERATOR OVERLOADS
		bag operator+(const bag&, const bag&);
}

#endif

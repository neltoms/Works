// FILE: hash_table.h
//
// CONSTRUCTOR
//


#ifndef NTCAGE_TABLE_H
#define NTCAGE_TABLE_H
#include <cstdlib>
#include "bintree.h"

namespace ntcage_main_1
{
	template <class T>
	struct LinkedHash
	{
		typedef T value_type;
		typedef std::size_t size_type;
	
		// Member Variables
		size_type key;
		T value;
		size_type many_nodes;
		LinkedHash<T>* next;
		
		// Constructor
		LinkedHash(size_type key, T value)
		{ this->key = key; this->value = value; this->next = NULL; many_nodes = 0;}
	};

	template <typename T>
	class HashTable
	{
		public:
			typedef T value_type;
			typedef std::size_t size_type;

			// Member Constant
			static const size_t SIZE = 20;

			// Constructor
			HashTable();

			// Copy Constructor
			HashTable(const HashTable& source);

			// Destructor
			~HashTable();

			// Member Functions
			size_type hash_func(size_type key) const { return key % SIZE; }
			size_type find(const T& key) const;
			void insert_hash(size_type key, T value);
			void print_list();
			void find_index(size_type key, bool& found, size_type& i) const;
			void print_tree(binary_tree_node<T>* node_ptr);	
			void remove(size_type key);
			size_type size() const { return SIZE; }

		private:
			LinkedHash<T>** bucket;
			binary_tree_node<T>** b_bucket;
			size_type many_nodes;
	};

}

#include "hash_table.template"
#endif


			

			



			




























/*

			// MODIFICATION MEMBER FUNCTIONS
			void insert(const T& entry);
			void remove(std::size_t key);
			

			// CONSTANT MEMBER FUNCTIONS
			bool is_present(std::size_t key) const;
			void find(int key, bool& found, T& result) const;
			std::size_t size() const { return used; }

		private:
			// MEMBER CONSTANTS
			static const int NEVER_USED = -1;
			static const int PREVIOUSLY_USED = -2; 

			// MEMBER VARIABLES
			dbl_node<T>* root_ptr;
			T value;
			std::size_t key;
			std::size_t used;

			// HELPER FUNCTIONS
			std::size_t hash(std::size_t key) const;
			std::size_t next_index(std::size_t index);
			void find_index(int key, bool& found, std::size_t& i) const;
			bool never_used(std::size_t index) const;
			bool is_vacant(std::size_t index) const;

	};

}

//#include "Table.template"
#endif

*/

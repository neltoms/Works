// MEMBER FUNCTIONS
//
// size_t list_length(const node* head_ptr);
// 	 Precondition: head_ptr is the head pointer of the linked listl
// 	 Postcondition: The value returned is the number of nodes in the 
// 	 linked list.
// 	 Library facilities used: cstdlib
//
// 	void list_insert(node* p, const node::value_type& entry);
// 	  Precondition: previous_ptr points to a node in a linked list.
// 	  Postcondtion: A new node containing the given entry has been added
// 	  after the node that p points to.
//
// 	 void list_head_insert(node*& head_ptr, const node::value_type& entry);
// 	  Precondition: head_ptr is the head pointer of a linked list.
// 	  Postcondition: A new node containing the given entry has been added at
// 	  the head of the list; head_ptr now points to the head of the new, longer
// 	  linked list.
// 	  


#ifndef NTCAGE_NODE_H
#define NTCAGE_NODE_H

#include <cstdlib>
#include <string>

namespace ntcage_main_1
{
	class node
	{
		public:
			typedef std::string value_type;
			typedef std::size_t size_type;

			// CONSTRUCTOR
			node(const value_type& init_data = value_type(), 
					node* init_link = NULL)
			{ data_field = init_data; link_field = init_link; }


			// Member functions to set the data and link fields
			void set_data(const value_type& new_data) { data_field = new_data; }
			void set_link(node* new_link) 			  { link_field = new_link; }

			// CONSTANT MEMBER FUNCTIONS TO RETRIEVE THE CURRENT DATA:
			value_type data() const { return data_field; }

			// TWO SLIGHTLY DIFFERENT MEMEBER FUNCTIONS TO RETRIEVE THE CURRENT LINK:
			const node* link() const { return link_field; }
			node* link() 		     { return link_field; }

		private:

			value_type data_field;
			node *link_field;

	};
	// FUNCTIONS for the linked-list tool-kit
	std::size_t list_length(const node* head_ptr);
	void list_head_insert(node*& head_ptr, const node::value_type& entry);
	void list_insert(node* previous_ptr, const node::value_type& entry);
	node* list_search(node* head_ptr, const node::value_type& target);
	const node* list_search(const node* head_ptr, const node::value_type& target);
	node* list_locate(node* head_ptr, std::size_t position);
	const node* list_locate(const node* head_ptr, std::size_t position);
	void list_head_remove(node*& head_ptr);
	void list_remove(node* previous_ptr);
	void list_clear(node*& head_ptr);
	void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr);
}

#endif


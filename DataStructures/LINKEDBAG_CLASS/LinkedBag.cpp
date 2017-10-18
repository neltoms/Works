#include <iostream>
#include <cassert>
#include "LinkedBag.h"
#include "node.h"


namespace ntcage_main_1
{
	LinkedBag::LinkedBag()
	{
		head_ptr = NULL;
		many_nodes = 0;
	}

	LinkedBag::LinkedBag(const LinkedBag& source)
	{
		node *tail_ptr; // needed for argument to list_copy

		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.many_nodes;
	}

	LinkedBag::~LinkedBag()
	{
		list_clear(head_ptr);
		many_nodes = 0;
	}

	void LinkedBag::operator=(const LinkedBag& source)
	{
		node *tail_ptr;

		if(this == &source)
			return;

		list_clear(head_ptr);
		many_nodes = 0;
		list_copy(source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.many_nodes;
	}
	
	bool LinkedBag::erase_one(const value_type& target)
	{
		node *target_ptr;
		target_ptr = list_search(head_ptr, target);
		if(target_ptr == NULL)
			return false; // target is not in the LinkedBag
		target_ptr->set_data(head_ptr->data());
		list_head_remove(head_ptr);
		--many_nodes;
		return true;
		
	}
	
	void LinkedBag::insert(const value_type& entry)
	{
		list_head_insert(head_ptr, entry);
		++many_nodes;
	}

	LinkedBag::size_type LinkedBag::count(const value_type& target) const
	{
		size_type answer = 0;
		const node *cursor = list_search(head_ptr, target);
		while(cursor != NULL)
		{
			++answer;
			cursor = cursor->link();
			cursor= list_search(cursor, target);
		}
		return answer;
	}

	LinkedBag::value_type LinkedBag::grab() const
	{
		size_type i;
		const node *cursor;

		assert(size() > 0);
		i = (rand() % size()) + 1;
		cursor = list_locate(head_ptr, i);
		return cursor->data();
	}

}


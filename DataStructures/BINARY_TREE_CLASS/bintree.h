// FILE: bintree.h
//
//
//
#ifndef NTCAGE_BINTREE_H
#define NTCAGE_BINTREE_H
#include <cstdlib>


namespace ntcage_main_1
{
	template <typename T>
	class binary_tree_node
	{
		public:
			// TYPEDEF
			typedef T value_type;
			// CONSTRUCTOR
			binary_tree_node(
				const T& init_data = T(),
				binary_tree_node* init_left = NULL,
				binary_tree_node* init_right = NULL
			)
			{
				data_field = init_data;
				left_field = init_left;
				right_field = init_right;
			}
			// MODIFICATION MEMBER FUNCTIONS
			T& data() { return data_field; }
			binary_tree_node*& left() { return left_field; }
			binary_tree_node*& right() { return right_field; }
			void set_data(const T& new_data) { data_field = new_data; }
			void set_left(const T& new_left) { left_field = new_left; }
			void set_right(const T& new_right) { right_field = new_right; }
			// CONSTANT MEMBER FUNCTIONS
			const T& data() const { return data_field; }
			const binary_tree_node* left() const { return left_field; }
			const binary_tree_node* right() const { return right_field; }
			bool is_leaf() const 
				{ return (left_field == NULL) && (right_field == NULL); } 

		private:
			T data_field;
			binary_tree_node *left_field;
			binary_tree_node *right_field;
	};
	
	// BINARY TREE TOOLKIT
	template <typename T>
	void tree_clear(binary_tree_node<T>*& root_ptr);
	
	template <typename T, typename NodePtr>
	NodePtr<T>* tree_copy(NodePtr<T>* root_ptr);

	template <typename T>
	void preorder_print(const binary_tree_node<T>* node_ptr);

	template <typename T>
	void inorder_print(const binary_tree_node<T>* node_ptr);

	template <typename T>
	void postorder_print(const binary_tree_node<T>* node_ptr);

	template <typename T, typename SizeType>
	void print(const binary_tree_node<T>* node_ptr, SizeType depth);
	
	template <typename T>
	std::size_t tree_size(const binary_tree_node<T>* node_ptr);


}
#include "binary_tree_node.template"
#endif

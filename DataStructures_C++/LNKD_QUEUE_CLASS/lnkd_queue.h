// FILE: lnkd_queue.h


#include <cstdlib>
#include "dbl_node.h"

namespace ntcage_main_1
{
	template <typename Item>
	class lnkd_queue
	{
		public:
			// TYPEDEFS
			typedef std::size_t size_type;
			typedef Item value_type;
			// CONSTRUCTORS and DESTRUCTOR
			lnkd_queue();
			lnkd_queue(const<Item>& source);
			~lnkd_queue();
			// MODIFICATION MEMBER FUNCTIONS
			void pop();
			void push(const Item& entry);
			void operator=(const lnkd_queue<Item>& source);
			// CONSTANT MEMBER FUNCTIONS
			bool empty() const { return (count == 0); }
			Item front() const;
			size_type size() const { return count; }
		private:
			dbl_node<Item> *front_ptr;
			dbl_node<Item> *rear_ptr;
			size_type count;
	};
}
#include "lnkd_queue.template"
#endif

#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>

using namespace std;

bool is_balanced(const string& expression);

int main()
{
	int i = (2 + 4);
	cout << i << endl;
	return 0;
}

bool is_balanced(const string& expression)
{
	const char LEFT_PARENTHESIS = '(';
		const char RIGHT_PARENTHESIS = ')';

		stack<char> store;
		string::size_type i;
		char next;
		bool failed = false;

		for (i = 0; !failed && (i < expression.length()); i++) 
		{
			next = expression[i];
			if (next == LEFT_PARENTHESIS)
				store.push(next);
			else if ((next == RIGHT_PARENTHESIS) && (!store.empty()))
				store.pop();
			else if ((next == RIGHT_PARENTHESIS) && (store.empty()))
				cout << "failed = true";
				cout << "\n";
		}

		return (store.empty() && !failed);
}



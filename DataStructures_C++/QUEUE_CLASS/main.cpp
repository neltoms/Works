#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main()
{
	stack<char> back;
	queue<char> forw;
	char n;
	int i = 0;
	
	cout <<"Please enter a word: ";
	cin >> n;
	back.push(n);
	forw.push(n);
	

	while(i < 5)
	{
		back.top();
		back.pop();
		++i;
	}

	while(i < 5)
	{
		forw.front();
		forw.pop();
		++i;
	}


	
	EXIT_SUCCESS;
}

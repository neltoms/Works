#include<iostream>
#include<time.h>

using namespace std;

int main(){

		int v;
		srand (time(NULL));
		v = rand() % 3 +1;
		cout << v << endl;

		return EXIT_SUCCESS;
}

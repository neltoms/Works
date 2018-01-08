#include<iostream>
#include<time.h>

using namespace std;

int main(){

		int v;
		srand (time(NULL));
		v = rand() % 40 +1;
		cout << v << endl;

		return EXIT_SUCCESS;
}

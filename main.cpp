#include <iostream>

#include "range.hpp"
#include <string>
using namespace std;
using namespace itertools;
int main(){
for (int i: range<char>('a','c'))
		cout << i<<endl;
}
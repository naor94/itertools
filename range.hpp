#include <iostream>
#pragma once

namespace itertools{

template<typename T>
class range{
 

public:
T start;
T last;

 
range(T b, T e){
    start=b;
    last=e;
}

class iterator{

private:
T val;


public:
iterator(T p = nullptr)
: val(p) 
{}

T operator*() const {
	return val;
}

iterator& operator++() {
    val++;
	return *this;
}

const iterator operator++(int) {
 iterator tmp= *this;
 val++;
 return tmp;
}



bool operator!=(const iterator& rhs) const {
	return val != rhs.val;
}



}; //end itertor class

public:
iterator begin() {
		return iterator{start};
	}
	
	iterator end() {
		return iterator{last};
	}



};


}




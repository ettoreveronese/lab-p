#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <iostream>

class MyVector{

public:
	MyVector(size_t s);
    MyVector(initializer_list<double> lst){};
    MyVector(const MyVector& v);
	~MyVector();
	
    const double &at(size_t index) const;
	double &at(size_t index);
	
    void push_back(double elem);
	void pop_back();
	
    void reserve(size_t n);

private:
	double *ptr;
	size_t size;
	size_t buffer_size;
}

#endif

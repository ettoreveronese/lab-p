// da commentare
// rivedere nome variabili
#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <iostream>
#include <initializer_list>  // Add this include
#include <cstddef>          // For size_t


class MyVector{

public:
    MyVector();
	MyVector(size_t s);
    MyVector(std::initializer_list<double> lst);
    MyVector(const MyVector& v);
    MyVector(MyVector&& v) noexcept;
    MyVector& operator=(const MyVector& v);
    MyVector& operator=(MyVector&& v) noexcept;
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
};

#endif

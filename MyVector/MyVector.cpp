#include "MyVector.h"

MyVector::MyVector(size_t s){
    size = s;
	buffer_size = s;
	ptr = new double[size];
}

MyVector::~MyVector(){
	if(ptr != nullptr){
		delete[] ptr;
	}
}

double MyVector::at(size_t i){
	if (i >= size){
		throw std::out_of_range("invalid argument");
	}
	return ptr[i];
}

const double MyVector::at(size_t i) const{
	if (i >= size){
		throw std::out_of_range("invalid argument");
		return;
	}
	return ptr[i];
}

void MyVector::push_back(double elem){
	size_t old_size = size;
    size += 1;
	
    if (size > buffer_size){
		buffer_size = (buffer_size == 0) ?  1 : buffer_size*2;
		
        double *new_ptr = new double[buffer_size];
		std::copy(ptr, ptr+old_size , new_ptr);
	    
        delete[] ptr;
        ptr = new_ptr;
    }

	ptr[size-1]=elem;
}

void MyVector::pop_back(){
	if (size <= 0){
        throw std::out_of_range("pop_back on empty vector");
    }
    size -= 1;
}

void MyVector::reserve(size_t n){
    if (n > buffer_size){
        buffer_size = n;
		
        double *new_ptr = new double[buffer_size];
		std::copy(ptr, ptr+size-1, new_ptr);
	    
        delete[] ptr;
        ptr = new_ptr;
    } 
}

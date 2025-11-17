#include "MyVector.h"


MyVector::MyVector(size_t s) : size(s ? s : 0), ptr(s ? new double[size] : nullptr), buffer_size(s) {} // s = nullptr ????????

MyVector::MyVector(initializer_list<double> lst) : size(lst.size()), buffer_size(size), ptr(size ? new double[size] : nullptr) {
    std::copy(lst.begin(), lst.end(), ptr); 
}

MyVector::MyVector(const MyVector& v) : size(v.size), buffer_size(v.buffer_size), ptr(size ? new double[size] : nullptr){
    std::copy(v, v.ptr+size, ptr);
}

MyVector::~MyVector(){
	delete[] ptr;
}


double& MyVector::at(size_t i){
	if (i >= size) throw std::out_of_range("invalid argument");
	return ptr[i];
}

const double& MyVector::at(size_t i) const{
	if (i >= size){
		throw std::out_of_range("invalid argument");
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
	if (size == 0){
        throw std::out_of_range("pop_back on empty vector");
    }
    size -= 1;
}

void MyVector::reserve(size_t n){
    if (n > buffer_size){
        buffer_size = n;
		
        double *new_ptr = new double[buffer_size];
		std::copy(ptr, ptr+size, new_ptr);
	    
        delete[] ptr;
        ptr = new_ptr;
    } 
}

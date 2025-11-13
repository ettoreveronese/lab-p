#include "MyVector.h"

MyVector::MyVector(size_t bs){
	max_size = bs;
	ptr = new double[ms];
}

MyVector::~MyVector(){
	if(ptr != nullptr){
		delete[] ptr;
	}
}

double MyVector::at(size_t i){
	if (i >= max_size){
		throw std::out_of_range("invalid argument\n");
		return;
	}
	return ptr[i];
}

const double MyVector::at(size_t i) const{
	if (i >= size){
		throw std::out_of_range("invalid argument\n");
		return;
	}
	return ptr[i]
}

void MyVector::push_back(double elem){
	size++;
	if (size > buffer_size){
		buffer_size*=2;
		double t_ptr* = new double[buffer_size];
		std::copy(ptr, ptr+size , t_ptr);
	}
	ptr[size]=elem;
}

void MyVector::pop_back(){
	size--;
	max_size--;
}

void MyVector::reserve(size_t n){

}


// paolo


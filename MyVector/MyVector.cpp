#include "MyVector.h"

MyVector::MyVector(size_t ms){
	max_size = ms;
	ptr = new double[ms];
}

MyVector::~MyVector(){
	if(ptr != nullptr){
		delete ptr;
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



// paolo


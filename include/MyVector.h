// da commentare
// rivedere nome variabili
#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <iostream>
#include <initializer_list>  
#include <cstddef>          
#include <algorithm>
#include <stdexcept>

template <typename T>
class MyVector{

public:
    MyVector() : size(0), buffer_size(0), ptr(nullptr) {}
    MyVector(size_t s) : size(s ? s : 0), ptr(s ? new T[size] : nullptr), buffer_size(s) {} // s = nullptr ????????
    
    MyVector(std::initializer_list<T> lst) : size(lst.size()), buffer_size(size), ptr(size ? new T[size] : nullptr) {
        std::copy(lst.begin(), lst.end(), ptr); 
    }

    MyVector(const MyVector& v) : size(v.size), buffer_size(v.buffer_size), ptr(size ? new T[size] : nullptr){
        std::copy(v.ptr, v.ptr+size, ptr);
    }
    
    MyVector(MyVector&& v) noexcept : size(v.size), buffer_size(v.buffer_size), ptr(v.ptr){
        v.size = 0;
        v.buffer_size = 0;
        v.ptr = nullptr;
    }

    MyVector<T>& operator=(const MyVector& v){
        if (this == &v){
            return *this;
        }
    
        size = v.size;
        buffer_size = v.buffer_size;

        T* new_ptr = size ? new T[size] : nullptr;
        std::copy(v.ptr, v.ptr+v.size, new_ptr);
    
        delete[] ptr;
        ptr = new_ptr;

        return *this;    
    }

    MyVector<T>& operator=(MyVector&& v) noexcept {
        if(this == &v){
            return *this;
        }

        delete[] ptr;

        size = v.size;
        buffer_size = v.buffer_size;
        ptr = v.ptr;

        v.size = 0;
        v.buffer_size = 0;
        v.ptr = nullptr;

        return *this;
    }
    
	~MyVector(){
	    delete[] ptr;
    }
	
    T& at(size_t i){
	    if (i >= size) throw std::out_of_range("invalid argument");
	    return ptr[i];
    }

    const T& at(size_t i) const{
	    if (i >= size){
		    throw std::out_of_range("invalid argument");
	    }
	    return ptr[i];
    }

    void push_back(const T& elem){
	    size_t old_size = size;
	
        if (size > buffer_size){
	    	buffer_size = (buffer_size == 0) ?  1 : buffer_size*2;
		
            T *new_ptr = new T[buffer_size];
		    std::copy(ptr, ptr+old_size , new_ptr);
	    
            delete[] ptr;
            ptr = new_ptr;
        } 

	    ptr[size]=elem;
        size += 1;
    }

    void pop_back(){
	    if (size == 0){
            throw std::out_of_range("pop_back on empty vector");
        }
        size -= 1;
    }

    void reserve(size_t n){
        if (n > buffer_size){
            buffer_size = n;
		
            T *new_ptr = new T[buffer_size];
		    std::copy(ptr, ptr+size, new_ptr);
	    
            delete[] ptr;
            ptr = new_ptr;
        } 
    }

private:
    std::size_t size;
    std::size_t buffer_size;
    T* ptr;
};

#endif

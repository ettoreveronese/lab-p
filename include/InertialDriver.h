#ifndef INDERTIAL_DRIVER_H
#define INERTIAL_DRIVER_H

#include "MyVector.h"
#include <iostream>

class InertialDriver{
	
public:
	InertialDriver();
	void push_back(MyVector v);
	MyVector pop_front();
	void clear_buffer();
	double get_reading(std::uint8_t index);
	std::ostream& operator<<(std::ostream& os, const InertialDriver& data);
	
private:
	MyVector data;
	
};

#endif

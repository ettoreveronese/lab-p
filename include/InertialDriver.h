#ifndef INDERTIAL_DRIVER_H
#define INERTIAL_DRIVER_H

#include "../include/MyVector.h"
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
    const std::size_t 
    const std::size_t BUFFER_DIM 	

    struct Reading {
        double yaw_v;
        double yaw_a;
        double pitch_v;
        double pitch_a;
        double roll_v;
        double roll_a;
    };
};

#endif

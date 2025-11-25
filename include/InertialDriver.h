#ifndef INDERTIAL_DRIVER_H
#define INERTIAL_DRIVER_H

#include "../include/MyVector.h"
#include <iostream>

struct Reading {
    double yaw_v, yaw_a, pitch_v, pitch_a, roll_v, roll_a;
};
    
const std::size_t BUFFER_DIM = 670;
const std::size_t NUM_SENSORS = 17;
typedef Reading Measurement[NUM_SENSORS];

class InertialDriver{

private: 
    MyVector<Reading> buffer;

    std::size_t front;
    std::size_t back;
    std::size_t count;

public:
	InertialDriver();
	void push_back(const Measurement& readings);
	MyVector pop_front();
	Reading get_reading(std::size_t i);
	void clear_buffer();
	std::ostream& operator<<(std::ostream& os, const InertialDriver& data);

};

#endif

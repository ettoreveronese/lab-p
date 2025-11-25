#ifndef INDERTIAL_DRIVER_H
#define INERTIAL_DRIVER_H

#include "../include/MyVector.h"
#include <iostream>

class InertialDriver{

private:
    static constexpr std::size_t BUFFER_DIM = 67;
    MyVector<Reading> buffer;

    struct Reading {
        double yaw_v, yaw_a;
        double pitch_v, pitch_a;
        double roll_v, roll_a;
    };


public:
	InertialDriver();
	void push_back(const Reading measure[BUFFER_DIM]);
	MyVector pop_front();
	Reading get_reading(std::size_t i);
	void clear_buffer();
	std::ostream& operator<<(std::ostream& os, const InertialDriver& data);

};

#endif

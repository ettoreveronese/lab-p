#ifndef INERTIAL_DRIVER_H
#define INERTIAL_DRIVER_H

#include "../include/MyVector.h"
#include <iostream>

struct Reading { // lettura di 1 sensore 
    double yaw_v, yaw_a, pitch_v, pitch_a, roll_v, roll_a;
};
    
const std::size_t NUM_SENSORS = 17;     // numero di sensori, equivale al numero di letture che costituisce una misura
typedef Reading Measurement[NUM_SENSORS];   // un array di 17 strutture Reading, quindi le letture di 17 sensori

class InertialDriver{ 

private:
    static const std::size_t BUFFER_DIM = 67;
    MyVector<Measurement> buffer;

    std::size_t front;
    std::size_t back;
    std::size_t count;

public:
	InertialDriver();
	void push_back(const Measurement& new_measurement);
	void pop_front(Measurement& output_measurement);
	Reading get_reading(std::size_t i);
	void clear_buffer();
	
    friend std::ostream& operator<<(std::ostream& os, const InertialDriver& data);

};

#endif

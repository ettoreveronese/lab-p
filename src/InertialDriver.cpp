#include "InertialDriver.h"
#include <iostream>

InertialDriver::InertialDriver() : buffer(BUFFER_DIM){}

void InertialDriver::push_back(const Measurement& readings){ // todo
    
}

MyVector InertialDriver::pop_front(){
    
}

Reading InertialDriver::get_reading(){

}

void InertialDriver::clear_buffer(){

}

std::ostream& InertialDriver::operator<<(std::ostream& os, const InertialDriver& data){
    
}



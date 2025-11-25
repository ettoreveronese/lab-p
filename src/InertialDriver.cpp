#include "InertialDriver.h"
#include <iostream>

InertialDriver::InertialDriver() : buffer(BUFFER_DIM){}

void InertialDriver::push_back(const Measurement& readings){
    if(count >= BUFFER_DIM){
        buffer.at()
    }
}

void InertialDriver::pop_front(){
    
}

Reading InertialDriver::get_reading(std::size_t i) {
    if (count == 0) {
        throw std::out_of_range("Buffer is empty");
    }
    if (i >= NUM_SENSORS) {
        throw std::out_of_range("Invalid sensor index");
    }

    // Indice dell'ultima misura inserita
    std::size_t last_measure_idx = (back + BUFFER_DIM - 1) % BUFFER_DIM;

    // Uso di at() per sicurezza
    Measurement& last_measure = buffer.at(last_measure_idx);  // l'ultima misura
    return last_measure[i];                                   // la lettura richiesta
}

void InertialDriver::clear_buffer(){
    front = 0;
    back = 0;
    count = 0;
}

std::ostream& InertialDriver::operator<<(std::ostream& os, const InertialDriver& data){
      
}

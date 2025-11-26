#include "InertialDriver.h"
#include <iostream>

InertialDriver::InertialDriver() : buffer(BUFFER_DIM), front(0), back(BUFFER_DIM-1), count(0){}

void InertialDriver::push_back(const Measurement& readings){
    if (count == BUFFER_DIM){   // push_back quando il buffer è pieno
        std::copy(readings, readings+NUM_SENSORS, buffer.at(front));
        back = front;
        front = (front + 1) % BUFFER_DIM;
    } else {    // push_back quando il buffer non è pieno
        back = (back + 1) % BUFFER_DIM;
        std::copy(readings, readings+NUM_SENSORS, buffer.at(back));
        count++;
    }
}

void InertialDriver::pop_front(Measurement& measurement_out){
    if (count != 0){
        // copia della misura da rimuovere su measurement_out
        const Measurement& m = buffer.at(front);    // misura da rimuovere e restituire
        std::copy(m, m+NUM_SENSORS, measurement_out);
        // aggiornamento parametri
        front = (front+1) % BUFFER_DIM; 
        count--;
    } else {
        throw std::runtime_error("buffer is empty");
    }
}

Reading InertialDriver::get_reading(std::size_t i) {
    if (count == 0) {
        throw std::runtime_error("buffer is empty");
    }
    if (i >= NUM_SENSORS) {
        throw std::out_of_range("Invalid sensor index");
    }

    // Indice dell'ultima misura inserita
    std::size_t last_measure_idx = (back + BUFFER_DIM - 1) % BUFFER_DIM;

    Measurement& last_measure = buffer.at(back);    // l'ultima misura
    return last_measure[i];                         // la lettura richiesta
}

void InertialDriver::clear_buffer(){
    front = 0;
    back = BUFFER_DIM-1;
    count = 0;
}

std::ostream& InertialDriver::operator<<(std::ostream& os, const InertialDriver& data){
      
}

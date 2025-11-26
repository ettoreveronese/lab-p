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

    Measurement& last_measure = buffer.at(back);    // l'ultima misura
    return last_measure[i];                         // la lettura richiesta
}

void InertialDriver::clear_buffer(){
    front = 0;
    back = BUFFER_DIM-1;
    count = 0;
}

std::ostream& operator<<(std::ostream& os, const InertialDriver& data) {
    if (data.count == 0) {
        os << "Buffer Empty";
        return os;
    }

    os << "Buffer Status (" << data.count << " items):\n";
    
    for (std::size_t i = 0; i < data.count; ++i) 
        std::size_t physical_idx = (data.front + i) % data.BUFFER_DIM;
        
        os << "Pos " << i << " (Ind " << physical_idx << "): ";
    
        const Measurement& m = data.buffer.at(physical_idx);
        
        os << "[S0: y_v=" << m[0].yaw_v << ", y_a=" << m[0].yaw_a << "...]\n";
    }
    return os;
}

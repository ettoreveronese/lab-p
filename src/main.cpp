// test classe 

#include "../include/InertialDriver.h"
#include <iostream>

 void generate_random_measurement(Measurement& m) {
        for (std::size_t i = 0; i < NUM_SENSORS; ++i) {
            m[i].yaw_v   = rand() % 100 / 10.0;
            m[i].yaw_a   = rand() % 100 / 10.0;
            m[i].pitch_v = rand() % 100 / 10.0;
            m[i].pitch_a = rand() % 100 / 10.0;
            m[i].roll_v  = rand() % 100 / 10.0;
            m[i].roll_a  = rand() % 100 / 10.0;
        }
        std::cout << "sensore 1 (dati casuali): " << m[0].yaw_v << " " << m[0].yaw_a << " " << m[0].pitch_v << " " << m[0].pitch_a << " " << m[0].roll_v << " " << m[0].roll_a << "\n";
    }

int main(){
    InertialDriver driver;
    
    Measurement m;

    // test push_back
    std::cout << "test push_back\n";
    for (int i=0; i<71; i++){
        std::cout << "misura indice " << i << "\n";
        generate_random_measurement(m);
        driver.push_back(m);
    }

    // test << operator
    std::cout << driver << "\n";
    
    // test pop_front
    driver.pop_front(m);
    

    return 0;
}

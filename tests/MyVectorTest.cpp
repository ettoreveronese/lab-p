#include <iostream>
#include "../include/MyVector.h"

int main(){
    MyVector<double> v0;
    MyVector<double> v1(5);
    MyVector<double> v2 = {1, 2, 3, 4, 5};
    MyVector<double> v3 = v2;
    
    for(int i=0; i<5; i++){
        std::cout << v3.at(i) << "\n";
    }
    return 0;
}

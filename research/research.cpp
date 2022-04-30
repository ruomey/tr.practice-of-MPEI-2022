#include <iostream>
#include "plant.h"
#include <vector>
#include <math.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <string>
#include "hist.h"



void input (size_t &number_sensor,size_t &count_min,size_t &count_max, size_t &interval) {
    std::cout << "Input number sensor";
    std::cin >> number_sensor;
    std::cout << "Input count min";
    std::cin >> count_min;
    std::cout << "Input count max";
    std::cin >> count_max;
    std::cout << "Input interval";
    std::cin >> interval;
}


int main(){
    size_t number_sensor,count_min, count_max, interval;
    input(number_sensor, count_min, count_max, interval);

}

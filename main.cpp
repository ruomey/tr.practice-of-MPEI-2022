#include <iostream>
#include "plant.h"
#include <vector>
#include <math.h>

void input (size_t &sensor,size_t &number_of_surveys,size_t &time_interval,size_t &number_of_intervals ){
    sensor = 0, number_of_surveys = 0, time_interval = 0, number_of_intervals = 0;
    std::cout << "Enter the sensor number :" << std::endl;
    std::cin >> sensor;
    std::cout << "Enter the number of surveys :" << std::endl;
    std::cin >> number_of_surveys;
    std::cout << "Enter the time_interval :" << std::endl;
    std::cin >> time_interval;
    std::cout << "Enter the number of intervals :"<< std::endl;
    std::cin >> number_of_intervals;
    return;
}

int main (){
    size_t sensor, number_of_surveys,time_interval, number_of_intervals;
    input(sensor, number_of_surveys, time_interval, number_of_intervals);
    std::cout << sensor << number_of_surveys << time_interval << number_of_intervals;
    return 0;
}

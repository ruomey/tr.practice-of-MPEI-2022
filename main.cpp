#include <iostream>
#include "plant.h"
#include <vector>
#include <math.h>
int main (){
    size_t sensor = 0, number_of_surveys = 0, time_interval = 0, number_of_intervals = 0;
    std::cout << "Enter the sensor number :" << std::endl;
    std::cin >> sensor;
    std::cout << "Enter the number of surveys :" << std::endl;
    std::cin >> number_of_surveys;
    std::cout << "Enter the time_interval :" << std::endl;
    std::cin >> time_interval;
    std::cout << "Enter the number of intervals :"<< std::endl;
    std::cin >> number_of_intervals;
    std::cout << sensor << number_of_surveys << time_interval << number_of_intervals;
    return 0;
}

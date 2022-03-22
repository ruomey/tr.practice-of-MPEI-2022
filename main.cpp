#include <iostream>
#include "plant.h"
#include <vector>
#include <math.h>
#include <chrono>
#include <thread>
using namespace std::chrono;
using namespace std::this_thread;

void input (size_t &sensor,size_t &count_surveys,size_t &time_interval,size_t &count_intervals ){
    sensor = 0, count_surveys = 0, time_interval = 0, count_intervals = 0;
    std::cout << "Enter the sensor number :" << std::endl;
    std::cin >> sensor;
    std::cout << "Enter the number of surveys :" << std::endl;
    std::cin >> count_surveys;
    std::cout << "Enter the time_interval :" << std::endl;
    std::cin >> time_interval;
    std::cout << "Enter the number of intervals :"<< std::endl;
    std::cin >> count_intervals;
    return;
}

int main (){
    //ввод данных
    Plant plant;
    plant_init(plant);
    size_t sensor, count_surveys, time_interval, count_intervals;
    input(sensor, count_surveys, time_interval, count_intervals);
    std::vector<double>sensor_values(count_surveys);
    for (size_t i = 0; i < count_surveys; i++){
        sensor_values[i] = plant_measure(sensor,plant);
        sleep_for(seconds(time_interval));
    }
    std::cout << "Sensor values: " << std::endl;
    for (size_t i = 0; i < count_surveys; i++){
        std::cout << "[" << i + 1 << "]: " << sensor_values[i] << "   ";
        if ((i + 1) % 5 == 0 && i != 0) std::cout << std::endl;
    }
    //расчет
    //1. найдем минимум и максимум
    double min = sensor_values[0];
    double max = sensor_values[0];
    for (double value : sensor_values){
        if (min > value) min = value;
        if (max < value) max = value;
    }


    return 0;
}

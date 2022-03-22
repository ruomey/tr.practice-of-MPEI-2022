#include <iostream>
#include "plant.h"
#include <vector>
#include <math.h>
#include <chrono>
#include <thread>
using namespace std::chrono;
using namespace std::this_thread;
//ввод
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
//поиск количества значений попадающих в интервал
void hit_rate(std::vector<double>values, size_t count_surveys, std::vector<size_t> &hit_rates, size_t count_intervals, double lenght_interval,double min){
    for(size_t i = 0; i < count_surveys; i++){
            bool found = false;
            for(size_t count = 0; count < (count_intervals - 1) && !found; count++){
                auto lo = min + (count * lenght_interval);
                auto hi = min + ((count + 1)* lenght_interval);
                if ( (values[i] >= lo) && (values[i] < hi)) {
                    found = true;
                    hit_rates[i]++;
                }
            }
            if(!found) hit_rates[count_intervals - 1]++;
    }
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
    //1. поиск минимум и максимум
    double min = sensor_values[0];
    double max = sensor_values[0];
    for (double value : sensor_values){
        if (min > value) min = value;
        if (max < value) max = value;
    }
    double lenght_interval = 0;
    std::vector<size_t>hit_rates(count_intervals,0);
    lenght_interval = (max - min)/count_intervals;
    hit_rate(sensor_values,count_surveys, hit_rates, count_intervals, lenght_interval,min);
    return 0;
}

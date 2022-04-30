#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <string>
#include "hist.h"
#include "plant.h"
#include "graph.h"

size_t hit_rate_research(std::vector<double>values, size_t count_surveys, size_t number_interval,double lenght_interval,double min){
    size_t hit_rate = 0;
    for(size_t i = 0; i < count_surveys; i++){
        auto lo = min + ((number_interval-1) * lenght_interval);
        auto hi = min + ((number_interval)* lenght_interval);
        if ((values[i] >= lo) && (values[i] < hi)) hit_rate++;
    }
    return hit_rate;
}


int main(){
    Plant plant;
    plant_init(plant);
    size_t sensor, count_surveys, count_intervals, number_interval, count_min, count_max,interval;
    double time_interval;
    input(sensor, count_surveys, time_interval, count_intervals);
    std::vector<double>sensor_values(count_surveys,0);
    input_values(sensor_values,sensor,plant);
    std::cout << "Enter number interval: ";
    std::cin >> number_interval;
    std::cout << "Enter min number: ";
    std::cin >> count_min;
    std::cout << "Enter max number: ";
    std::cin >> count_max;
    std::cout << "Enter interval: ";
    std::cin >> interval;
    double max,min;
    find_minmax(sensor_values, max, min);
    double lenght_interval = 0;
    lenght_interval = (max - min)/count_intervals;
    std::vector<size_t>hit_rates((count_max - count_min + interval)/interval,0);
    size_t i = 0;
    for(size_t j = count_min; j <= count_max ; j+=interval){
        hit_rates[i] = hit_rate_research(sensor_values,j,number_interval,lenght_interval,min);
        i++;
    }
    std::vector<float>relative_numbers(i,0);
    for(size_t j = 0; j < i; j ++){
        relative_numbers[j] = (static_cast<float>(hit_rates[j]) / ((count_max - count_min + interval)/interval));
    }
    std::vector<float>steps((count_max - count_min + interval)/interval);
    size_t count = 0;
    for(size_t j = 0; j < steps.size(); j++){
        steps[j] = count_min + j*interval;
    }
    for(size_t k = 0; k < 3; k++){
            std::cout <<"+"<< std::setw(15) << std::setfill('-') << "+";
    }
    std::cout << std::endl;
    std::cout << "|" << std::setw(14) << std::setfill(' ') << "N" << "||" << std::setw(14) << std::setfill(' ') << "Measurements" << "||" << std::setw(14) << std::setfill(' ') << "Hits" << "|" << std::endl;
    for(size_t k = 0; k < 3; k++){
            std::cout <<"+"<< std::setw(15) << std::setfill('-') << "+";
    }
    std::cout << std::endl;
    for(size_t j = 0; j < hit_rates.size(); j++){
        std::cout << "|" << std::setw(14) <<std::setfill(' ')<< j+1 << "||" << std::setw(14)<<std::setfill(' ') << count_min + j*interval << "||" << std::setw(14)<<std::setfill(' ') << relative_numbers[j] << "|" << std::endl;
        for(size_t k = 0; k < 3; k++){
            std::cout <<"+"<< std::setw(15) << std::setfill('-') << "+";
        }
        std::cout << std::endl;
    }

    graph(steps,relative_numbers);
}

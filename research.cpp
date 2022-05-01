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


int main(){
    Plant plant;
    plant_init(plant);
    size_t sensor, count_surveys, count_intervals, number_interval, count_min, count_max,interval;
    double time_interval;
    input(sensor, count_surveys, time_interval, count_intervals);
    input_for_research(number_interval, count_min, count_max, interval);
    std::vector<size_t>hit_rates((count_max - count_min + interval)/interval,0);
    std::vector<float>relative_numbers(hit_rates.size(),0);
    size_t i = 0;
    double min = 0, max = 0;
    find_minmax_for_research(count_min, sensor, plant, count_max, interval, max, min);
    for(size_t j = count_min; j < count_max ; j+=interval){
        std::vector<double>sensor_values(j,0);
        input_values(sensor_values,sensor,plant);
        hit_rates[i] = research(sensor_values, number_interval, count_intervals, max, min);
        relative_numbers[i] = static_cast<float>(hit_rates[i]) / j;
        i++;
    }

    std::vector<float>steps(hit_rates.size());
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

    size_t found = 0;
    for (size_t j = 0; j < hit_rates.size(); j++){
        if (hit_rates[j] == 0) found++;
    }
    if(found != hit_rates.size()) graph(steps,relative_numbers);
    else std::cout << "Not a single value fell into this interval" << std::endl;
}

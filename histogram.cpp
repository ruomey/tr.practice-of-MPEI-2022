
#include <iostream>
#include "plant.h"
#include <vector>
#include <math.h>
#include <fstream>
#include <string>
#include "histogram.h"

void input (size_t &sensor,size_t &count_surveys,double &time_interval,size_t &count_intervals ){
    sensor = 0, count_surveys = 0, time_interval = 0, count_intervals = 0;
    std::cerr << "Enter the sensor number :" << std::endl;
    std::cin >> sensor;
    std::cerr << "Enter the number of surveys :" << std::endl;
    std::cin >> count_surveys;
    std::cerr << "Enter the time_interval :" << std::endl;
    std::cin >> time_interval;
    std::cerr << "Enter the number of intervals :"<< std::endl;
    std::cin >> count_intervals;
    return;
}

void find_minmax(std::vector<double> numbers, double& min, double& max) {
    min = numbers[0];
    max = numbers[0];
    if(numbers.size() == 0)
    {
        return;
    }
    for (double number : numbers){
        if (min > number) min = number;
        if (max < number) max = number;
    }
}


std::vector<size_t> hit_rate(std::vector<double>values, size_t count_surveys,size_t count_intervals){
    double min,max;
    find_minmax(values, min, max);
    std::vector<size_t>bins(count_intervals,0);
    double bin_size = (max - min)/count_intervals;
    for (size_t i = 0; i < values.size(); i++){
        bool found = false;
        for(size_t j = 0; j < (count_intervals - 1) && !found; j++){
            auto lo = min +  j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= values[i]) && (values[i] < hi)) {
                bins[j]++;
                found = true;
            }
        }
        if (!found){
            bins[count_intervals - 1]++;
        }
    }
    return bins;
}

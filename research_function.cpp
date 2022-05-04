#include <iostream>
#include <vector>
#include <math.h>
#include "research_function.h"
#include "plant.h"
#include "input.h"
size_t research (std::vector<double>numbers,size_t number_interval, size_t count_intervals,double max, double min){
    double lenght_interval = (max-min)/count_intervals;
    double left = min + lenght_interval*(number_interval - 1);
    double right = min + lenght_interval*(number_interval);
    size_t count = 0;
    if (number_interval!= count_intervals){
        for (size_t i = 0; i < numbers.size(); i++){
            if ((left <= numbers[i]) && (numbers[i] < right)){
                count++;
            }
        }
    }
    else {
        for (size_t i = 0; i < numbers.size(); i++){
            if (left <= numbers[i] && numbers[i] <= max){
                count++;
            }
        }
    }
    return count;
}


void find_minmax_for_research(size_t count_min, size_t sensor, Plant plant, size_t count_max,size_t interval, float &max, float &min){
    for(size_t j = count_min; j <= count_max; j+=interval){
        float temp_max, temp_min;
        std::vector<float>sensor_values(j,0);
        input_values_float(sensor_values,sensor,plant);
        find_minmax_float(sensor_values,temp_max,temp_min);
        if (max < temp_max) max = temp_max;
        if (min > temp_min) min = temp_min;
    }
}

void find_minmax_float(std::vector<float> &values, float &max, float &min){
    min = values[0];
    max = values[0];
    for (float value : values){
        if (min > value) min = value;
        if (max < value) max = value;
    }
}

#include <iostream>
#include <vector>
#include <math.h>
#include "hist.h"
#include "plant.h"

void input (size_t &sensor, size_t &count_surveys, double &time_interval, size_t &count_intervals){
    sensor = 0, count_surveys = 0, time_interval = 0, count_intervals = 0;
    std::cerr << "Enter the sensor number :";
    std::cin >> sensor;
    std::cerr << "Enter the number of surveys :";
    std::cin >> count_surveys;
    std::cerr << "Enter the time_interval :";
    std::cin >> time_interval;
    std::cerr << "Enter the number of intervals :";
    std::cin >> count_intervals;
    return;
}
void input_for_research(size_t &number_interval, size_t &count_min, size_t &count_max, size_t &interval){
    number_interval = 0, count_min = 0, count_max = 0, interval = 0;
    std::cout << "Enter number interval: ";
    std::cin >> number_interval;
    std::cout << "Enter min number: ";
    std::cin >> count_min;
    std::cout << "Enter max number: ";
    std::cin >> count_max;
    std::cout << "Enter interval: ";
    std::cin >> interval;
    return;
}
void input_values(std::vector<double>&result, size_t sensor,Plant plant){
    for (size_t i = 0; i < result.size(); i++){
        result[i] = plant_measure(sensor,plant);
        //sleep_for(milliseconds(time_interval));
    }

    return;
}
//поиск количества значений попадающих в интервал
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

void hit_rate(std::vector<double>values, size_t count_surveys, std::vector<size_t> &hit_rates, size_t count_intervals, double lenght_interval,double min){
    for(size_t i = 0; i < count_surveys; i++){
            bool found = false;
            for(size_t count = 0; count < (count_intervals - 1) && !found; count++){
                auto lo = min + (count * lenght_interval);
                auto hi = min + ((count + 1)* lenght_interval);
                if ( (values[i] >= lo) && (values[i] < hi)) {
                    found = true;
                    hit_rates[count]++;
                }
            }
            if(!found) hit_rates[count_intervals - 1]++;
    }
    return;
}

void find_minmax_for_research(size_t count_min, size_t sensor, Plant plant, size_t count_max,size_t interval, double &max, double &min){
    for(size_t j = count_min; j <= count_max; j+=interval){
        double temp_max, temp_min;
        std::vector<double>sensor_values(j,0);
        input_values(sensor_values,sensor,plant);
        find_minmax(sensor_values,temp_max,temp_min);
        if (max < temp_max) max = temp_max;
        if (min > temp_min) min = temp_min;
    }
}
void find_minmax(const std::vector<double> &values, double &max, double &min){
    min = values[0];
    max = values[0];
    for (double value : values){
        if (min > value) min = value;
        if (max < value) max = value;
    }
}

void find_minmax_float(const std::vector<float> &values, float &max, float &min){
    min = values[0];
    max = values[0];
    for (double value : values){
        if (min > value) min = value;
        if (max < value) max = value;
    }
}

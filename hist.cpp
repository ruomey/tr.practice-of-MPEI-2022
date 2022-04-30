#include <iostream>
#include <vector>
#include <math.h>
#include "hist.h"
#include "plant.h"

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
void input_values(std::vector<double>&result, size_t sensor,Plant plant){
    for (size_t i = 0; i < result.size(); i++){
        result[i] = plant_measure(sensor,plant);
        //sleep_for(milliseconds(time_interval));
    }

    return;
}
//поиск количества значений попадающих в интервал
void hit_rate(std::vector<double>values, size_t count_surveys, std::vector<size_t> &hit_rates, size_t count_intervals, double lenght_interval,double min){
    for(size_t i = 0; i < count_surveys; i++){
            bool found = false;
            for(size_t count = 0; count < (count_intervals - 1) && !found; count++){
                auto lo = min + (count * lenght_interval);
                auto hi = min + ((count + 1)* lenght_interval);
                if ((values[i] >= lo) && (values[i] < hi)) {
                    found = true;
                    hit_rates[count]++;
                }
            }
            if(!found) hit_rates[count_intervals - 1]++;
    }
    return;
}
void find_minmax(const std::vector<double> &values, double &max, double &min){
    min = values[0];
    max = values[0];
    for (double value : values){
        if (min > value) min = value;
        if (max < value) max = value;
    }
}

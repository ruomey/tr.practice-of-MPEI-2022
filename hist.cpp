#include <iostream>
#include <vector>
#include <math.h>
#include "hist.h"
#include "plant.h"


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

void find_minmax(const std::vector<double> &values, double &max, double &min){
    min = values[0];
    max = values[0];
    for (double value : values){
        if (min > value) min = value;
        if (max < value) max = value;
    }
}

#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <iostream>
#include "plant.h"
#include <vector>
#include <math.h>
#include <fstream>
#include <string>

void input (size_t &sensor,size_t &count_surveys,double &time_interval,size_t &count_intervals);
void find_minmax(std::vector<double> numbers, double& min, double& max);
std::vector<size_t> hit_rate(std::vector<double>values, size_t count_surveys,size_t count_intervals);

#endif // HISTOGRAM_H_INCLUDED

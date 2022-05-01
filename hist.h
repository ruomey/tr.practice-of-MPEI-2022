#ifndef HIST_H_INCLUDED
#define HIST_H_INCLUDED
#include <iostream>
#include <vector>
#include "plant.h"

void input (size_t &sensor, size_t &count_surveys, double &time_interval, size_t &count_intervals);
void input_values(std::vector<double>&result, size_t sensor,Plant plant);
size_t research (std::vector<double>numbers, size_t number_interval,size_t count_intervals, double max, double min);
void find_minmax(const std::vector<double> &values, double &max, double &min);
void find_minmax_float(const std::vector<float> &values, float &max, float &min);
void input_for_research(size_t &number_interval, size_t &count_min, size_t &count_max, size_t &interval);
void hit_rate(std::vector<double>values, size_t count_surveys, std::vector<size_t> &hit_rates, size_t count_intervals, double lenght_interval,double min);
void find_minmax_for_research(size_t count_min, size_t sensor, Plant plant, size_t count_max,size_t interval, double &max, double &min);
#endif // HIST_H_INCLUDED

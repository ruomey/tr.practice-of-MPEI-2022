#ifndef RESEARCH_FUNCTION_H_INCLUDED
#define RESEARCH_FUNCTION_H_INCLUDED
#include <iostream>
#include <vector>
#include <math.h>
#include "plant.h"

size_t research (std::vector<double>numbers, size_t number_interval,size_t count_intervals, double max, double min);
void find_minmax_for_research(size_t count_min, size_t sensor, Plant plant, size_t count_max,size_t interval, float &max, float &min);
void find_minmax_float(std::vector<float> &values, float &max, float &min);
#endif // RESEARCH_FUNCTION_H_INCLUDED

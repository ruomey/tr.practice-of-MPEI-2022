#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <iostream>
#include <vector>
#include <math.h>
#include "plant.h"

void input (int &sensor, int &count_surveys, double &time_interval, int &count_intervals);
void input_values(std::vector<double>&result, int sensor, Plant plant);
void input_for_research(int &number_interval, int &count_min, int &count_max, int &interval, int count_intervals);
void input_values_float(std::vector<float>&result, int sensor,Plant plant);
#endif // INPUT_H_INCLUDED

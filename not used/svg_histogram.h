#ifndef SVG_HISTOGRAM_H_INCLUDED
#define SVG_HISTOGRAM_H_INCLUDED
#include <iostream>
#include "plant.h"
#include "histogram.h"
#include "svg_histogram.h"
#include <vector>
#include <math.h>
#include <fstream>
#include <string>

void svg_begin(double width, double height);
void svg_end();
void svg_rect(double x, double y, double width, double height, std::string stroke = "black", std::string fill ="black");
void svg_text(double left, double baseline, std::string text);
void show_histogram_svg(const std::vector<size_t>hit_rates,std::vector<double>values, std::vector<double>relative_numbers);

#endif // SVG_HISTOGRAM_H_INCLUDED

#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <string>
#include <windows.h>
#include <shellapi.h>
#include <iomanip>
#include "plant.h"
#include "hist.h"

using namespace std::chrono;
using namespace std::this_thread;
std::ofstream out_histogram_file("file_histogram.svg");


//ввод

void svg_begin(double width, double height) {
    out_histogram_file << "<?xml version='1.0' encoding='UTF-8'?>\n";
    out_histogram_file << "<svg ";
    out_histogram_file << "width='" << width << "' ";
    out_histogram_file << "height='" << height << "' ";
    out_histogram_file << "viewBox='0 0 " << width << " " << height << "' ";
    out_histogram_file << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end() {
    out_histogram_file<< "</svg>\n";
    out_histogram_file.close();
}
void svg_rect(double x, double y, double width, double height, std::string stroke = "black", std::string fill ="black"){
    out_histogram_file << "<rect x='"<< x <<"' y='"<< y <<"' width='"<< width <<"' height='"<< height <<"' stroke='"<< stroke <<"' fill='"<< fill <<"'></rect>";
}
void svg_text(double left, double baseline, std::string text) {
    out_histogram_file << "<text x='" << left << "' y='"<< baseline <<"'>'"<< text <<"'</text>";
}
void show_histogram_svg(const std::vector<size_t>hit_rates,std::vector<double>relative_numbers,double min, double length_interval) {
    const auto IMAGE_WIDTH = 1080;
    const auto IMAGE_HEIGHT = 1920;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 40;
    const auto BLOCK_WIDTH = 40;
    const auto HISTOGRAM_MAX_WIDTH = IMAGE_WIDTH - TEXT_LEFT - TEXT_WIDTH;
    size_t max_bin = hit_rates[0];
    for (size_t bin : hit_rates){
        if (max_bin < bin) max_bin = bin;
    }
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = TEXT_BASELINE;
    size_t count = 0;
    for (size_t bin : hit_rates) {
        std::string str = std::to_string(relative_numbers[count]);
        size_t height = bin;
        if (max_bin * BLOCK_WIDTH > HISTOGRAM_MAX_WIDTH){
            height = HISTOGRAM_MAX_WIDTH * (static_cast<double> (bin) / (max_bin * BLOCK_WIDTH));
        }
        const double bin_width = BLOCK_WIDTH * height;
        svg_text(0, top  + (BIN_HEIGHT/2), std::to_string(bin));
        svg_text(0, top  + BIN_HEIGHT, str.substr(0,4));
        str = std::to_string(min + count * length_interval);
        svg_text(0,top,str.substr(0,4));
        str = std::to_string(min + (count+1) * length_interval);
        svg_text(0,top + BIN_HEIGHT + TEXT_BASELINE,str.substr(0,4));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT,"#AAAAAA","#DC143C");
        svg_rect(TEXT_WIDTH, top += BIN_HEIGHT, bin_width, (BIN_HEIGHT / 2),"#FFFFFF","#FFFFFF");
        top += BIN_HEIGHT/2;
        count ++;
    }
    svg_end();
}



int main (){
    //ввод данных
    Plant plant;
    plant_init(plant);
    size_t sensor, count_surveys, count_intervals;
    double time_interval;
    input(sensor, count_surveys, time_interval, count_intervals);
    std::vector<double>sensor_values(count_surveys,0);
    input_values(sensor_values,sensor,plant);
    std::cout << "Sensor values: " << std::endl;
    for (size_t i = 0; i < count_surveys; i++){
        std::cout << "[" << i + 1 << "]: " <<std::setw(10) << std::setprecision(5)<< std::setfill(' ')<<sensor_values[i] <<"   ";
        if ((i + 1) % 5 == 0 && i != 0) std::cout << std::endl;
    }
    //расчет
    //1. поиск минимума и максимума
    double max,min;
    find_minmax(sensor_values, max, min);
    double lenght_interval = 0;
    lenght_interval = (max - min)/count_intervals;
    std::vector<size_t>hit_rates(count_intervals,0);
    hit_rate(sensor_values,count_surveys, hit_rates, count_intervals, lenght_interval, min);
    std::vector<double>relative_numbers(count_surveys);
    for(size_t i = 0; i < count_intervals; i ++){
        relative_numbers[i] = (static_cast<double>(hit_rates[i]) / count_surveys);
    }
    show_histogram_svg(hit_rates,relative_numbers,min,lenght_interval);
    ShellExecute(NULL, "open", "file_histogram.svg", NULL, NULL, SW_SHOWNORMAL);
    return 0;
}

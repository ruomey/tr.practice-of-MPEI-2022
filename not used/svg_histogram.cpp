#include <iostream>
#include "plant.h"
#include "histogram.h"
#include "svg_histogram.h"
#include <vector>
#include <math.h>
#include <fstream>
#include <string>
std::ofstream out_histogram_file("file_histogram.svg");
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
void svg_rect(double x, double y, double width, double height, std::string stroke, std::string fill){
    out_histogram_file << "<rect x='"<< x <<"' y='"<< y <<"' width='"<< width <<"' height='"<< height <<"' stroke='"<< stroke <<"' fill='"<< fill <<"'></rect>";
}
void svg_text(double left, double baseline, std::string text) {
    out_histogram_file << "<text x='" << left << "' y='"<< baseline <<"'>'"<< text <<"'</text>";
}
void show_histogram_svg(const std::vector<size_t>hit_rates,std::vector<double>value, std::vector<double>relative_numbers) {
    const auto IMAGE_WIDTH = 500;
    const auto IMAGE_HEIGHT = 600;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 40;
    const auto BLOCK_WIDTH = 40;
    const auto HISTOGRAM_MAX_WIDTH = IMAGE_WIDTH - TEXT_LEFT - TEXT_WIDTH;
    double max,min;
    find_minmax(value,min,max);
    double bin_size = (max - min)/hit_rates.size();
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
        str = std::to_string(min + count * bin_size);
        svg_text(0,top,str.substr(0,4));
        str = std::to_string(min + (count+1) * bin_size);
        svg_text(0,top + BIN_HEIGHT + TEXT_BASELINE,str.substr(0,4));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT,"#AAAAAA","#DC143C");
        svg_rect(TEXT_WIDTH, top += BIN_HEIGHT, bin_width, (BIN_HEIGHT / 2),"#FFFFFF","#FFFFFF");
        top += BIN_HEIGHT/2;
        count ++;
    }
    svg_end();
}

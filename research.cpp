#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <string>
#include "research_function.h"
#include "input.h"
#include "plant.h"
#include "graph.h"


int main(){
    Plant plant;
    plant_init(plant);
    int count_surveys, count_intervals, number_interval, count_min, count_max,interval;
    int sensor;
    double time_interval;
    int k1 = -1;
    while(k1 == -1){
        input(sensor, count_surveys, time_interval, count_intervals);
        int k = -1;
        while (k == - 1){
            input_for_research(number_interval, count_min, count_max, interval, count_intervals);
            std::vector<size_t>hit_rates((count_max - count_min + interval)/interval,0);
            std::vector<float>relative_numbers(hit_rates.size(),0);
            size_t i = 0;
            float min = 0, max = 0;
            find_minmax_for_research(count_min, sensor, plant, count_max, interval, max, min);
            for(int j = count_min; j < count_max ; j+=interval){
                std::vector<double>sensor_values(j,0);
                input_values(sensor_values,sensor,plant);
                hit_rates[i] = research(sensor_values, number_interval, count_intervals, max, min);
                relative_numbers[i] = static_cast<float>(hit_rates[i]) / j;
                i++;
            }

            std::vector<float>steps(hit_rates.size());
            for(size_t j = 0; j < steps.size(); j++){
                steps[j] = count_min + j*interval;
            }

            for(size_t k = 0; k < 3; k++){
                std::cout <<"+"<< std::setw(15) << std::setfill('-') << "+";
            }
            std::cout << std::endl;
            std::cout << "|" << std::setw(14) << std::setfill(' ') << "N" << "||" << std::setw(14) << std::setfill(' ') << "Measurements" << "||"
            << std::setw(14) << std::setfill(' ') << "Hits" << "|" << std::endl;
            for(size_t k = 0; k < 3; k++){
                std::cout <<"+"<< std::setw(15) << std::setfill('-') << "+";
            }
            std::cout << std::endl;
            for(size_t j = 0; j < hit_rates.size(); j++){
                std::cout << "|" << std::setw(14) <<std::setfill(' ')<< j+1 << "||" << std::setw(14)<<std::setfill(' ') << count_min + j*interval << "||"
                << std::setw(14)<<std::setfill(' ') << relative_numbers[j] << "|" << std::endl;
                for(size_t k = 0; k < 3; k++){
                    std::cout <<"+"<< std::setw(15) << std::setfill('-') << "+";
                }
                std::cout << std::endl;
            }

            size_t found = 0;
            for (size_t j = 0; j < hit_rates.size(); j++){
                if (hit_rates[j] == 0) found++;
            }
            if(found != hit_rates.size()) graph(steps,relative_numbers);
            else std::cout << "Not a single value fell into this interval" << std::endl;
            std::string ans = "-1";
            int count_for_error = 0;
            while (ans == "-1"&& count_for_error < 10){
                std::cout << "Enter 'y' if you want to plot a new graph over a new interval, enter 'n' if you want go to sensor selection" << std::endl;
                std::cout << "Enter y/n: ";
                std::cin >> ans;
                if (ans == "n") k = 1;
                else if(ans == "y") k = -1;
                else ans = "-1";
                if (count_for_error == 5) std::cout << "Warning: 5 tries left" << std::endl;
                if (count_for_error == 8) std::cout << "Warning: 1 tries left" << std::endl;
                if (count_for_error == 9) exit(-1);
                count_for_error ++;
            }

        }
        if (k == 1) {
           std::string ans = "-1";
           int count_for_error = 0;
            while (ans == "-1" && count_for_error < 10){
                std::cout << "Enter 'y' if you want a change sensor for research, enter 'n' if you want to close the programm" << std::endl;
                std::cout << "Enter y/n: ";
                std::cin >> ans;
                if (ans == "n") k1 = 1;
                else if (ans == "ded") {
                    std::cout << "please, give a good rating" << std::endl;
                    ans = "-1";
                }
                else if (ans == "git") {
                    std::cout << "git)" << std::endl;
                    ans = "-1";
                }
                else if (ans == "1"){
                    std::cout << "lonely ded, so he will soon be dead inside" << std::endl;
                    ans = "-1";
                }
                else if (ans == "y") k1 = -1;
                else ans = "-1";
                if (count_for_error == 5) std::cout << "Warning: 5 tries left" << std::endl;
                if (count_for_error == 8) std::cout << "Warning: 1 tries left" << std::endl;
                if (count_for_error == 9) exit(-1);
                count_for_error ++;
            }

        }

    }
}

#include <iostream>
#include <vector>
#include <math.h>
#include "input.h"
#include "plant.h"

void input (int &sensor, int &count_surveys, double &time_interval, int &count_intervals){
    sensor = -1, count_surveys = -1, time_interval = -1, count_intervals = -1;
    int count_for_error = 0;
    while(sensor == -1 && count_for_error < 10){
        std::cerr << "Enter the sensor number :";
        std::cin >> sensor;
        if (sensor <= 0) {
            std :: cout << "Enter correct sensor number(from 1 to 90)" << std::endl;
            sensor = -1;
            if (count_for_error == 5) std::cout << "Warning: 5 tries left" << std::endl;
            if (count_for_error == 8) std::cout << "Warning: 1 tries left" << std::endl;
            if (count_for_error == 9) exit(-1);
            count_for_error ++;

        }
    }
    count_for_error = 0;
    while(count_surveys == -1 && count_for_error < 10){
        std::cerr << "Enter number of surveys :";
        std::cin >> count_surveys;
        if (count_surveys <= 0) {
            std :: cout << "Enter correct number of surveys ( > 0)" << std::endl;
            count_surveys = -1;
            if (count_for_error == 5) std::cout << "Warning: 5 tries left" << std::endl;
            if (count_for_error == 8) std::cout << "Warning: 1 tries left" << std::endl;
            if (count_for_error == 9) exit(-1);
            count_for_error ++;

        }
    }
    count_for_error = 0;
    while(time_interval == -1 && count_for_error < 10){
        std::cerr << "Enter time interval :";
        std::cin >> time_interval;
        if (time_interval < 0) {
            std :: cout << "Enter correct time interval ( >= 0)" << std::endl;
            time_interval = -1;
            if (count_for_error == 5) std::cout << "Warning: 5 tries left" << std::endl;
            if (count_for_error == 8) std::cout << "Warning: 1 tries left" << std::endl;
            if (count_for_error == 9) exit(-1);
            count_for_error ++;

        }
    }
    count_for_error = 0;
    while(count_intervals == -1 && count_for_error < 10){
        std::cerr << "Enter count intervals :";
        std::cin >> count_intervals;
        if (count_intervals <= 0) {
            std :: cout << "Enter correct count intervals ( > 0)" << std::endl;
            count_intervals = -1;
            if (count_for_error == 5) std::cout << "Warning: 5 tries left" << std::endl;
            if (count_for_error == 8) std::cout << "Warning: 1 tries left" << std::endl;
            if (count_for_error == 9) exit(-1);
            count_for_error ++;

        }
    }
    return;
}
void input_for_research(int &number_interval, int &count_min, int &count_max, int &interval, int count_intervals){
    int k1 = -1;
    int count_for_error4 = 0;
    int count_for_error = 0;
    while (k1 == -1 && count_for_error4 < 10){
        number_interval = -1;
        while(number_interval == -1 && count_for_error < 10){
            std::cerr << "Enter the number interval:";
            std::cin >> number_interval;
            if (number_interval <= 0) {
                std :: cout << "Enter correct number interval( > 0)" << std::endl;
                number_interval = -1;
                if (count_for_error == 5) std::cout << "Warning: 5 tries left" << std::endl;
                if (count_for_error == 8) std::cout << "Warning: 1 tries left" << std::endl;
                if (count_for_error == 9) exit(-1);
                count_for_error ++;
            }
        }
        if(0 < number_interval && number_interval <= count_intervals) k1 = 1;
        else{
            std::cout << "Enter correct number interval ( > 0  and <= count intervals )" << std::endl;
            if (count_for_error4 == 5) std::cout << "Warning: 5 tries left" << std::endl;
            if (count_for_error4 == 8) std::cout << "Warning: 1 tries left" << std::endl;
            if (count_for_error4 == 9) exit(-1);
            count_for_error4 ++;
        }
    }
    int count_for_error2 = 0;
    int k = -1;
    while (k == -1 && count_for_error2 < 10){
        count_min = -1, count_max = -1, interval = -1;
        int count_for_error3 = 0;
        while(count_min == -1 && count_for_error3 < 10){
            std::cerr << "Enter min number mesuarments:";
            std::cin >> count_min;
            if (count_min <= 0) {
                std :: cout << "Enter correct min number mesuarments ( > 0)" << std::endl;
                count_min = -1;
                if (count_for_error == 5) std::cout << "Warning: 5 tries left" << std::endl;
                if (count_for_error == 8) std::cout << "Warning: 1 tries left" << std::endl;
                if (count_for_error == 9) exit(-1);
                count_for_error ++;

            }
        }
        count_for_error3 = 0;
        while(count_max == -1 && count_for_error3 < 10){
            std::cerr << "Enter max number mesuarments:";
            std::cin >> count_max;
            if (count_max <= 0) {
                std :: cout << "Enter correct max number mesuarments ( > 0)" << std::endl;
                count_max = -1;
                if (count_for_error == 5) std::cout << "Warning: 5 tries left" << std::endl;
                if (count_for_error == 8) std::cout << "Warning: 1 tries left" << std::endl;
                if (count_for_error == 9) exit(-1);
                count_for_error ++;

            }
        }
        count_for_error3 = 0;
        while(interval == -1 && count_for_error3 < 10){
            std::cerr << "Enter interval:";
            std::cin >> interval;
            if (interval <= 0) {
                std :: cout << "Enter correct interval ( > 0)" << std::endl;
                interval = -1;
                if (count_for_error == 5) std::cout << "Warning: 5 tries left" << std::endl;
                if (count_for_error == 8) std::cout << "Warning: 1 tries left" << std::endl;
                if (count_for_error == 9) exit(-1);
                count_for_error ++;

            }
        }
        if (count_min < count_max && interval < (count_max - count_min)){
            k = 1;
        }
        else{
            std::cout << "Enter correct interval, max and min number of mesuarements." << std::endl;
            if (count_for_error2 == 5) std::cout << "Warning: 5 tries left" << std::endl;
            if (count_for_error2 == 8) std::cout << "Warning: 1 tries left" << std::endl;
            if (count_for_error2 == 9) exit(-1);
            count_for_error2++;
        }
    }
    return;
}
void input_values(std::vector<double>&result, int sensor,Plant plant){
    for (size_t i = 0; i < result.size(); i++){
        result[i] = plant_measure(sensor,plant);
    }

    return;
}
void input_values_float(std::vector<float>&result, int sensor,Plant plant){
    for (size_t i = 0; i < result.size(); i++){
        result[i] = plant_measure(sensor,plant);
    }

    return;
}

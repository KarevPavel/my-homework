//
// Created by yacopsae on 20/08/2021.
//


#include <cstddef>
#include <statistics.h>
#include <min.h>
#include <max.h>
#include <average.h>
#include <std.h>
#include <pct90.h>
#include <pct95.h>
#include <iostream>

int main() {

    const size_t statistics_count = 6;
    IStatistics *statistics[statistics_count];

    statistics[0] = new Min{};
    statistics[1] = new Max{};
    statistics[2] = new Average{};
    statistics[3] = new Std{};
    statistics[4] = new Pct90{};
    statistics[5] = new Pct95{};

/*    double val = 0;
    while (std::cin >> val) {
        for (size_t i = 0; i < statistics_count; ++i) {
            statistics[i]->update(val);
        }
    }*/

    double val[10] = {
            1,
            3,
            56,
            67,
            23,
            12,
            45,
            3,
            22,
            10
    };


    for (auto const & v : val) {
        for (auto & statistic : statistics) {
            statistic->update(v);
        }
    }


    // Handle invalid input data
    if (!std::cin.eof() && !std::cin.good()) {
        std::cerr << "Invalid input data\n";
        return 1;
    }

    // Print results if any
    for (size_t i = 0; i < statistics_count; ++i) {
        std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
    }

    // Clear memory - delete all objects created by new
    for (size_t i = 0; i < statistics_count; ++i) {
        delete statistics[i];
    }
    return 0;
}
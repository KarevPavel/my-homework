//
// Created by yacopsae on 20/08/2021.
//
#pragma once

#include <limits>
#include "statistics.h"

class Min : public IStatistics {
public:
    Min();
    void update(double next) override;
    double eval() const override;
    const char * name() const override;
};
//
// Created by yacopsae on 20/08/2021.
//

#include "statistics.h"

class Average : public IStatistics {
public:
    Average();
    bool check(double next) override;
    void setVal(double val) override;
    double eval() const override;

private:
    double sum;
};
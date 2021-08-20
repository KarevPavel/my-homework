#include <iostream>
#include <limits>
#include <vector>
#include <cmath>
#include <algorithm>

class IStatistics {
public:

    IStatistics(double mEval, char *mName) : m_eval(mEval), m_name(mName), m_el_count(0) {}

    virtual ~IStatistics() {}

    virtual void setVal(double val) = 0;

    virtual bool check(double next) = 0;

    virtual void update(double next) {
        increaseCount();
        if (check(next)) setVal(next);
    }

    virtual void increaseCount() {
        m_el_count++;
    }

    virtual double eval() const {
        return m_eval;
    }

    virtual const char *name() const {
        return m_name;
    }

protected:
    double m_el_count;
    double m_eval;
    char *m_name;
};

class Min : public IStatistics {
public:
    Min() : IStatistics(std::numeric_limits<double>::max(), "min") {
    }

    bool check(double next) override {
        return next < eval();
    }

    void setVal(double val) override {
        m_eval = val;
    }
};

class Max : public IStatistics {
public:
    Max() : IStatistics(std::numeric_limits<double>::min(), "max") {
    }

    bool check(double next) override {
        return next > eval();
    }

    void setVal(double val) override {
        m_eval = val;
    }
};

class Average : public IStatistics {
public:
    Average() : IStatistics(0, "average") {
    }

    bool check(double next) override {
        return true;
    }

    void setVal(double val) override {
        sum += val;
    }

    double eval() const override {
        return sum / m_el_count;
    }

private:
    double sum;
};

//standard deviation
class Std : public IStatistics {
public:
    Std() : IStatistics(0, "std"), values() {
    }

    bool check(double next) override {
        return true;
    }

    void setVal(double val) override {
        values.push_back(val);
    }

    double eval() const override {
        double _average = average();
        double sum{0};
        for (const double &v : values) {
            sum += std::pow((v - _average), 2);
        }
        return std::sqrt(sum / values.size());
    }

    double average() const {
        double sum{0};
        for (const double &v : values) {
            sum += v;
        }
        return sum / values.size();
    }

private:
    std::vector<double> values;
};

class Pct : public IStatistics {
public:
    Pct(char * name, double percent) : IStatistics(std::numeric_limits<double>::min(), name), values(), _percent{percent} {}

    bool check(double next) override {
        return true;
    }

    void setVal(double val) override {
        values.push_back(val);
        std::sort(values.begin(), values.end());
    }

    double eval() const override {
        return values.at(_percent * m_el_count);
    }

private:
    std::vector<double> values;
    double _percent;
};

class Pct90 : public Pct {
public:
    Pct90() : Pct("pct90", 0.9) {
    }
};

class Pct95 : public Pct {
public:
    Pct95() : Pct("pct95", 0.95) {
    }
};



int main() {

    const size_t statistics_count = 6;
    IStatistics *statistics[statistics_count];

    statistics[0] = new Min{};
    statistics[1] = new Max{};
    statistics[2] = new Average{};
    statistics[3] = new Std{};
    statistics[4] = new Pct90{};
    statistics[5] = new Pct95{};

    double val = 0;
    while (std::cin >> val) {
        for (size_t i = 0; i < statistics_count; ++i) {
            statistics[i]->update(val);
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
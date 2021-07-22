//
// Created by yacopsae on 21/07/2021.
//

#include "argument.h"
#include "constants.h"

bool containsParam(std::string array[][2], const std::string &name) {
    for (int i = 0; i < parameters::ARGUMENT_COUNT; i++) {
        if (array[i][0] == name)
            return true;
    }
    return false;
}

std::string getParamValue(std::string array[][2], const std::string &name) {
    for (int i = 0; i < parameters::ARGUMENT_COUNT; i++) {
        std::string paramName{array[i][0]};
        if (paramName == name) {
            if (parameters::isDebug)
                std::cout << "[DEBUG] " << "Founded! Param \"" << name << "\"" << std::endl;
            return array[i][1];
        } else if (parameters::isDebug) {
            std::cout << "[DEBUG] " << "Param \"" << name << "\"" << " != \"" << paramName << "\"" << std::endl;
        }
    }
    if (parameters::isDebug) {
        std::cout << "[DEBUG] " << "Param \"" << name << "\"" << " NOT FOUND!" << std::endl;
    }
    return std::string();
}

bool charToBool(const char &c) {
    return c == 'y' || c == 'Y';
}
#pragma once

#include "string"
#include <iostream>

bool containsParam(std::string array[][2], const std::string & name);

std::string getParamValue(std::string array[][2], const std::string & name);

bool charToBool(const char & c);

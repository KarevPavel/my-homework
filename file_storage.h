#pragma once

#include "string"
#include <iostream>
#include <fstream>
#include "constants.h"
#include <iomanip>

extern std::string** RECORDS;
extern int RECORDS_COUNT;

int getSavedRecord(const std::string & userName);

void writeRecord2File(const std::string & userName, const int & score);

void printCurrentScores();

void printRecords();

int findIndexOfName(const std::string & userName);
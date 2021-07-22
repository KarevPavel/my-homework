#pragma once

#include "string"

namespace constants {
    const std::string HELP = "help";
    const std::string MAX = "max";
    const std::string DEBUG = "debug";
    const std::string LEVEL = "level";
    const std::string TABLE = "table";
    const std::string RECORDS_FILE = "records";
    const char RECORDS_DELIM = '|';
    const int MAX_RETRIES = 5;
    const std::string EASY = "10";
    const std::string MED = "50";
    const std::string HARD = "100";
}

namespace parameters {
    extern bool isDebug;
    extern int retries;
    extern std::string userName;
    extern int ARGUMENT_COUNT;
}
#include "file_storage.h"
#include <wchar.h>

std::string** RECORDS = new std::string*[2]{};
int RECORDS_COUNT = 0;

void initRecordsArray() {
    std::ifstream recordsFile;
    recordsFile.open(constants::RECORDS_FILE);
    std::string line;

    RECORDS_COUNT = 0;
    if (recordsFile.is_open()) {
        for(int i = 0; getline(recordsFile, line); i++, RECORDS_COUNT++) {
            int index = line.find(constants::RECORDS_DELIM);
            RECORDS[i] = new std::string[2]();
            RECORDS[i][0] = line.substr(0, index);
            RECORDS[i][1] = line.substr(index + 1, line.length());
        }
        recordsFile.close();
    }
}

int getSavedRecord(const std::string & userName) {
    auto index = findIndexOfName(userName);
    if (index != -1) {
        return std::stoi(RECORDS[index][1]);
    }
    return 0;
}

void writeRecord2File(const std::string & userName, const int & score) {

    auto index = findIndexOfName(userName);
    if (index != -1) {
        RECORDS[index][1] = std::to_string(score);
    } else {
        int nextIndex = RECORDS_COUNT;
        RECORDS[nextIndex] = new std::string[2]();
        RECORDS[nextIndex][0] = userName;
        RECORDS[nextIndex][1] = std::to_string(score);
        RECORDS_COUNT++;
    }

    std::ofstream recordsFile;
    recordsFile.open(constants::RECORDS_FILE);

    for (int i = 0; i < RECORDS_COUNT; i++) {
        recordsFile << RECORDS[i][0] << "|" << RECORDS[i][1] << std::endl;
    }
    recordsFile.close();
}

int findIndexOfName(const std::string & userName) {
    if (RECORDS[0] == nullptr) {
        initRecordsArray();
    }
    for (int index = 0; index < RECORDS_COUNT; index++) {
        if (RECORDS[index][0] == userName) {
            return index;
        }
    }
    return -1;
}

void printCurrentScores() {

    //TODO: А так вообще правильно делать???
    if (RECORDS[0] == nullptr) {
        initRecordsArray();
    }
    if (RECORDS[0] == nullptr) {
        std::cout << "К сожалению, Текущая таблица рекордов пуста." << std::endl;
    } else {
        printRecords();
    }
}

void printRecords() {

    int w = 15;
    std::cout << std::endl;
    std::cout << std::setw(w) << "NAME" << std::setw(w) <<"|" << std::setw(w) << "SCORE" << std::endl;

    for (int i = 0; i < RECORDS_COUNT; i++) {
        //TODO: Тут косяк с русскими именами (setW отрабатывает иначе)
        std::cout << std::setw(w) << RECORDS[i][0] << std::setw(w) <<"|" << std::setw(w)<< RECORDS[i][1] << std::endl;
    }
}
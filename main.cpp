#include <iostream>
#include <ctime>
#include "constants.h"
#include "argument.h"
#include "game.h"
#include "file_storage.h"
/*
 * По программе курса мы ещё не знаем о структурах и классах, enum и пр.
 * поэтому старался исключить их использование.
 */


int parameters::ARGUMENT_COUNT = 0;
/**
 * Не получилось вынести этот метод в header т.к. не знаю какое возвращаемое значение прописать, пока поставил auto.
 *
 * Принип такой: разбиваем входящий массив аргументов запуска на двумерный массив
 * т.е. пример
 *
 * Запуск:
 * someApp -max 10 -lvl 3 -debug true
 *
 * приходит вот так: ["-max", "10", "-lvl", "3", "-debug", "true"]
 *
 * преобразуме в 2д массив:
 * (  "max",   "10"   )
 * (  "lvl",   "3"    )
 * (  "debug", "true" )
 *
 * На мой взгляд это предоставляет некоторую гибкость.
 */
auto readArguments(int count, char *argv[]) {
    const int row = 2;

    //Заранее не знаем сколько параметров пришло, поэтому устанвливаем значение максимально возможное
    const int col = count;

    auto array = new std::string[col][row]();

    for (int i = 1, argIndex = 0; i < count; i++) {
        std::string v{argv[i]};
        bool isParameterName = v.find('-') != std::string::npos;
        if (isParameterName) {
            parameters::ARGUMENT_COUNT++;
            std::string argumentName{v.substr(1, v.size())};
            array[argIndex][0] = argumentName;
            argIndex += 1;
        } else {
            if (array[argIndex - 1][1].empty()) {
                array[argIndex - 1][1] = v;
            } else {
                array[argIndex - 1][1] += v;
            }
        }
    }
    return array;
}

void showHelp() {
    std::cout << "Игра «угадай число» с таблицей рекордов" << std::endl;
    std::cout << "Параметры запуска:" << std::endl;
    std::cout << "\t-help               - эта справка" << std::endl;
    std::cout << "\t-table              - таблица рекордов " << std::endl;
    std::cout << "\t-level [integer]    - уровень сложности (число от  1 до 3) " << std::endl;
    std::cout << "\t\t - 1 уровень: число до 10" << std::endl;
    std::cout << "\t\t - 2 уровень: число до 50" << std::endl;
    std::cout << "\t\t - 3 уровень: число до 100" << std::endl;
    std::cout << "\t-max   [integer]    - верхняя граница \"загаданного числа\"  " << std::endl;
    std::cout << "\t-debug              - режим дебага (показывает загаданное число)" << std::endl;
}

std::string getMaxNumberByLvl(const std::string & lvl) {
    if (lvl.empty()) {
        return std::string();
    }

    int i_lvl = std::stoi(lvl);
    if (i_lvl == 1) return constants::EASY;
    else if (i_lvl == 2) return constants::MED;
    else return constants::HARD;
}

/**
 * return true if everything is ok.
 * @return
 */
bool checkLvl(const std::string & lvl) {
    if (lvl.empty()) {
       return true;
    }
    int i_lvl = std::stoi(lvl);
    if (i_lvl > 0 && i_lvl < 4) {
        return true;
    }
    std::cerr << "level cannot be less then 0 and greater then 3" << std::endl;
    return false;
}

/**
 * return true if everything is ok.
 * @param value
 * @return
 */
bool checkStoi(const std::string & value) {
    try {
        /*TODO: Если задать число с буквой в конце, то stoi это схавает...
         * Пример: stoi(44АБФА) = 44
         */
        std::stoi(value);
        return true;
    } catch (const std::invalid_argument &) {
        std::cerr << "Seems like this >>" << value << "<< is not a number" << std::endl;
    } catch (const std::out_of_range &) {
        std::cerr << "Omg! Keep calm! Maximum of this program is " << INT32_MAX << ", but you write " << value << std::endl;
    }
    return false;
}

int main(int argc, char *argv[]) {

    setlocale(LC_ALL,"Russian" );

    auto paramsArray = readArguments(argc, argv);

    auto helpFlag = containsParam(paramsArray, constants::HELP);
    if (helpFlag) {
        showHelp();
        return 0;
    }

    parameters::isDebug = containsParam(paramsArray, constants::DEBUG);

    if (parameters::isDebug) {
        std::cout << "[DEBUG] " << "DEBUG MODE: enabled" << std::endl;
    }

    bool showRecordsOnly = containsParam(paramsArray, constants::TABLE);
    if (showRecordsOnly) {
        printCurrentScores();
        return 0;
    }

    std::srand(std::time(nullptr));

    parameters::retries = 0;

    auto max = getParamValue(paramsArray, constants::MAX);

    auto lvl = getParamValue(paramsArray, constants::LEVEL);

    if (!max.empty() && !lvl.empty()) {
        std::cerr << R"(Flags "max" and "level" cannot be set at the same time)" << std::endl;
        return 1;
    }

    if (!max.empty())
        if (!checkStoi(max))
            return 0;

    if (!lvl.empty())
        if(!checkStoi(lvl) || !checkLvl(lvl))
            return 0;

    std::string maxNumberByLvl = getMaxNumberByLvl(lvl);

    if (parameters::isDebug) {
        if (!max.empty())
            std::cout << "[DEBUG] " << "MAX VALUE: " << max << std::endl;
        if (!lvl.empty())
            std::cout << "[DEBUG] " << "LEVEL VALUE: " << lvl << std::endl;
    }

    parameters::userName = getUserName("Введите ваше имя (Лучше писать латинскими, кириллица в таблице рекордов \"едет\")");
    gameCycle(max, maxNumberByLvl);

    return 0;
}


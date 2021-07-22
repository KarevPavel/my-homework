//
// Created by yacopsae on 21/07/2021.
//

#include "user_input.h"

int getUserNumber(int maxNumber) {
    /*
     * Будем мучить пользователя до тех пор, пока не введёт нормальное число
    */
    while (true) {

        int number;
        std::cin >> number;

        if (std::cin.fail() || number < 0 || number > maxNumber) {
            std::cout << "Ошибочка! Введите валидное число от 0 до " << maxNumber << std::endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        } else {
            return number;
        }
    }
}

char getUserChar(const std::string& message) {
    /*
     * Будем мучить пользователя до тех пор, пока не введёт нормальный ответ [y/n]
    */
    while (true) {
        std::cout << message << std::endl;
        std::string answer;
        std::cin >> answer;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }

        char _char = answer.length() == 1 ? answer[0] : '`';
        if (_char == 'Y' || _char == 'y' || _char == 'n' || _char == 'N') {
            return _char;
        }
    }
}

std::string getUserName(const std::string & message) {
    /*
     * Будем мучить пользователя до тех пор, пока не введёт имя
    */
    while (true) {
        std::cout << message << std::endl;
        std::string answer;
        std::cin >> answer;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }

        if (!answer.empty() && answer.find(constants::RECORDS_DELIM) == std::string::npos) {
            return answer;
        }
    }
}
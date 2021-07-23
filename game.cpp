#include "game.h"
#include "constants.h"
#include "argument.h"
#include "file_storage.h"

int generateNumber(int maxNumber) {
    int answer = (std::rand() % maxNumber);
    while (answer == 0) {
        answer = generateNumber(maxNumber);
    }
    return answer;
}

std::string coalesce(std::initializer_list<std::string> list) {
    for (std::string str : list) {
        if (!str.empty()) {
            return str;
        }
    }
    return std::string();
}

template<typename ...string>
std::string coalesce(string& ...strings) {
    return coalesce({strings...});
}

void gameCycle(const std::string & max, const std::string & maxNumberBylvl) {

    bool want2Exit = false;

    while(!want2Exit) {

        int maxNumber = std::stoi((coalesce(max, maxNumberBylvl, "100")));
        int number = generateNumber(maxNumber);
        parameters::retries = 1;

        std::cout << "Загадано число от 1 до " << maxNumber << std::endl;
        std::cout << "Попробуйте его угадать!" << std::endl;
        if (parameters::isDebug) {
            std::cout << "[DEBUG] " << "Пссс...загаданное число: " << number << std::endl;
        }

        bool fail;
        int userNumber;
        while ((fail = (userNumber = getUserNumber(maxNumber)) != number) && parameters::retries < constants::MAX_RETRIES) {
            if (userNumber > number) {
                std::cout << "Ваше число больше!" << std::endl;
            }
            if (userNumber < number) {
                std::cout << "Ваше число меньше!" << std::endl;
            }

            //std::cout << "Неудача, попробуйте ещё раз!" << std::endl;
            parameters::retries += 1;
        }
        if (parameters::retries >= constants::MAX_RETRIES) {
            std::cout << "Превышено максимальное кол-во попыток " << constants::MAX_RETRIES << std::endl;
            std::cout << "КОНЕЦ ИГРЫ!" << std::endl << std::endl << std::endl;
        }

        if (!fail) {
            std::cout << parameters::userName << " вы великолепны! У вас получилось с " << parameters::retries << " попытки!" << std::endl;
            int prevRecord = getSavedRecord(parameters::userName);
            if (prevRecord == 0 || parameters::retries < prevRecord) {
                std::cout << "Кстати, это ваш новый рекорд!" << std::endl;
                writeRecord2File(parameters::userName, parameters::retries);
            }
        }

        want2Exit = !charToBool(getUserChar("Начать заново? [y/n]"));
    }
    std::cout << "Удачного дня!" << std::endl;
}


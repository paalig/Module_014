#include <iostream>
/*
 * Вы продолжаете писать калькулятор, работающий с вещественными числами с очень высокой точностью.
 * Вы уже научились проверять корректность записи вещественных чисел в виде строк,
 * и теперь перед вами новая цель - научиться сравнивать такие вещественные числа.
 * Пользователь вводит две строки, задающие вещественные числа, в том же формате,
 * как было описано в задаче “Длинное вещественное число”.
 * Программа должна проверить корректность ввода
 * (для этого можно переиспользовать код, написанный в задаче “Длинное вещественное число”),
 * после чего вывести слово Less, если первое число строго меньше второго;
 * слово More, если первое число строго больше второго; и слово Equal, если введенные числа равны.
 */

bool CheckString(std::string str) {
    bool point = false;
    bool number = false;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '.' && str[i] != '-' && (str[i] < '0' || str[i] > '9')) {
            return false;
        }
        if (str[i] == '.') {
            if (!point) {
                point = true;
            } else {
                return false;
            }
        }
        if (str[i] == '-' && i != 0) {
            return false;
        }
        if (str[i] >= '0' && str[i] <= '9' && !number) {
            number = true;
        }
    }
    return number;
}

void CountInteger (int a[2], std::string str) {
    std::string tempString;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '.') {
            if (tempString.empty() || (tempString.size() == 1 && tempString[0] == '-')) {
                a[0] = 0;
                break;
            } else {
                a[0] = std::stoi(tempString);
                break;
            }
        } else {
            tempString += str[i];
            if (str.size() - 1 == i) {
                a[0] = std::stoi(tempString);
                break;
            }
        }
    }
}

std::string CutDecimal(std::string str) {
    bool point = false;
    std::string newStr;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '-') {
            newStr += str[i];
        }
        if (str[i] == '.') {
            point = true;
        } else if (point) {
            newStr += str[i];
        } else {}
    }
    return newStr;
}

int ReturnIndex(std::string str, int a) {
    if ((str.size() - 1) < a) {
        return 0;
    } else {
        return a;
    }
}

std::string CheckEmptyDecimal (std::string str) {
    if (str.empty()) {
        return "0";
    } else {
        return str;
    }
}

void CountDecimal(std::string str1, std::string str2) {
    str1 = CheckEmptyDecimal(str1);
    str2 = CheckEmptyDecimal(str2);
    std::string newStr1, newStr2;
    for (int i = 0; i < std::max(str1.size(), str2.size()); i++) {
        newStr1 += str1[ReturnIndex(str1, i)];
        newStr2 += str2[ReturnIndex(str2, i)];
    }
    int a = std::stoi(newStr1);
    int b = std::stoi(newStr2);
    if (a > b) {
        std::cout << "More" << std::endl;
    } else if (a < b) {
        std::cout << "Less" << std::endl;
    } else {
        std::cout << "Equal" << std::endl;
    }
}

int main() {
    std::string str1, str2;
    std::cout << "Input first number:" << std::endl;
    std::cin >> str1;
    std::cout << "Input second number:" << std::endl;
    std::cin >> str2;
    if (CheckString(str1) && CheckString(str2)) {
        int first[2] = {0, 0};
        int second[2] = {0, 0};
        CountInteger(first, str1);
        CountInteger(second, str2);
        if (first[0] > second[0]) {
            std::cout << "More" << std::endl;
        } else if (first[0] < second[0]) {
            std::cout << "Less" << std::endl;
        } else {
            str1 = CutDecimal(str1);
            str2 = CutDecimal(str2);
            CountDecimal(str1, str2);
        }
    } else {
        std::cout << "Incorrect input" << std::endl;
    }
    return 0;
}

#include <iostream>
/*
 * На этот раз вам нужно проверить, задает ли введенная пользователем строка корректный IP-адрес.
 * IP-адрес должен представлять из себя 4 числа, разделенных точками без пробелов,
 * причем каждое число должно быть в диапазоне от 0 до 255 включительно.
 * Числа не должны содержать ведущих нулей. Других символов в строке, кроме вышеописанных, присутствовать не должно.
 * Пользователь вводит строку, задающую IP-адрес.
 * Программа должна вывести слово Yes, если адрес корректен, а в противном случае - слово No.
 * Примеры корректных IP-адресов:
 */

bool CheckSymbol(std::string str) {
    //Содержить только символы 0-9, "."
    for (int i = 0; i < str.size(); i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '.') {
            return false;
        }
    }
    //Количество точек в строке - 3
    int countPoint = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '.') {
            countPoint++;
        }
    }
    if (countPoint != 3) {
        return false;
    }
    //Строка не начинается и не заканчивается на "."
    if (str[0] == '.' || str[str.size() - 1] == '.') {
        return false;
    }
    //Исключены 2 точки подряд
    for (int i = 0; i < str.size() - 1; i++) {
        if (str[i] == str[i + 1] && str[i] == '.') {
            return false;
        }
    }

    return true;
}

bool CheckInteger(std::string str) {
    std::string bufferString;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != '.') {
            bufferString += str[i];
            int a = std::stoi(bufferString);
            //Число не больше 255, нет ведущего нуля
            if (a > 255 || (bufferString.size() > 1 && bufferString[0] == '0')) {
                return false;
            }
        } else {
            bufferString = "";
        }
    }
    return true;
}

int main() {
    std::string str;
    std::cout << "Input IP:" << std::endl;
    std::cin >> str;

    if (CheckSymbol(str) && CheckInteger(str)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    return 0;
}

#include <iostream>
/*
 * Напишите программу, которая проверяет корректность email-адреса, введенного пользователем.
 * Согласно международным требованиям, корректный email-адрес должен состоять из двух частей, разделенных знаком @.
 * Первая часть должна иметь длину не менее 1 и не более 64 символов, вторая часть - не менее 1 и не более 63 символов.
 * Из символов допускаются только английские буквы, цифры и знак - (дефис), а также точка.
 * Точка не может быть первым или последним символом, а кроме того, две точки не могут идти подряд.
 * В первой части (которая предшествует символу @), кроме вышеперечисленных, разрешены еще следующие символы:
 * !#$%&'*+-/=?^_`{|}~
 * Пользователь вводит строку, задающую email-адрес.
 * Программа должна вывести слово Yes, если адрес корректен, а в противном случае - слово No.
 */
bool CheckSize (std::string str) {
    int a = 0;
    if (str.empty() || str.size() > 128) {
        return false;
    }
    //@ не первый и не последний символ
    if (str[0] == '@' || str[str.size() - 1] == '@') {
        return false;
    }
    //точка не первый и не последний символ
    if (str[0] == '.' || str[str.size() - 1] == '.') {
        return false;
    }

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '@') {
            a = 1;
        } else {
            a++;
        }
        if (a > 64) {
            return false;
        }
    }
    return true;
}

bool CheckSymbol(std::string str) {

    //2 точки не идут подряд
    for (int i = 0; i < (str.size() - 1); i++) {
        if (str[i] == str[i + 1] && str[i] == '.') {
            return false;
        }
    }

    int countA = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '@') {
            countA++;
        }
        //не больше одной @
        if (countA > 1) {
            return false;
        }

        // A-Z, a-z, 0-9, ".", "-", @
        if ((!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z') &&
            !(str[i] >= '0' && str[i] <= '9') && str[i] != '-' && str[i] != '.') && str[i] != '@') {
            //доп.символы в первой части
            if (countA == 0) {
                std::string firstPartSymbol = "!#$%&'*+-/=?^_`{|}~";
                bool firstPart = false;
                for (int j = 0; j < firstPartSymbol.size(); j++) {
                    if (str[i] == firstPartSymbol[j]) {
                        firstPart = true;
                        break;
                    }
                }
                if (!firstPart) {
                    return false;
                }
            } else {
                return false;
            }
        }
    }

    //есть хоть одна @ в адресе
    if (countA < 1) {
        return false;
    }
    return true;
}

int main() {
    std::string str;
    std::cout << "Input email:" << std::endl;
    std::cin >> str;

    if (CheckSize(str) && CheckSymbol(str)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    return 0;
}

#include <iostream>
/*
 * В древности для зашифрования сообщений использовался такой способ.
 * Все буквы в сообщении сдвигались на одно и то же число позиций в алфавите.
 * Число позиций могло быть как положительным, так и отрицательным, и являлось параметром шифра.
 * Если для сдвига на данное число позиций алфавита не хватает, то он зацикливается
 * (то есть буква с номером 27 - это снова a, буква с номером 28 - это b, и так далее).
 * Например, слово abracadabra при сдвиге на 10 позиций превратится в klbkmknklbk.
 * Этот простейший шифр называется шифром Цезаря. Регистр букв (заглавные и строчные) менять не нужно.
 * Напишите функцию encryptCaesar от строки и числа, которая возвращает исходную строку,
 * зашифрованную шифром Цезаря с параметром, равным данному числу.
 * Также напишите функцию decryptCaesar, выполняющую обратное преобразование.
 * Считаем, что входные строки состоят лишь из английских букв; если там содержатся и другие символы, то их надо игнорировать.
 * Подсказка: имея функцию encryptCaesar, функцию decryptCaesar можно реализовать в одну строчку.
 */

bool Check (std::string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] < 'A' || str[i] > 'z' || (str[i] > 'Z' && str[i] < 'a')) {
            return false;
        }
    }
    return true;
}

std::string EncryptCaesar(std::string str, int a) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            if (str[i] + a > 'z') {
                str[i] += a - 26;
            } else if (str[i] + a < 'a') {
                str[i] += a + 26;
            } else {
                str[i] += a;
            }
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            if (str[i] + a > 'Z') {
                str[i] += a - 26;
            } else if (str[i] + a < 'A') {
                str[i] += a + 26;
            } else {
                str[i] += a;
            }
        }
    }
    return str;
}

std::string DecryptCaesar(std::string str, int a) {
    return EncryptCaesar(str, -a);
}

void PrintStr(std::string str) {
    for (int i = 0; i < str.size(); i++) {
        std::cout << str[i];
    }
}

int main() {
    std::string str;
    int a;

    std::cout << "Input string to encrypt:" << std::endl;
    std::cin >> str;
    std::cout << "Input number for encryption:" << std::endl;
    std::cin >> a;

    if(Check(str)) {
        std::cout << "Encrypt: ";
        PrintStr(EncryptCaesar(str, a));
        std::cout << std::endl;
        std::cout << "Decrypt: ";
        PrintStr(DecryptCaesar(str, a));
    } else {
        std::cout << "Wrong input";
    }
}

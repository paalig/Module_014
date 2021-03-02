#include <iostream>
/*
 * Петя и Вася играли в крестики-нолики и не стерли после себя результаты своей игры.
 * Теперь перед вами табличка 3х3, которая осталась после их поединка.
 * Вы хотите понять, выиграл ли кто-то из них, или они не доиграли.
 * На вход программе дается три строки, кодирующие верхнюю, среднюю и нижнюю строчки игрового поля.
 * Крестик обозначается символом X (английская заглавная буква X), нолик - символом O (заглавная английская буква O),
 * пустая клетка - точкой.
 * Если ввод некорректен (то есть такая таблица не могла получиться в ходе настоящей игры),
 * то надо написать в ответ слово Incorrect.
 * Если таблица корректна и выиграли крестики, то нужно вывести в ответ слова Petya won, если нолики - то Vanya won,
 * а иначе (то есть они не доиграли или сыграли вничью) надо написать Nobody.
 */
//проверяем допустимые значения и предварительно - дельту между X и O
bool CheckMatrix(char matrix[3][3]) {
    int x = 0;
    int o = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] != 'X' && matrix[i][j] != 'O' && matrix[i][j] != '.') {
                return false;
            } else {
                if (matrix[i][j] == 'X') {
                    x++;
                } else if (matrix[i][j] == 'O') {
                    o++;
                }
            }
        }
    }
    if (x - o > 1 || x - o < 0) {
        return false;
    }
    return true;
}

//проверяем, что нет одновременно 2 выигрышных строк
bool CheckRows(char matrix[3][3]) {
    int xRow = 0;
    int oRow = 0;
    int xCol = 0;
    int oCol = 0;
    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] == 'X' && matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2]) {
            xRow++;
        }
        if (matrix[i][0] == 'O' && matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2]) {
            oRow++;
        }
        if (matrix[0][i] == 'X' && matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i]) {
            xCol++;
        }
        if (matrix[0][i] == 'O' && matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i]) {
            oCol++;
        }
    }
    return !((xRow + oRow) > 1 || (xCol + oCol) > 1);
}

char matrix[3][3];
void WriteMatrix (std::string str, int a) {
    for (int i = 0; i < str.size(); i++) {
        matrix[a][i] = str[i];
    }
}

int CheckDelta() {
    int x = 0;
    int o = 0;
    for (int a = 0; a < 3; a++) {
        for (int b = 0; b < 3; b++) {
            if (matrix[a][b] == 'X') {
                x++;
            } else if (matrix[a][b] == 'O') {
                o++;
            }
        }
    }
    return x - o;
}

void CheckWinner() {
    bool winner = false;
    for (int i = 0; i < 3 && !winner; i++) {
        int xRow = 0, xCol = 0;
        int oRow = 0, oCol = 0;
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == 'X') {
                xRow++;
            }
            if (matrix[i][j] == 'O') {
                oRow++;
            }
            if (matrix[j][i] == 'X') {
                xCol++;
            }
            if (matrix[j][i] == 'O') {
                oCol++;
            }
        }
        if (xRow == 3 || xCol == 3) {
            if (CheckDelta() == 1) {
                std::cout << "Petya won" << std::endl;
            } else {
                std::cout << "Incorrect" << std::endl;
            }
            winner = true;
        } else if (oRow == 3 || oCol == 3) {
            if (CheckDelta() == 0) {
                std::cout << "Vanya won" << std::endl;
            } else {
                std::cout << "Incorrect" << std::endl;
            }
            winner = true;
        }
    }
    if (!winner) {
        if (matrix[1][1] == 'X') {
            if ((matrix[0][0] == 'X' && matrix[2][2] == 'X') || (matrix[2][0] == 'X' && matrix[0][2] == 'X')) {
                if (CheckDelta() == 1) {
                    std::cout << "Petya won" << std::endl;
                } else {
                    std::cout << "Incorrect" << std::endl;
                }
            } else {
                std::cout << "Nobody" << std::endl;
            }
        } else if (matrix[1][1] == 'O') {
            if ((matrix[0][0] == 'O' && matrix[2][2] == 'O') || (matrix[2][0] == 'O' && matrix[0][2] == 'O')) {
                if (CheckDelta() == 0) {
                    std::cout << "Vanya won" << std::endl;
                } else {
                    std::cout << "Incorrect" << std::endl;
                }
            } else {
                std::cout << "Nobody" << std::endl;
            }
        } else {
            std::cout << "Nobody" << std::endl;
        }
    }
}

int main() {
    std::string str;

    for (int i = 0; i < 3; i++) {
        std::cout << "Input " << i + 1 << " string:" << std::endl;
        std::cin >> str;
        while (str.size() != 3) {
            std::cout << "Incorrect string" << std::endl;
            std::cout << "Input " << i + 1 << " string:" << std::endl;
            std::cin >> str;
        }
        WriteMatrix(str, i);
    }

    if (CheckMatrix(matrix) && CheckRows(matrix)) {
        CheckWinner();
    } else {
        std::cout << "Incorrect" << std::endl;
    }
}

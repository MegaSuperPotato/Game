#include <iostream>

void inputCorrectness(int[], char[3][3], int);
bool isWin(char[3][3], int);

int main()
{
    std::cout << "Hello World!\n";
}

void inputCorrectness(int coordinates[], char map[3][3], int turn) {
    bool flag = true;
    while (flag) {
        std::cout << "Input correct coordinates: ";
        std::cin >> coordinates[0] >> coordinates[1];
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if ((coordinates[0] < 3) && (coordinates[1] < 3)) {
            if ((coordinates[0] >= 0) && coordinates[1] >= 0) {
                if (map[coordinates[0]][coordinates[1]] == '#') {
                    char character;
                    if (turn % 2 == 0) {
                        character = 'X';
                    }
                    else {
                        character = 'o';
                    }
                    map[coordinates[0]][coordinates[1]] = character;
                    flag = false;
                }
            }
        }
    }
}

bool isWin(char map[3][3], int turn) {
    int index = 0;
    char buf = 'X';

    /*if ((map[0][0] == map[1][1] == map[2][2]) || (map[0][2] == map[1][1] == map[2][0])) {
        return true;
    }*/

    if ((map[0][0] == map[1][1] && map[1][1] == map[2][2] && map[0][0] != '#') || (map[0][2] == map[1][1] && map[1][1] == map[2][0] && map[0][2] != '#')) {
        //return true;
        goto end_game;
    }

    for (int i = 0; i < 3; ++i) {
        if (map[i][0] != '#') {
            buf = map[0][0];
        }
        for (int k = 0; k < 3; ++k) {
            if (map[i][k] == buf) {
                ++index;
            }
            else if (map[i][k] != '#') {
                buf = map[i][k];
            }
            else if (map[k][i] == buf) {
                ++index;
            }
        }
        if (index == 3) {
            goto end_game;
            //return true;
        }
        index = 0;
    }

    if (false) {
    end_game:
        std::cout << "\nCongratulations!!!!! \nPlayer " << (turn % 2) + 1 << " win!\n";
        return true;
    }


    return false;
}
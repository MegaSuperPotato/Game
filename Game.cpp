#include <iostream>

void inputCorrectness(int[], char[3][3], int);

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
#include "structs.h"

void GameField::initPlayground() {
    matrix.assign(playgroundSize, std::vector<int>(playgroundSize));

    int value = playgroundSize * playgroundSize - 1;

    for (int i = 0; i < playgroundSize; ++i) {
        for (int j = 0; j < playgroundSize; ++j) {
            matrix[i][j] = value;

            if (value == 0) {
                row = i;
                col = j;
            }
            value--;
        }
    }

    if (playgroundSize % 2 == 0) {
        int r1, c1, r2, c2;

        for (int i = 0; i < playgroundSize; ++i) {
            for (int j = 0; j < playgroundSize; ++j) {
                if (matrix[i][j] == 1) {
                    r1 = i; c1 = j;
                }
                if (matrix[i][j] == 2) {
                    r2 = i; c2 = j;
                }
            }
        }
        std::swap(matrix[r1][c1], matrix[r2][c2]);
    }
}

//void gamefield::drowplayground() {
//    for (int i = 0; i < playgroundsize; ++i) {
//        for (int j = 0; j < playgroundsize; ++j) {
//            std::cout << matrix[i][j] << "\t";
//        }
//        std::cout << std::endl;
//    }
//}

std::ostream& operator<<(std::ostream& out, const GameField& field) {
    for (int i = 0; i < field.playgroundSize; ++i) {
        for (int j = 0; j < field.playgroundSize; ++j) {
            if (field.matrix[i][j] == 0) {
                out << "  \t";
            }
            else {
                out << field.matrix[i][j] << "\t";
            }
        }
        out << "\n";
    }
    return out;
}

int GameField::stepCheck(int dice) {
    int dRow[] = { -1, 1, 0, 0 };
    int dCol[] = { 0, 0, -1, 1 };

    for (int i = 0; i < 4; ++i) {
        int ni = row + dRow[i];
        int nj = col + dCol[i];

        if (ni >= 0 && ni < playgroundSize && nj >= 0 && nj < playgroundSize) {
            if (matrix[ni][nj] == dice) {
                return 1;
            }
        }
    }
    std::cout << "Incorrect step" << std::endl;
    return 0;
}

//void GameField::step(int dice) {
//    if (stepCheck(dice) == 0) return;
//
//    int targetRow = -1;
//    int targetCol = -1;
//
//    int dRow[] = { -1, 1, 0, 0 };
//    int dCol[] = { 0, 0, -1, 1 };
//
//    for (int i = 0; i < 4; ++i) {
//        int ni = row + dRow[i];
//        int nj = col + dCol[i];
//
//        if (ni >= 0 && ni < playgroundSize && nj >= 0 && nj < playgroundSize) {
//            if (matrix[ni][nj] == dice) {
//                targetRow = ni;
//                targetCol = nj;
//                break;
//            }
//        }
//    }
//
//    std::swap(matrix[row][col], matrix[targetRow][targetCol]);
//
//    row = targetRow;
//    col = targetCol;
//
//    countOFstep++;
//    gameStatusCheck();
//}

GameField& operator+=(GameField& field, int dice) 
{
    if (field.stepCheck(dice) == 0) return field;

    int targetRow = -1;
    int targetCol = -1;

    int dRow[] = { -1, 1, 0, 0 };
    int dCol[] = { 0, 0, -1, 1 };

    for (int i = 0; i < 4; ++i) {
        int ni = field.row + dRow[i];
        int nj = field.col + dCol[i];

        if (ni >= 0 && ni < field.playgroundSize && nj >= 0 && nj < field.playgroundSize) {
            if (field.matrix[ni][nj] == dice) {
                targetRow = ni;
                targetCol = nj;
                break;
            }
        }
    }

    std::swap(field.matrix[field.row][field.col], field.matrix[targetRow][targetCol]);

    field.row = targetRow;
    field.col = targetCol;

    field.countOFstep++;
    field.gameStatusCheck();

    return field;
};

void GameField::gameStatusCheck() {
    int expectedValue = 1;
    int n = playgroundSize;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == n - 1 && j == n - 1) {
                if (matrix[i][j] == 0) {
                    std::cout << "Succses! You solve the task in " << countOFstep << " step!" << std::endl;
                }
                return;
            }

            if (matrix[i][j] != expectedValue) {
                return;
            }
            expectedValue++;
        }
    }
}
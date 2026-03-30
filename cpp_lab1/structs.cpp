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
    return 0;
}

GameField& operator+=(GameField& field, int dice) 
{
    if (field.stepCheck(dice) == 0) 
    {
        field.errorFlag = dice;
        return field; 
    }

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
                    gameMod = 2;
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

/////////////////////////////////////////////////

int GameController::getInt(int mod) {
    std::string input;
    int value;
    while (true) {
        try {
            if (mod == 0)
            {
                std::cout << "Enter gamefield size: ";
            }
            else
            {
                std::cout << "Enter num of dice: ";
            }
            std::cin >> input;
            size_t pos;
            value = std::stoi(input, &pos);
            if (pos != input.length()) {
                if (mod == 0) {
                    std::cout << "\nIncorrect Argument!";
                    continue;
                }
                else
                {
                    return -1;
                }
            }
            if (mod == 0)
            {
                if (value < 2)
                {
                    std::cout << "\nSize should be 2 or bigger! ";
                    continue;
                }
            }
            else
            {
                if (value < 1) {
                    return -1;
                }
            }

            while (std::isspace(std::cin.peek()) &&
                std::cin.peek() != '\n') {
                std::cin.ignore();
            }
            if (std::cin.peek() != '\n') {
                std::cout << "Entered extra arguments! Will be used only first one(" << value << ")." << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
            }
            return value;

        }
        catch (...) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (mod == 0) {
                std::cout << "Incorrect Argument!";
            }
            else
            {
                return -1;
            }
        }
    }
}

////////////////////////////////////////////////////

void GameController::savePlaygraund(GameField* game)
{

    std::ofstream logFile("game_log.txt", std::ios::app);

    logFile << "#### #### ####\n";

    logFile << "Step: " << game->countOFstep << std::endl;

    for (int i = 0; i < game->playgroundSize; ++i) {
        for (int j = 0; j < game->playgroundSize; ++j) {
            if (game->matrix[i][j] == 0) {
                logFile << "  \t";
            }
            else {
                logFile << game->matrix[i][j] << "\t";
            }
        }
        logFile << "\n";
    }

    logFile.close();
}

void GameController::saveTime(GameField* game)
{
    time_t date = time(nullptr);
    tm ltm;

    std::ofstream logFile("game_log.txt", std::ios::app);
    
    if (game->gameMod == 0)
    {
        if (localtime_s(&ltm, &date) == 0) {
            logFile << "Game started : " << std::put_time(&ltm, " %d.%m.%Y %H:%M:%S") << std::endl;
        }
    }
    else
    {
        if (localtime_s(&ltm, &date) == 0) {
            logFile << "End time : " << std::put_time(&ltm, " %d.%m.%Y %H:%M:%S") << std::endl << std::endl;
        }
    }
    
    logFile.close();
}

void GameController::init(GameField* game)
{
    std::ofstream logFile("game_log.txt", std::ios::app);
    saveTime(game);
    game->playgroundSize = getInt(game->gameMod);
    logFile << "Playground size: " << game->playgroundSize << std::endl;
    logFile.close();
    game->gameMod = 1;
    game->initPlayground();

    mainCycle(game);
    
}

void GameController::mainCycle(GameField* game)
{
    int val;
    while (true)
    {
        std::system("cls");

        if (game->errorFlag != 0)
        {
            std::ofstream logFile("game_log.txt", std::ios::app);
            logFile << "Incorrect step! Dice num " << game->errorFlag << std::endl;
            logFile.close();

            std::cout << "Incorrect step! Dice num " << game->errorFlag << std::endl;
            game->errorFlag = 0;
        }
        else
        {
            savePlaygraund(game);
        }

        std::cout << *game;
        std::cout << "Count of step: " << game->countOFstep << std::endl;
        std::cout << "\nTo finish game enter any letter or negative int\n";
        val = getInt(game->gameMod);
        if (val == -1) 
        {
            std::string confimation;
            std::cout << "Do you really want finish the game? \nEnter Y to finish or N to continue: ";
            std::cin >> confimation;
            if (confimation == "Y" or confimation == "y")
            {
                std::ofstream logFile("game_log.txt", std::ios::app);
                logFile << "Game stopped on step " << game->countOFstep << std::endl;
                logFile.close();
                saveTime(game);

                game->gameMod = -1;
                std::cout << "Game Over!";
                return;
            }

        }
        else 
        {
            *game += val;
        }
        game->gameStatusCheck();
        if (game->gameMod == 2)
        {
            savePlaygraund(game);

            std::ofstream logFile("game_log.txt", std::ios::app);
            logFile << "Game succsesfully finished in " << game->countOFstep << " step!" << std::endl;
            logFile.close();
            saveTime(game);         

            std::system("cls");
            std::cout << *game;
            std::cout << "Succses! You solve the task in " << game->countOFstep << " step!" << std::endl;
            break;
        }

    }
}

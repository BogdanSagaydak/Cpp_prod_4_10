#include "input.h"

//void savePlaygraund(GameField* game)
//{
//    // ѕерев≥рка на вал≥дн≥сть покажчика
//    if (game == nullptr) return;
//
//    std::ofstream logFile("game_log.txt", std::ios::app);
//
//    // ѕерев≥рка, чи файл взагал≥ в≥дкривс€
//    if (!logFile.is_open()) return;
//
//    logFile << "#### #### ####\n";
//
//    for (int i = 0; i < game->playgroundSize; ++i) { // ¬икористовуЇмо ->
//        for (int j = 0; j < game->playgroundSize; ++j) { // ¬икористовуЇмо ->
//            if (game->matrix[i][j] == 0) {
//                logFile << "  \t"; // «м≥нено out на logFile
//            }
//            else {
//                logFile << game->matrix[i][j] << "\t"; // «м≥нено out на logFile
//            }
//        }
//        logFile << "\n";
//    }
//
//    logFile << "#### #### ####\n";
//
//    logFile.close();
//}



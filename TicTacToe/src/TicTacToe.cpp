#include "TicTacToe.hpp"
#include <iostream>

/**
 * Method: constructor
 * Arg 1: boardSize - Size of the board
 * Output: Forms the board and intilizes class variables
 */
TicTacToe::TicTacToe(int boardSize) {
    draw = false;
    numberOfTurn = 0;
    turn = '*';

    board.resize(boardSize);
    for (auto &row : board) {
        row.resize(boardSize);
    }

    // Initialize vector/ board
    char count = 'A';
    for (auto &row : board) {
        for (auto &col : row) {
            col = count++;
        }
    }
}

/**
 * Method: displayBoard
 * Output: Prints the current state of the board
 */
void TicTacToe::displayBoard() {
    // Game Board LAYOUT

    std::cout << "PLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";
    for (auto row : board) {
        std::cout << "\t\t|";
        for (auto ind = 0; ind < board.size(); ++ind) {
            std::cout << "     |";
        }
        std::cout << " \n";
        std::cout << "\t\t|";
        for (auto ind = 0; ind < board.size(); ++ind) {
            std::cout << "  " << row[ind] << "  |";
        }
        std::cout << " \n";
        std::cout << "\t\t|";
        for (auto ind = 0; ind < board.size(); ++ind) {
            std::cout << "_____|";
        }
        std::cout << " \n";
    }
    std::cout << " \n";
}

/**
 * Method: updateBoard
 * Output: Takes input from the player and writes to board
 */
void TicTacToe::updateBoard() {
    if (turn == '*') {
        std::cout << "\n\tPlayer - 1 [*] turn : ";
    } else if (turn == 'o') {
        std::cout << "\n\tPlayer - 2 [o] turn : ";
    }
    // Taking input from user
    // Updating the board according to choice and reassigning the turn Start

    char choice;
    std::cin >> choice;

    int number = choice - 'A';
    int row = number / board.size();
    int col = number % board.size();

    if (turn == '*' && board[row][col] != '*' && board[row][col] != 'o') {
        // Updating the position for '*' symbol if
        // it is not already occupied
        board[row][col] = '*';
        turn = 'o';
        numberOfTurn++;
    } else if (turn == 'o' && board[row][col] != '*' &&
               board[row][col] != 'o') {
        // Updating the position for 'o' symbol if
        // it is not already occupied
        board[row][col] = 'o';
        turn = '*';
        numberOfTurn++;
    } else {
        // If input position already filled
        std::cout << "\nBox already filled!\n Please choose another!!\n\n";
        updateBoard();
    }
    /* Ends */
    displayBoard();
}

/**
 * Method: winPossible
 * Arg1: turnToExamine- Player i.e. cross or nut
 * Arg2: turnsRemaining- Remaining turns for player
 * Output: Predict if player with turnToExamine can win in turnsRemaining
 */
bool TicTacToe::winPossible(char turnToExamine, int turnsRemaining) {
    // checking the win for Simple Rows and Simple Column
    for (int row = 0; row < board.size(); row++) {
        bool calculateRow = true;
        bool calculateCol = true;
        int remaining = turnsRemaining;
        for (int col = 0; col < board.size(); col++) {
            // Check for row
            if (board[row][col] != '*' && board[row][col] != 'o' &&
                remaining != 0) {
                calculateRow = calculateRow && true;
            } else {
                calculateRow =
                    calculateRow && (board[row][col] == turnToExamine);
            }

            // Check for column
            if (board[col][row] != '*' && board[col][row] != 'o' &&
                remaining != 0) {
                calculateCol = calculateCol && true;
            } else {
                calculateCol =
                    calculateCol && (board[row][col] == turnToExamine);
            }

            remaining--;
        }
        if (calculateRow || calculateCol) {
            return true;
        }
    }

    // checking the win for both diagonal
    bool calculateLeft = true;
    bool calculateRight = true;
    int remainingLeft = turnsRemaining;
    int remainingRight = turnsRemaining;
    int decSize = board.size() - 1;
    for (int size = 0; size < board.size(); size++) {
        // Left diagonal
        if (board[size][size] != '*' && board[size][size] != 'o' &&
            remainingLeft-- != 0) {
            calculateLeft = calculateLeft && true;
        } else {
            calculateLeft =
                calculateLeft && (board[size][size] == turnToExamine);
        }

        // Right diagonal
        if (board[size][decSize] != '*' && board[size][decSize] != 'o' &&
            remainingRight-- != 0) {
            calculateRight = calculateRight && true;
        } else {

            calculateRight =
                calculateRight && (board[size][decSize--] == turnToExamine);
        }
    }
    if (calculateLeft || calculateRight) {
        return true;
    }

    return false;
}

/**
 * Method: predictDraw
 * Output: Predict if both player won't be able to win the game
 */
bool TicTacToe::predictDraw() {
    int totalTurnsRemaining = (board.size() * board.size()) - numberOfTurn;

    // Predict the game only if turn are remaining
    if (totalTurnsRemaining > 0) {
        // If even number of turns remaining, both players will get
        // equal opportunity
        int numberCross = totalTurnsRemaining / 2;
        int numberNut = totalTurnsRemaining / 2;
        if (totalTurnsRemaining % 2 != 0) {
            if (turn == '*') {
                numberCross++;
            } else {
                numberNut++;
            }
        }
        return (!winPossible('*', numberCross) || !winPossible('o', numberNut));
    } else {
        return false;
    }
}

/**
 * Method: gameStatus
 * Output: Check for winning
 */
bool TicTacToe::gameStatus() {
    // checking the win for Simple Rows and Simple Column
    for (int row = 0; row < board.size(); row++) {
        bool calculateRow = true;
        bool calculateCol = true;
        for (int col = 0; col < board.size(); col++) {
            calculateRow = calculateRow && (board[row][col] == board[row][0]);
            calculateCol = calculateCol && (board[col][row] == board[0][row]);
        }
        if (calculateRow || calculateCol) {
            return true;
        }
    }

    // checking the win for both diagonal
    bool calculateLeft = true;
    bool calculateRight = true;
    int decSize = board.size() - 1;
    for (int size = 0; size < board.size(); size++) {
        calculateLeft = calculateLeft && (board[size][size] == board[0][0]);
        calculateRight = calculateRight &&
                         (board[size][decSize--] == board[0][board.size() - 1]);
    }
    if (calculateLeft || calculateRight) {
        std::cout << "checking the win for one diagonal" << std::endl;
        return true;
    }

    // Continue game if turn not over
    if (numberOfTurn != (board.size() * board.size())) {
        // std::cout << "turn " << numberOfTurn << " "
        //<< (board.size() * board.size()) << std::endl;
        return false;
    }

    // The game draws if reached here!
    draw = true;
    return true;
}

/**
 * Method: play
 * Output: Entry point to play the game
 */
void TicTacToe::play() {
    std::cout << "\t\t\tT I C K -- T A C -- T O E -- G A M E\t\t\t\n";

    displayBoard();

    do {
        if (predictDraw()) {
            std::cout << "The game can't proceed further. It will "
                         "draw eventually\n";
            return;
        }
        updateBoard();
    } while (!gameStatus());

    if (turn == '*' && draw == false) {
        std::cout << "\n\nCongratulations!Player with 'o' has won the game\n";
    } else if (turn == 'o' && draw == false) {
        std::cout << "\n\nCongratulations!Player with '*' has won the game\n";
    } else {
        std::cout << "\n\nGAME DRAW!!!\n";
    }
}

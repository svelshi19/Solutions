#include <vector>

class TicTacToe {
    std::vector<std::vector<char>> board;
    bool draw;
    char turn;
    int numberOfTurn;

    void displayBoard();
    void updateBoard();
    bool gameStatus();
    bool winPossible(char turnToExamine, int turnsRemaining);
    bool predictDraw();

  public:
    TicTacToe(int boardSize);

    void play();
};

#include <iostream>
#include <vector>

void displaytheBoard(const std::vector<char>& board) {
    std::cout << "\n";
    for (int i = 0; i < 9; i++) {
        std::cout << " " << board[i] << " ";
        if ((i + 1) % 3 == 0) {
            std::cout << "\n";
            if (i < 6) std::cout << "---|---|---\n";
        } else {
            std::cout << "|";
        }
    }
    std::cout << "\n";
}

bool checkWin(const std::vector<char>& board, char player) {
  
    return (board[0] == player && board[1] == player && board[2] == player) ||
           (board[3] == player && board[4] == player && board[5] == player) ||
           (board[6] == player && board[7] == player && board[8] == player) ||
           (board[0] == player && board[3] == player && board[6] == player) ||
           (board[1] == player && board[4] == player && board[7] == player) ||
           (board[2] == player && board[5] == player && board[8] == player) ||
           (board[0] == player && board[4] == player && board[8] == player) ||
           (board[2] == player && board[4] == player && board[6] == player);
}

bool checkDraw(const std::vector<char>& board) {
    for (char cell : board) {
        if (cell != 'X' && cell != 'O') {
            return false;
        }
    }
    return true;
}

void play() {
    std::vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char currentPlayer = 'X';
    bool gameRunning = true;

    while (gameRunning) {
        displaytheBoard(board);

        int move;
        std::cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        std::cin >> move;

        if (move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O') {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }

        board[move - 1] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displaytheBoard(board);
            std::cout << "Player " << currentPlayer << " wins!\n";
            gameRunning = false;
        } else if (checkDraw(board)) {
            displaytheBoard(board);
            std::cout << "It's a draw!\n";
            gameRunning = false;
        } else {
            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

int main() {
    char playAgain;
    do {
        play();
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thanks for playing!\n";
    return 0;
}

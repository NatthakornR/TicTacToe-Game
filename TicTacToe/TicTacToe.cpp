#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int BOARD_SIZE = 3;

void displayBoard(const vector<vector<char>>& board);
bool isWinningMove(const vector<vector<char>>& board, char symbol);
bool isBoardFull(const vector<vector<char>>& board);
void getPlayerMove(vector<vector<char>>& board, char symbol);

int main() {
    vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, ' '));
    char currentPlayer = 'X';
    bool gameRunning = true;

    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "Player 1: X\nPlayer 2: O\n\n";

    while (gameRunning) {
        displayBoard(board);

        getPlayerMove(board, currentPlayer);

        if (isWinningMove(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << (currentPlayer == 'X' ? 1 : 2) << " (" << currentPlayer << ") wins!\n";
            gameRunning = false;
            break;
        }

        if (isBoardFull(board)) {
            displayBoard(board);
            cout << "It's a draw!\n";
            gameRunning = false;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

void displayBoard(const vector<vector<char>>& board) {
    cout << "\n";
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << " " << board[i][j];
            if (j < BOARD_SIZE - 1) cout << " |";
        }
        cout << "\n";
        if (i < BOARD_SIZE - 1) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool isWinningMove(const vector<vector<char>>& board, char symbol) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
            return true;
        }
    }

    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return true;
    }

    return false;
}

bool isBoardFull(const vector<vector<char>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void getPlayerMove(vector<vector<char>>& board, char symbol) {
    int row, col;
    while (true) {
        cout << "Player " << (symbol == 'X' ? 1 : 2) << " (" << symbol << "), enter your move (row and column: 1-3 1-3): ";
        cin >> row >> col;

        row--;
        col--;

        if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ') {
            board[row][col] = symbol;
            break;
        }
        else {
            cout << "Invalid move. Try again.\n";
        }
    }
}

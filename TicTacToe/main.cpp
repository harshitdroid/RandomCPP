#include <iostream>
#include <cstring>
using namespace std;

const int BOARD_SIZE = 3;

char board[BOARD_SIZE][BOARD_SIZE];
bool player1Turn;

// Initialize the board with empty spaces
void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Print the current state of the board
void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if the current player has won
bool checkWin(char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

// Check if the board is full
bool checkFull() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Get player input
void getPlayerInput() {
    int row, col;
    cout << "Enter row (0-2): ";
    cin >> row;
    cout << "Enter col (0-2): ";
    cin >> col;
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ')
    {
        if (player1Turn) {
            board[row][col] = 'X';
        } else {
            board[row][col] = 'O';
        }
        player1Turn = !player1Turn;
    } else {
        cout << "Invalid move, try again." << endl;
    }
}

int main() {
    initBoard();
    player1Turn = true;
    while (true) {
        printBoard();
        getPlayerInput();
        if (checkWin('X')) {
            cout << "Player 1 wins!" << endl;
            break;
        } else if (checkWin('O')) {
            cout << "Player 2 wins!" << endl;
            break;
        } else if (checkFull()) {
            cout << "It's a tie!" << endl;
            break;
        }
    }
    return 0;
}

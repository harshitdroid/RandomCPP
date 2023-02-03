#include <iostream>
#include <cstring>
using namespace std;

const int BOARD_SIZE = 20;

char board[BOARD_SIZE][BOARD_SIZE];
int pacmanX, pacmanY; // position of Pac-Man on the board
int ghostX, ghostY; // position of ghost on the board

// Initialize the board with walls and pellets
void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 0 || i == BOARD_SIZE - 1 || j == 0 || j == BOARD_SIZE - 1) {
                board[i][j] = '#';
            } else {
                board[i][j] = '.';
            }
        }
    }
    pacmanX = 1;
    pacmanY = 1;
    board[pacmanX][pacmanY] = 'P';
    ghostX = BOARD_SIZE - 2;
    ghostY = BOARD_SIZE - 2;
    board[ghostX][ghostY] = 'G';
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

// Get player input (w,a,s,d)
void getPlayerInput() {
    char move;
    cout << "Enter move (w, a, s, d): ";
    cin >> move;
    switch (move) {
        case 'w':
            if (board[pacmanX - 1][pacmanY] != '#') {
                board[pacmanX][pacmanY] = '.';
                pacmanX--;
                board[pacmanX][pacmanY] = 'P';
            }
            break;
        case 'a':
            if (board[pacmanX][pacmanY - 1] != '#') {
                board[pacmanX][pacmanY] = '.';
                pacmanY--;
                board[pacmanX][pacmanY] = 'P';
            }
            break;
        case 's':
            if (board[pacmanX + 1][pacmanY] != '#') {
                board[pacmanX][pacmanY] = '.';
                pacmanX++;
                board[pacmanX][pacmanY] = 'P';
            }
            break;
        case 'd':
            if (board[pacmanX][pacmanY + 1] != '#') {
                board[pacmanX][pacmanY] = '.';
                pacmanY++;
                board[pacmanX][pacmanY] = 'P';
            }
            break;
    }
}

int main() {
    initBoard();
    while (true) {
        printBoard();
        getPlayerInput();
    }
    return 0;
}

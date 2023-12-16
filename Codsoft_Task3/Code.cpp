#include <iostream>
#include <cstdlib>

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

int choice;
int row, column;
char turn = 'X';
bool draw = false;

void displayBoard();
void takePlayerTurn();
bool isValidMove();
bool checkGameOver();

int main() {
    cout << "T I C K -- T A C -- T O E -- G A M E" << endl;
    cout << "FOR 2 PLAYERS" << endl;

    while (!checkGameOver()) {
        displayBoard();
        takePlayerTurn();
    }

    if (turn == 'X' && !draw) {
        cout << "\nCongratulations! Player with 'X' has won the game" << endl;
    } else if (turn == 'O' && !draw) {
        cout << "\nCongratulations! Player with 'O' has won the game" << endl;
    } else {
        cout << "\nGAME DRAW!!!" << endl;
    }

    return 0;
}

void displayBoard() {
    cout << "\nPLAYER - 1 [X] | PLAYER - 2 [O]\n\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---------\n";
    }
    cout << "\n";
}

void takePlayerTurn() {
    cout << "Player - " << turn << " turn: ";
    cin >> choice;

    if (isValidMove()) {
        board[row][column] = turn;
        turn = (turn == 'X') ? 'O' : 'X';
    } else {
        cout << "Invalid Move! Please choose another.\n\n";
        takePlayerTurn();
    }
}

bool isValidMove() {
    switch (choice) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "Invalid Move";
            return false;
    }

    if (board[row][column] != 'X' && board[row][column] != 'O') {
        return true;
    } else {
        return false;
    }
}

bool checkGameOver() {
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] ||
            board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return true;
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] ||
        board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return true;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    draw = true;
    return true;
}

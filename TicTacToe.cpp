#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

bool checkGameOver();
void printGrid();
void initializeGame();

char p1, p2;
int turn = 0;

//Initialize the Tic Tac Toe Grid
char grid[3][3] = { 
    { '-', '.', '-' },
    { '.', '=', '.' },
    { '-', '.', '-' }
};

void printGrid(){
    //Prints the Tic Tac Toe Grid
    cout << setw(2) << right << grid[0][0] << setw(2) << "|" << setw(2) << grid[0][1] << setw(2) << "|" << setw(2) << grid[0][2] << endl
        << "-----------" << endl
        << setw(2) << right << grid[1][0] << setw(2) << "|" << setw(2) << grid[1][1] << setw(2) << "|" << setw(2) << grid[1][2] << endl
        << "-----------" << endl
        << setw(2) << right << grid[2][0] << setw(2) << "|" << setw(2) << grid[2][1] << setw(2) << "|" << setw(2) << grid[2][2] << endl;
}

//Initialize the game and players
void initializeGame() {
    cout << "Would the first player like to be X or O? Type your awnser: \n";
    cin >> p1;
    if (p1 == 'X' || p1 == 'x') {
        p1 = 'X';
        p2 = 'O';
    }
    else {
        p1 = 'O';
        p2 = 'X';
    }
}

//Fuction to play the game
void playGame() {
    int pos1, pos2;
    bool gameOver = false;
    bool turnEnd;

    //While game is is on going
    while (gameOver == false) {
        turnEnd = false;

        //Prompt user for next action
        while (turnEnd == false) {
            cout << "Make move by inputting position (ex. 0 1 for the top middle and 2 1 for the bottom middle)\n";
            cin >> pos1 >> pos2;
            if (pos1 > 2 || pos2 > 2) {
                cout << "Invalid position. Try again\n";
            }
            else if (grid[pos1][pos2] == 'X' || grid[pos1][pos2] == 'O') {
                cout << "Position already filled. Try again\n";
            }
            else {
                //Fill in grid depending on whose turn it is
                if (turn == 0) {
                    grid[pos1][pos2] = p1;
                    turn++;
                }
                else {
                    grid[pos1][pos2] = p2;
                    turn--;
                }
                turnEnd = true;
            }
        }
        printGrid();
        gameOver = checkGameOver();
    }

    //If game is done, check who wins
    if (turn == 0) {
        cout << "Player 2 wins!\n\n\n";
    }
    else if (turn == 1){
        cout << "Player 1 wins!\n\n\n";
    }
    else if (turn == 2){
        cout << "Game is tied!\n\n\n";
    }
}

//Bool function to check if Tic Tac Toe matches
bool checkGameOver() {
    int check = 0;
    for (int i = 0; i < 3; i++) {
        //checks if any columns match
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
            return true;
        }
        //Checks if any rows match
        else if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
            return true;
        }
        //Checks if all columns and rows are filled
        if (grid[0][i] == 'X' || grid[0][i] == 'Y') {
            if (grid[1][i] == 'X' || grid[1][i] == 'Y') {
                if (grid[2][i] == 'X' || grid[2][i] == 'Y') {
                    check++;                
                }
            }
        }
        //If all columns and rows are filled, return true
        if (check == 3) {
            turn = 2;
            return true;
        }
        
    }
    // checks if diagnoals matches
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
        return true;
    }
    else if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    initializeGame();
    playGame();
}

#include <iostream>
#include <vector>

using namespace std;

void print(const vector<vector<char>>& board) {
    for(int i=0 ; i<board.size() ; i++){
            for(int j=0 ; j<board.size() ; j++){
               cout<<board[i][j]<< " ";
            }
            cout<<endl;
        }

    cout << endl;
}

// Function to check if it's safe to place a queen at (r, c)
bool isSafe(vector<vector<char>>& board, int r, int c, int n) {
    // Check the column above
    for (int i = r; i >= 0; i--) {
        if (board[i][c] == 'Q') {
            return false;
        }
    }

    // Check the row to the left
    for (int j = c; j >= 0; j--) {
        if (board[r][j] == 'Q') {
            return false;
        }
    }

    // Check upper left diagonal
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Check upper right diagonal
    for (int i = r, j = c; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

// Recursive function to solve the N-Queens problem
void solve(vector<vector<char>>& board, int n, int r) {
    if (r == n) {//jevha 4 hoel 
        print(board);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (isSafe(board, r, j, n)) {
            board[r][j] = 'Q';
            solve(board, n, r + 1);
            board[r][j] = '-'; // Backtrack
        }
    }
}

// Function to print the board


int main() {
    int n;
    cout << "Enter the size of the board: ";
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n, '-'));

    int pos;
    cout << "Enter the position for the first queen (< " << n << "): ";
    cin >> pos;

    if (pos >= n) {
        cout << "Invalid position for the first queen" << endl;
        return 0;
    }

    board[0][pos] = 'Q';
    solve(board, n, 1); // Start solving from the second row

    return 0;
}

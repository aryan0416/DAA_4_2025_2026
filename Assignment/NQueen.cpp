#include <bits/stdc++.h>
using namespace std;

int N, count_solutions = 0;
vector<int> board;
unordered_set<int> cols, diag1, diag2;

void printBoard() {
    cout << "Solution " << count_solutions << ":\n";
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++)
            cout << (board[r] == c ? "Q " : ". ");
        cout << "\n";
    }
    cout << "\n";
}

void solve(int row) {
    if (row == N) {
        count_solutions++;
        printBoard();
        return;
    }
    for (int col = 0; col < N; col++) {
        if (cols.count(col) || diag1.count(row - col) || diag2.count(row + col))
            continue;
        board[row] = col;
        cols.insert(col);
        diag1.insert(row - col);
        diag2.insert(row + col);

        solve(row + 1);

        cols.erase(col);
        diag1.erase(row - col);
        diag2.erase(row + col);
    }
}

int main() {
    N = 8; 
    board.assign(N, -1);
    solve(0);
    cout << "Total solutions for N=" << N << ": " << count_solutions << "\n";
    return 0;
}

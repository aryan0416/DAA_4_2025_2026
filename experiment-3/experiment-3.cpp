#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> result;
vector<string> board;
int n;

vector<int> colmn, diag1, diag2;

bool isSafe(int x, int y) {
    if(colmn[y] || diag1[x - y + n - 1] || diag2[x + y]) return false;
    return true;
}

void solve(int row) {
    if (row == n) {
        result.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 'Q';

            colmn[col] = diag1[row - col + n - 1] = diag2[row + col] = 1;

            solve(row + 1);

            board[row][col] = '.';
            colmn[col] = diag1[row - col + n - 1] = diag2[row + col] = 0;
        }
    }
}

int main() {
    cin >> n;

    board.assign(n, string(n, '.'));
    
    colmn.assign(n, 0);
    diag1.assign(2*n, 0);
    diag2.assign(2*n, 0);

    solve(0);
  
for (int i = 0; i < result.size(); i++) {        
    for (int j = 0; j < result[i].size(); j++) { 
        cout << result[i][j] << endl;
    }
    return 0;
}

// Time complexity : n!    for isSafe : O(1)


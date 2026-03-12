class Solution {
public:
bool dfs(vector<vector<char>>& board, string& word, int i, int j, int n, vector<vector<bool>>& visited) {
        if(n == word.size()) return true;

        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if(visited[i][j] || board[i][j] != word[n]) return false;

        visited[i][j] = true;

        bool status = dfs(board, word, i + 1, j, n + 1, visited) ||
                      dfs(board, word, i - 1, j, n + 1, visited) ||
                      dfs(board, word, i, j + 1, n + 1, visited) ||
                      dfs(board, word, i, j - 1, n + 1, visited);

        visited[i][j] = false; 
        return status;
    }

    bool exist(vector<vector<char>>& board, string word) {
        

        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(dfs(board, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

// O(m*n*4^l)   // l = word length 

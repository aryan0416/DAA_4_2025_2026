# DAA Assignment — Backtracking Problems
---

## Problem 1: N-Queens

Place N queens on an N×N chessboard such that no two queens attack each other (no shared row, column, or diagonal).

### Approach

Uses **backtracking** with O(1) conflict checks via three hash sets:
- `cols` — tracks occupied columns
- `diag1` — tracks occupied left diagonals (`row - col`)
- `diag2` — tracks occupied right diagonals (`row + col`)

A queen is placed row by row. At each row, only safe columns are tried; if no safe column exists, the algorithm backtracks.

### Tasks Covered

| Task | Implementation |
|------|----------------|
| Print all valid board configurations | `printBoard()` called for each solution |
| Count total valid configurations | Counter incremented per solution |
| Optimize via column and diagonal hashing | `unordered_set` for O(1) conflict lookup |

### Time & Space Complexity

| | Complexity |
|---|---|
| Time | O(N!) worst case |
| Space | O(N) for recursion stack + hash sets |

### Sample Output (N = 4)

```
Solution 1:
. Q . .
. . . Q
Q . . .
. . Q .

Solution 2:
. . Q .
Q . . .
. . . Q
. Q . .

Total solutions: 2
```

---

## Problem 2: Hamiltonian Cycle

Given an undirected graph, determine if a **Hamiltonian Cycle** exists — a cycle that visits every vertex exactly once and returns to the starting vertex.

### Approach

Uses **backtracking** on an adjacency matrix:
1. Start from vertex `0`.
2. At each step, try adding an unvisited vertex that has an edge from the last vertex in the current path.
3. After visiting all `N` vertices, check if an edge exists back to vertex `0`.
4. Backtrack if no valid extension exists.

### Tasks Covered

| Task | Implementation |
|------|----------------|
| Print one valid Hamiltonian cycle | Path array printed if cycle found |
| Return false if none exists | `false` returned after full backtrack |
| Adjacency matrix representation | `int graph[V][V]` |

### Time & Space Complexity

| | Complexity |
|---|---|
| Time | O(N!) worst case |
| Space | O(N) for path array + recursion stack |

### Sample Output

```
// Graph with cycle:
Hamiltonian Cycle found:
0 -> 1 -> 2 -> 4 -> 3 -> 0

// Graph without cycle:
No Hamiltonian Cycle exists.
```

---

## Source Code

### NQueens.cpp

```cpp
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
```

### HamiltonianCycle.cpp

```cpp
#include <bits/stdc++.h>
using namespace std;

const int V = 5;
int graph[V][V];
int path[V];

bool isSafe(int v, int pos) {
    if (!graph[path[pos - 1]][v]) return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v) return false;
    return true;
}

bool solve(int pos) {
    if (pos == V)
        return graph[path[pos - 1]][path[0]]; 

    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            if (solve(pos + 1)) return true;
            path[pos] = -1;
        }
    }
    return false;
}

void hamiltonianCycle() {
    fill(path, path + V, -1);
    path[0] = 0;
    if (!solve(1)) {
        cout << "No Hamiltonian Cycle exists.\n";
        return;
    }
    cout << "Hamiltonian Cycle found:\n";
    for (int i = 0; i < V; i++)
        cout << path[i] << " -> ";
    cout << path[0] << "\n";
}

int main() {
    
    int g[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };
    memcpy(graph, g, sizeof(g));
    hamiltonianCycle();
    return 0;
}
```

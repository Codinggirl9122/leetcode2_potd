class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();

        auto getPosition = [n](int s) {
            int quot = (s - 1) / n;
            int rem = (s - 1) % n;
            int row = n - 1 - quot;
            int col = (quot % 2 == 0) ? rem : (n - 1 - rem);
            return make_pair(row, col);
        };

        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q;  
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, moves] = q.front(); q.pop();

            for (int i = 1; i <= 6; ++i) {
                int next = curr + i;
                if (next > n * n) continue;
                auto [r, c] = getPosition(next);
                if (board[r][c] != -1) {
                    next = board[r][c];
                }
                if (next == n * n) return moves + 1;
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }

        return -1; 
        
    }
};
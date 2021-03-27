#include <iostream>
#include <queue>
#include <vector>

/**
 * LeetCode 25 March 2021 challenge
 */

using namespace std;

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    if (heights.size() == 0 || heights[0].size() == 0) return vector<vector<int>>();

    vector<vector<int>> ans;
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // Directions (up, down, left, right)
    int m = heights.size();
    int n = heights[0].size();

    // This matrix will keep the reached state of our land unit cells
    // (0 - not reached yet, 1 - reached by pacific, 2 - reached by atlantic, 3 - reached by both)
    vector<vector<int>> reached(m, vector<int>(n));

    queue<pair<int, int>> bfs;  // Queue to use for BFS

    // Initialize queue for pacific BFS
    for (int i = 0; i < m; i++) {
        bfs.emplace(i, 0);
    }
    
    for (int i = 0; i < n; i++) {
        bfs.emplace(0, i);
    }

    // Pacific BFS
    while (!bfs.empty()) {
        pair<int, int> p = bfs.front();
        int x = p.first;
        int y = p.second;

        reached[x][y] = 1;
        
        // Check if flow is possible in the 4 directions
        for (vector<int> dir : directions) {
            int newX = x + dir[0];
            int newY = y + dir[1];

            // Check boundaries
            if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                if (reached[newX][newY] == 0 && heights[x][y] <= heights[newX][newY]) { // Reachable
                    bfs.emplace(newX, newY);
                }
            }
        }

        bfs.pop();
    }

    // Initialize queue for atlantic BFS
    for (int i = 0; i < m; i++) {
        bfs.emplace(i, n-1);
    }
    
    for (int i = 0; i < n; i++) {
        bfs.emplace(m-1, i);
    }

    // Atlantic BFS
    while (!bfs.empty()) {
        pair<int, int> p = bfs.front();
        int x = p.first;
        int y = p.second;

        if (reached[x][y] == 1) {   
            reached[x][y] = 3;  // Reached by both oceans
            ans.push_back(vector<int>{x, y});
        }
        else reached[x][y] = 2;
        
        // Check if flow is possible in the 4 directions
        for (vector<int> dir : directions) {
            int newX = x + dir[0];
            int newY = y + dir[1];

            // Check boundaries
            if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                if (reached[newX][newY] < 2 && heights[x][y] <= heights[newX][newY]) { // Reachable
                    bfs.emplace(newX, newY);
                }
            }
        }

        bfs.pop();
    }

    return ans;
}

int main() {
    vector<vector<int>> heights = {{1,2,2,3,5}, {3,2,3,4,4}, {2,4,5,3,1}, {6,7,1,4,5}, {5,1,1,2,4}};

    vector<vector<int>> res = pacificAtlantic(heights);

    for (vector<int> v : res) {
        cout << "[" << v[0] << ", " << v[1] << "] ";
    }

    cout << endl;
}
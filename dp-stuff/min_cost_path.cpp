#include <iostream>
#include <queue>
#include<vector>
using namespace std;

// Function to return the cost of the minimum cost path
int findMinCost(vector<vector<int>>& cost, int x, int y) {
    int m = cost.size();
    int n = cost[0].size();

    if (x >= m || y >= n) {
        return 100000;
    }

    // Base case
    if (x == m-1 && y == n-1) {
        return cost[x][y];
    }

    int right = findMinCost(cost, x, y+1);
    int down = findMinCost(cost, x+1, y);
    int diagonal = findMinCost(cost, x+1, y+1);

    int best = min(right, min(down, diagonal));

    return cost[x][y] + best;


}

// function to find the minimum cost path
// to reach (m - 1, n - 1) from (0, 0)
// O(3 ^ (m * n)) Time and O(1) Space
int recursive_minCost(vector<vector<int>>& cost) {
    return findMinCost(cost, 0, 0);
}

int dijkstra_findMinCost(vector<vector<int>>& cost) {
    int m = cost.size();
    int n = cost[0].size();

    vector<pair<int,int>> directions = {{1,0}, {0,1}, {1,1}};

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    vector<vector<int>> dist(m, vector<int>(n, 1000000));
    dist[0][0] = cost[0][0];

    pq.push({cost[0][0], 0, 0});

    while (!pq.empty()) {
        vector<int> curr = pq.top();
        pq.pop();

        int x = curr[1];
        int y = curr[2];

        if (x==m-1 && y==n-1) {
            return dist[x][y];
        }

        for (auto dir : directions) {

            int newX = x + dir.first;
            int newY = y + dir.second;

            if (newX < m && newY < n) {

                // Relaxation
                if (dist[newX][newY] > dist[x][y]+ cost[newX][newY]) {
                    dist[newX][newY] = dist[x][y] + cost[newX][newY];
                    pq.push({dist[newX][newY], newX, newY});
                }
            }

        }
    }
    return dist[m-1][n-1];

}

int main() {

    vector<vector<int>> cost = {
        { 1, 2, 3 },
        { 4, 8, 2 },
        { 1, 5, 3 }
    };
    //cout << recursive_minCost(cost);
    cout << dijkstra_findMinCost(cost);
    return 0;
}

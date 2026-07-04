#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // Build the adjacency list: node -> pairs of {neighbor, distance}
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int dist = road[2];
            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }

        // BFS setup
        int min_score = 1e9; // Initialize with a large number
        vector<bool> visited(n + 1, false);
        queue<int> q;

        q.push(1);
        visited[1] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (const auto& edge : adj[curr]) {
                int neighbor = edge.first;
                int dist = edge.second;

                // Every road connected to a node in this component is reachable
                min_score = min(min_score, dist);

                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return min_score;
    }
};
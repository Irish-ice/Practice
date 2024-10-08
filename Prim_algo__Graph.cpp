#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    // Function to find the sum of weights of the Minimum Spanning Tree (MST)
    // and the list of MST edges along with their weights
    pair<int, vector<tuple<int, int, int>>> Spanning_tree(int V, vector<vector<pair<int, int>>> &adj) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);  // To track visited nodes
        vector<int> parent(V, -1);  // To track parent of each node in MST
        vector<tuple<int, int, int>> mst_edges;  // To store edges that are part of the MST

        pq.push({0, 0});  // Starting with node 0
        int sum = 0;  // Total weight of MST

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;

            // If the node is already visited, skip it
            if (vis[node] == 1) continue;

            // Mark the node as visited and add its weight to the MST sum
            vis[node] = 1;
            sum += wt;

            // If the node has a parent, add the edge (parent, node) to MST edges
            if (parent[node] != -1) {
                mst_edges.push_back({parent[node], node, wt});
            }

            // Explore all adjacent nodes of the current node
            for (auto adj_it : adj[node]) {
                int adjNode = adj_it.first;
                int edW = adj_it.second;

                // If the adjacent node is not visited, add it to the priority queue
                if (!vis[adjNode]) {
                    pq.push({edW, adjNode});
                    parent[adjNode] = node;  // Update parent for this node
                }
            }
        }

        return {sum, mst_edges};  // Return both sum and MST edges with weights
    }
};

int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter edges (u, v, weight) one by one:\n";
    for (int i = 0; i < E; ++i) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});  // Since it is an undirected graph
    }

    Solution sol;
    auto result = sol.Spanning_tree(V, adj);
    int mst_weight_sum = result.first;
    vector<tuple<int, int, int>> mst_edges = result.second;

    // Output the sum of the weights of the MST
    cout << "Sum of weights of the Minimum Spanning Tree: " << mst_weight_sum << endl;

    // Output the edges in the MST with their weights
    cout << "Edges in the Minimum Spanning Tree (u - v : weight):" << endl;
    for (auto edge : mst_edges) {
        int u, v, weight;
        tie(u, v, weight) = edge;
        cout << u << " - " << v << " : " << weight << endl;
    }

    return 0;
}


/*
Enter number of vertices and edges: 5 6
Enter edges (u, v, weight) one by one:
0 1 2
0 2 1
2 1 1
2 4 2
2 3 2
4 3 1
Sum of weights of the Minimum Spanning Tree: 5
Edges in the Minimum Spanning Tree (u - v : weight):
0 - 2 : 1
2 - 1 : 1
2 - 3 : 2
3 - 4 : 1

*/

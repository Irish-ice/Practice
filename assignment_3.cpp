#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Edge {
    public:

    int v;
    int cost;

    Edge(int _v, int _cost) : v(_v), cost(_cost) {}

    bool operator>(const Edge  &other) const {
        return  cost >  other.cost;
    }
};


class Graph {
    int n;
    vector<vector<Edge>> adj;

    public:

    Graph(int  _n) : n(_n), adj(_n + 1)  {}

    void addRoad(int u, int v, int cost) {
        adj[u].emplace_back(v, cost);
        adj[v].emplace_back(u, cost);
    }

    int PrimMST() {
        vector<bool> visited(n+1, false);
        priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
        pq.push(Edge(1, 0));
        int mstCost  = 0, edgesUsed = 0;

        while(!pq.empty() && edgesUsed < n) {
            Edge cur = pq.top();
            pq.pop();
            int  u = cur.v, cost = cur.cost;

            if(visited[u]) continue;

            visited[u] = true;
            mstCost += cost;
            edgesUsed++;

            for(Edge&  neighbor : adj[u]) {
                if(!visited[neighbor.v]) {
                    pq.push(neighbor);
                }
            }

        }
        return  (edgesUsed == n) ? mstCost : -1;
    }

};

int main() {
    int n, m;
    cout << "Enter the number of districts (n) and roads (m): ";
    cin >> n >> m;

    Graph graph(n);

    cout << "Enter the roads (u, v,  cost): " << endl;
    for(int i = 0 ; i < m ; i++) {
        int u, v,  cost;
        cin >> u >> v >> cost;

        graph.addRoad(u,  v,  cost);
    }

    int  result = graph.PrimMST();

    if( result == -1) {
        cout << "It is impossible to connect all districts."  << endl;
    }
    else {
        cout << "The minimum cost to connect all districts is:  "<< result <<  endl;
    }
}

/*

Enter the number of districts (n) and roads (m): 4 5
Enter the roads (u, v,  cost): 
1 2 3
1 3 4
4 2 6
4 3 5
1 4 2
The minimum cost to connect all districts is:  9
*/
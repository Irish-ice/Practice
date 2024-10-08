
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int V, E;

int dist[100];
bool visited[100];

void init() {
    for (int i = 0; i < 100; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
}

int find_minimum() {
    int minimum = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && (minimum == -1 || dist[i] < dist[minimum])) {
            minimum = i;
        }
    }
    return minimum;
}

void dijkstra(int cost[][100], int source) {
    dist[source] = 0;

    for (int i = 0; i < V; i++) {
        int u = find_minimum();
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && cost[u][v] != INT_MAX) {
                if (dist[v] > dist[u] + cost[u][v]) {
                    dist[v] = dist[u] + cost[u][v];
                }
            }


        }

    }

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            cout << i << " is unreachable.\n";
        } else {
            cout << i << "  " << dist[i] << endl;
        }
    }

}

bool has_negative_weight(int cost[][100]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (cost[i][j] < 0) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> V;
    cin >> E;
    int cost[100][100];


    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cost[i][j] = INT_MAX;
    }

    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        cost[u][v] = weight;
    }

    int source;
    cin >> source;


    if (has_negative_weight(cost)) {
        cout << "Graph contains negative weight edges. Therefore Dijkstra's algorithm cannot be applied.\n";
    } else {
        init();
        dijkstra(cost, source);
    }

    return 0;
}
}



/*
4 5
0 1 5
1 3 2
0 3 8
3 2 -3
0 2 11
0

*/

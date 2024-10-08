#include <iostream>
#include <vector>
using namespace std;



vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {

    vector<int> dist(V, 1e8);
    dist[S] = 0;
    for(int i = 0 ; i < V - 1 ; i++ ) {
        for( auto it : edges) {
            int u  = it[0];
            int  v =  it[1];
            int wt = it[2];

            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    for( auto it : edges) {
            int u  = it[0];
            int  v =  it[1];
            int wt  = it[2];

            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1};
            }
        }

        return dist;
}

int main(){

    int V, E, S;
    cout  <<  "Enter the number of vertices (V): ";
    cin >> V;
    cout  << "Enter the number of edges (E): ";
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    cout  << "Enter the edges (u, v, weight) one by one: \n";
    for(int i = 0 ; i  < E ; i++) {
        cin  >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cout << "Enter the source vertex(S): ";
    cin >> S;

    vector<int> distances  = bellman_ford(V, edges, S);

    if(distances[0] == -1) {
        cout  << "Graph  contains a negative weight  cycle.  \n";
    } else {
        cout << "Shortest distance from source vertex " << S << ":\n";
        for(int i = 0 ; i < V ; i++) {
            if(distances[i] ==  1e8 ) {
                cout << "Vertex " << i << ": INF\n";
            } else {
                cout << "Vertex " << i  << " : "<< distances[i] << "\n";
            }
        }
    }
    return 0;

}
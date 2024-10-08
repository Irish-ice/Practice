#include <iostream>
#include <vector>
using namespace std;


//for connected undirected graph
void dfs(int node, vector<int> adj[], int visit[], vector<int> &ls) {
    visit[node] = 1;
    ls.push_back(node);

    //traverse all its neighbours
    for(auto it : adj[node]) {
        if(!visit[it]){
            dfs(it, adj, visit,  ls);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    int visit[n] = [0];
    int start = 0;
    vector<int> ls;
    dfs(start, adj, visit, ls);
}

int main() {

}
#include <iostream>
#include  <vector>
#include <queue>
using namespace std;


vector<int> bfs(int V, vector<int> adj[]) {
    int visit[n] = {0};
    vist[0] = 1;
    queue<int> q;
    q.push(0);

    vector<int> bfs;

    while(!q.empty()) {
        int  node  = q.front();
        q.pop();
        bfs.push(node);

        for(auto if : adj[node]) {
            if(!visit[if]) {
                visit[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}
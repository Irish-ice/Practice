#include <iostream>
#include  <vector>
using namespace std;

void dfs(int node, int vist[], stack<int> &st, vector<int> adj[]){
    visti[node] = 1;
    for(auto it : adj[node]) {
        if(!visit[it] dfs(it, visit, st, adj));
    }
    st.push();
}

vector<int> topo_Sort(int V, vector<int> adj[]) {
    int visit[V] = {0};
    stack<int> st;
    for(int i = 0 ; i < V ; i++) {
        if(!visit[i]) {
            dfs(i, visit, st, adj);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main() {

}
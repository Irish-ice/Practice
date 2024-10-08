

#include <iostream>
#include <vector>
using namespace std;


class Solution {
    public:

    int spanning_Tree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, int>> edges;
        for(int i  = 0 ; i <  V; i++) {
            for(auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[i];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }

        Disjoint_Set ds(V);
        sort(edges.begin(), edges.end());
        int mst_wt = 0;
        for(auto it : edges) {
            int wt = it.first;
            int u =  it.second.first;
            int v =  it.second.second;

            if(ds.findUPar(u) != ds.findUPar(v)){
                mst_wt += wt;
                ds.union_by_rank(u, v);
            }
        }

        return  mst_wt;

    }
}

int main() {

}
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0; i <= n; i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};

int main() {
    int n, q;
    
    // User input for the number of elements in the disjoint set
    cout << "Enter the number of elements: ";
    cin >> n;

    DisjointSet ds(n);

    // User input for the number of union operations and queries
    cout << "Enter the number of union operations followed by queries: ";
    cin >> q;

    // Process union operations and queries
    for (int i = 0; i < q; ++i) {
        int type;
        cout << "\nChoose operation: 1 for union, 2 for query (same set): ";
        cin >> type;

        if (type == 1) {
            int u, v;
            cout << "Enter two elements to perform union: ";
            cin >> u >> v;
            ds.unionBySize(u, v);
        } 
        else if (type == 2) {
            int u, v;
            cout << "Enter two elements to check if they are in the same set: ";
            cin >> u >> v;
            if (ds.findUPar(u) == ds.findUPar(v)) {
                cout << "Same\n";
            } else {
                cout << "Not same\n";
            }
        } 
        else {
            cout << "Invalid operation!\n";
        }
    }

    return 0;
}




/*

Enter the number of elements: 7
Enter the number of union operations followed by queries: 6

Choose operation: 1 for union, 2 for query (same set): 1
Enter two elements to perform union: 1 2

Choose operation: 1 for union, 2 for query (same set): 1
Enter two elements to perform union: 2 3

Choose operation: 1 for union, 2 for query (same set): 1
Enter two elements to perform union: 4 5

Choose operation: 1 for union, 2 for query (same set): 2
Enter two elements to check if they are in the same set: 3 5
Not same

Choose operation: 1 for union, 2 for query (same set): 1
Enter two elements to perform union: 3 5

Choose operation: 1 for union, 2 for query (same set): 2
Enter two elements to check if they are in the same set: 3 5
Same







*/








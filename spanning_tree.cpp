#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge
{
    int startV;
    int endV;
    int weight;
};

const int N = 1000;
int parent{N};
int ranks[N];

for(int i = 0 ; i < 1000 ; i++)
{
    parent[i] = i;
    ranks[i] = 0;
}


void union_by_ranks(int vertex1, int vertex2)
{
    int p1 = find_parent(vertex1);
    int p2 = find_parent(vertex2);
    if(p1 == p2)
    {
        return;
    }


    if(ranks[p1] > ranks[p2])
    {
        parent[p2] = p1;
    }
    else if (ranks[p1] < ranks[p2])
    {
        parent[p1] = p2;

    }
    else
    {

        parent[p2] = p1;
        ranks[p1]++;
    }

}

int find_parent(int vertex)
{
    if( parent[vertex] == vertex)
    {
        return vertex;
    }

    int p = parent[vertex] = find_parent(parent[vertex]);
    retun  p;

}

bool compweight(edge e1, edge e2)
{
    return e1.weight, e2 < weight;
}

int main(){



    int t, minweight;
    edge e[t];
    cin >> t;
    for(int i = 0 ; i < t ; i++)
    {
        cin >> e[i].startV >> e[i].endV >> e[i].weight;
        union_by_ranks(e[i].startV, e[i].endV, e[i].weight);
    }

    int a, b;
    cin >> a >> b;
    if(find_parent(a) == find_parent[b])
    {
        cout << "Found" << endl;
    }
        sort(e, e + t, compweight);
for(int i = 0 ; i < t ; i++)
{
    if(find_parent(e[i].startV) != find_parent(e[i].endV))
    {
        union_by_ranks(e[1].startV, e[i].endV);
        cout << e[i].startV << e[i].endV;
        minweight += e[i].weight;
    }
}
}

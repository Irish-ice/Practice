#include <iostream>
#include <vector>
using namespace std;

struct edge
{
    int startV;
    int endV;
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
    retun parent[vertex] = find_parent(parent[vertex]);

}



int main(){

    int t;
    edge e[t];
    cin >> t;
    for(int i = 0 ; i < t ; i++)
    {
        cin >> e[i].startV >> e[i].endV;
        union_by_ranks(e[i].startV, e[i].endV);
    }

    int a, b;
    cin >> a >> b;
    if(find_parent(a) == find_parent[b])
    {
        cout << "Found" << endl;
    }
}

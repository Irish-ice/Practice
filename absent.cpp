#include using namespace std;

struct edge{
int startv;
int endv;
};

int parent[1000];
int ranks[1000];

void Initialize(){
for(int i=0;i<1000;i++){
parent[i]=i;
ranks[i]=0;
}
}

int findParent(int vertex){
if(parent[vertex]==vertex){
return vertex;
}
else{
return parent[vertex]=findParent(parent[vertex]);
}

}



void union_by_rank(int vertex1,int vertex2){
int p1=findParent(vertex1);
int p2=findParent(vertex2);

if(ranks[p1]>ranks[p2]){
parent[p2]=p1;
}
else if(ranks[p1] parent[p1]=p2;
}
else{
parent[p2]=p1;
ranks[p1]++;
}

}

int main(){
int t;
cin>>t;
edge e[t];
Initialize();


for(int i=0;i cin>> e[i].startv>>e[i].endv;
union_by_rank(e[i].startv,e[i].endv);
}

int a,b;
cin>>a>>b;
if(findParent[a]==findParent[b]){
cout<<"Found"< }

}

13:45
#include using namespace std;

struct edge{
int startv;
int endv;
int weight;
};

int parent[1000];
int ranks[1000];

void Initialize(){
for(int i=0;i<1000;i++){
parent[i]=i;
ranks[i]=0;
}
}

int findParent(int vertex){
if(parent[vertex]==vertex){
return vertex;
}
else{
return parent[vertex]=findParent(parent[vertex]);
}

}



void union_by_rank(int vertex1,int vertex2){
int p1=findParent(vertex1);
int p2=findParent(vertex2);

if(ranks[p1]>ranks[p2]){
parent[p2]=p1;
}
else if(ranks[p1] parent[p1]=p2;
}
else{
parent[p2]=p1;
ranks[p1]++;
}

}

bool comWeight( edge e1,edge e2){
return e1.weight }





int main(){
int t;
cin>>t;
edge e[t];
Initialize();

for(int i=0;i cin>>e[i].startv>>e[i].endv>>e[i].weight;
union_by_rank(e[i].startv,e[i].endv);

}


sort(e,e+t,comWeight);
int minWeight;

for(int i=0;i if(findParent(e[i].startv)!=findParent(e[i].endv)){
union_by_rank(e[i].startv,e[i].endv);
cout< minWeight +=e[i].weight;
}
}



int a,b;
cin>>a>>b;
if(findParent[a]==findParent[b]){
cout<<"Found"< }

}


#include using namespace std;

int V,E;

int dist[100];
bool visited[100];


void init(){
for(int i=0;i<100;i++){
dist[i]=INT_MAX;
visited[i]=false;
}

}

int find_minimum(){
int minimum=-1;
for(int i=0;i if(!visited[i] &&(minimum==-1||dist[i] minimum=i;
}
}
return minimum;

}

void dijkstra(int cost[][100],int source){
dist[source]=0;
for(int i=0;i int u=find_minimum();
visited[u]=true;

for(int v=0;v if(!visited[v]&&cost[u][v]!=0){
if(dist[v]>dist[u]+cost[u][v]){
dist[v]=dist[u]+cost[u][v];
}
}
}
}

for(int i=0;i if(dist[i]==INT_MAX){
cout< }
else{
cout< }
}

}

int main(){
int V,E;
cin>>V;
cin>>E;

int cost[100][100];

for(int i=0;i<100;i++){
for(int j=0;j<100;j++){
cost[i][j]=0;
}
}

init();

for(int i=0;i int u,v,weight;
cin>>u>>v>>weight;
cost[u][v]=weight;
//cost[v][u]=weight; if its not directed
}

int source;
cin>>source;

dijkstra(cost,source);

}
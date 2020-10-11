#include<bits/stdc++.h>
using namespace std;
class Graph{
    friend void dfs(Graph a,int source, bool *visited);
    friend void dfs_main(Graph a,int source);
    vector <int> *adjl;
    int vertex;
    public:
    Graph(int vertices);
    void addEdge(int vertex, int adjacent);
};
Graph::Graph(int vertices){
    adjl = new vector<int>[vertices];
    vertex = vertices;
}
void Graph::addEdge(int vertex, int adjacent){
    adjl[vertex].push_back(adjacent);
    adjl[adjacent].push_back(vertex); //Assuming to be an undirected graph
}
void dfs(Graph a,int source,bool visited[]){
    if(!visited[source]){
        cout<<source<<" ";
        visited[source] = true;
    } 
        
    for(auto s:a.adjl[source]){
        if(!visited[s]){
            dfs(a,s,visited);
        }
    }
}
void dfs_main(Graph a,int source){
   bool visited[a.vertex];
   for(int i=0;i<a.vertex;i++){
       visited[i]= false;
   }
   //Call dfs function for every vertex so that we dont leave vertices in case of unconnected graphs
   for(int i=0;i<a.vertex;i++){
       if(a.adjl[i].size()!=0)
        dfs(a,i,visited);
   }
}
int main(){
   Graph a(8);
   a.addEdge(0,1);
   a.addEdge(0,2);
   a.addEdge(0,3);
   a.addEdge(5,1);
   a.addEdge(3,1);
   a.addEdge(5,3);
   a.addEdge(6,7);
   a.addEdge(4,7);
   dfs_main(a,0);
return 0;
}
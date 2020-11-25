#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


void addEdge(vector <int> graph[], int a, int b) {
    graph[a].push_back(b);
    graph[b].push_back(a);
}

void DFSUtil(vector <int> adj[],vector <bool> &visited, int V, int u) {
    visited[u] = true;
    cout<<u<<" ";
    for(int i=0;i<adj[u].size();i++) {
        if(visited[adj[u][i]] == false) {
            DFSUtil(adj, visited, V, adj[u][i]);
        }
    }
}

void DFS(vector <int> adj[], int V) {
   vector <bool> visited(V, false);
    DFSUtil(adj, visited, V, 0);
    // for (int u=0;u<V;u++) {
    //     if(visited[u] == false) {
    //         DFSUtil(adj, visited, V, u);
    //     }
    // }

}


void BFS(vector <int> adj[], int V) {
    vector<bool> visited(V, false);
    BFSUtil(adj, visited, V, 0);

}

void BFSUtil(vector <int> adj[], vector <bool> &visited, int V, int u) {
    cout<<
}

int main () {

    int v = 5;
    vector <int> graph[v];
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 4);
    addEdge(graph, 4, 3);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    DFS(graph, v);
    return 0;
}
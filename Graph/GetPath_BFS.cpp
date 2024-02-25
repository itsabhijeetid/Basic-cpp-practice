//get  DFS path (Longest path comes max time) and BFS (Shortest Path comes max time) path both between s and e vertices 

#include <iostream>
using namespace std;

void InsertGraph (bool ** edges, int e) {
    for (int i = 0; i < e; i++) {
        int a,b;
        cin >> a >> b;
        edges[a][b] = true;
        edges[b][a] = true;
    }
}

void getPath_BFS (bool **edges, bool* visited, int v, int a, int b) {
    
}

int main () {
    int v,e;
    cout << "Enter the vertices : ";
    cin >> v;
    cout << "Enter the edges : ";
    cin >> e;
    bool** edges = new bool*[v];
    for (int i = 0; i < v; i++) {
        edges[i] = new bool [v];
    }
    bool *visited = new bool [v];
    for (int i = 0; i < v; i++) {
        visited[i] = true;
        for (int j = 0; j < v; j++) {
            edges[i][j] = false;
        }
    }
    InsertGraph (edges,e);
    int a,b;
    cout << "Enter the vertices of which DFS path have to be find : ";
    cin >> a >> b;
    getPath_BFS (edges, visited, v, a, b);
    delete [] visited;
    return 0;
}
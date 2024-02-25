// is there any path between s and e
// will be done same as BFS and DFS
#include <iostream>
using namespace std;

void InsertGraph (bool** edges, int e) {
    for (int i = 0; i < e; i++) {
        int a,b;
        cin >> a >> b;
        edges[a][b] = true;
        edges[b][a] = true;
    }
}

bool HasPath (bool** edges, bool* visited, int v, int a, int b) {
    if (edges[a][b] ) {
        return true;
    }
    visited[a] = true;
    for (int i = 0; i < v; i++) {
        if (edges[a][i]) {
            if(!visited[i]) {
                return HasPath (edges, visited, v, i, b);
            }
        }
    }
    return false;
}

int main () {
    int v, e;
    cout << "Enter the no of vertices : ";
    cin >> v;
    cout << "Enter the no of edges : ";
    cin >> e;
    bool** edges = new bool* [v];
    for (int i = 0; i < v; i++) {
        edges[i] = new bool[v];
    }
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        for (int j = 0; j < v; j++) {
            edges[i][j] = false;
        }
    }
    InsertGraph (edges, e);
    int a,b;
    cout << "Enter the vertices to be checked : ";
    cin >> a >> b;
    cout << HasPath (edges, visited, v, a, b);
    return 0;
}
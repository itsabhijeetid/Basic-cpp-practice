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

int getPath_DFS (bool **edges, bool* visited, int v, int a, int b, int *ans, int k) {
    visited[a] = true;
    ans[k] = a;
    k++;
    for (int i = 0; i < v; i++) {
        if (edges[a][i]) {
            if  (!visited[i]) {
                k = getPath_DFS (edges, visited, v, i, b, ans, k);
            }
        }
    }
    return k;
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
    int ans[v];
    int len = getPath_DFS (edges, visited, v, a, b, ans, 0);
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " ";
    }
    delete [] visited;
    return 0;
}
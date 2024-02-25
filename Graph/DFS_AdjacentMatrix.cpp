// Depth First Search for connected and disconnected both
#include <iostream> 
using namespace std;
// 6 6 0 1 0 2 0 3 2 4 2 5 3 5
void inputDFS (int e, bool **edges) {
    int a,b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        edges[a][b] = true;
        edges[b][a] = true;
    }
}

void printDFS (bool *visited, bool **edges, int sv, int v) {
    cout << sv << " ";
    visited[sv] = true;
    for (int i = 0; i < v; i++) {
        if (sv == i) {
            continue;
        }
        if (edges[sv][i] == true) {
            if (!visited[i]) {
                printDFS (visited, edges, i, v);
            } else {
                continue;
            }
        }
    }
}

void DFS (bool **edges, int v) {
    bool* visited = new bool[v];
    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++) {
        if (!visited[i] ) {
            printDFS (visited, edges, i, v);
        }
    }
    delete [] visited;
}

int main () {
    int v, e;
    cout << "Enter the no of vertices : ";
    cin >> v;
    cout << " Enter the no of edges : ";
    cin >> e;
    bool **edges = new bool* [v];
    bool *visited = new bool [v];
    for (int i = 0; i < v; i++) {
        edges[i] = new bool [v];
    }
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        for (int j = 0; j < v; j++) {
            edges[i][j] = false;
        }
    }
    inputDFS (e, edges);
    DFS (edges, v);
    return 0;
}
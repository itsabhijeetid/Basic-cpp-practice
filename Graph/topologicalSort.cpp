// Depth First Search for connected and disconnected both
#include <iostream> 
#include <stack>
using namespace std;
// 6 6 0 1 0 2 0 3 2 4 2 5 3 5
// 6 7 1 2 1 4 4 5 4 2 4 6 5 6 2 3
void inputDFS (int e, bool **edges) {
    int a,b;
    for (int i = 1; i <= e; i++) {
        cin >> a >> b;
        edges[a][b] = true;
        edges[b][a] = true;
    }
}

stack<int> printDFS (bool *visited, bool **edges, int sv, int v, stack<int> s) {
    // cout << sv << " ";
    visited[sv] = true;
    for (int i = 1; i <= v; i++) {
        if (sv == i) {
            continue;
        }
        if (edges[sv][i] == true) {
            if (!visited[i]) {
                s = printDFS (visited, edges, i, v, s);
            } else {
                continue;
            }
        }
    }
    s.push(sv);
    return s;
}

void DFS (bool **edges, int v) {
    bool* visited = new bool[v];
    stack<int> s;
    for (int i = 1; i <= v; i++) {
        visited[i] = false;
    }
    for (int i = 1; i <= v; i++) {
        if (!visited[i] ) {
            s = printDFS (visited, edges, i, v, s);
        }
    }
    while (!s.empty() ) {
        cout << s.top() << " ";
        s.pop();
    } cout << endl;
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
    for (int i = 1; i <= v; i++) {
        edges[i] = new bool [v];
    }
    for (int i = 1; i <= v; i++) {
        visited[i] = false;
        for (int j = 0; j < v; j++) {
            edges[i][j] = false;
        }
    }
    inputDFS (e, edges);
    DFS (edges, v);
    return 0;
}
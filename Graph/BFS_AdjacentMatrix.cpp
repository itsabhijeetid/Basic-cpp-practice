// Breadth First Search for connected and disconnected both
#include <iostream>
#include<queue>
using namespace std;

void inputBFS (bool **edges, int e) {
    int a,b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        edges[a][b] = true;
        edges[b][a] = true;
    }
}

void printBFS (bool **edges, bool* visited, int sv, int v) {
    queue<int> q;
    q.push(sv);
    while (!q.empty() ) 
    {   
        cout << q.front() << " ";
        visited[q.front()] = true;
        for (int i = 0; i < v; i++) {
            if (q.front() == i) {
                continue;
            }
            if (edges[q.front()][i] == true && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
        q.pop();
    }
}

void BFS (bool ** edges, int v) {
    bool* visited = new bool[v];
    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++) {
        if (!visited[i] ) {
            printBFS (edges,visited, i, v);
        }
    }
    delete [] visited;
}

int main () {
    int v, e;
    cout << "Enter the no of vertices : ";
    cin >> v;
    cout << "Enter the no of edges : ";
    cin >> e;
    bool ** edges = new bool* [v];
    bool *visited = new bool [v];
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        edges[i] = new bool [v];
        for (int j = 0; j < v; j++) {
            edges[i][j] = false;
        }
    }
    inputBFS (edges,e);
    BFS (edges,v);
    return 0;
}

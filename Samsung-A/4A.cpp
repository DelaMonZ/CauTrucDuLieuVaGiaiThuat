#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph, int src) {
    int V = graph.size();
    vector<int> color(V, -1);
    color[src] = 1;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            } else if (graph[u][v] && color[v] == color[u]) {
                return false; // Nếu có cạnh nối hai đỉnh cùng mầu, đồ thị không phải là đồ thị hai mầu
            }
        }
    }

    return true;
}

bool hasOddCycle(vector<vector<int>>& graph) {
    int V = graph.size();
    for (int i = 0; i < V; i++) {
        if (!isBipartite(graph, i)) {
            return true; // Nếu đồ thị không phải là đồ thị hai mầu, tức là nó chứa chu trình độ dài lẻ
        }
    }
    return false;
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    if (hasOddCycle(graph)) {
        cout << "Do thi chua chu trinh do dai le, khong phai la do thi hai mau." << endl;
    } else {
        cout << "Do thi khong chua chu trinh do dai le, la do thi hai mau." << endl;
    }

    return 0;
}


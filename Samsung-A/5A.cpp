#include <iostream>
#include <vector>
using namespace std;

bool isBiconnected(vector<vector<int>>& graph, int u, int v, vector<bool>& visited) {
    int V = graph.size();
    vector<int> parent(V, -1);
    vector<bool> articulation(V, false);
    int time = 0;

    // Hàm đệ quy để tìm các điểm articulation trong đồ thị
    auto dfsArticulation = [&](int u) {
        int children = 0;
        visited[u] = true;
        int discTime = time++;
        int low = discTime;

        for (int v = 0; v < V; v++) {
            if (graph[u][v]) {
                if (!visited[v]) {
                    children++;
                    parent[v] = u;
                    dfsArticulation(v);
                    low = min(low, low[v]);
                    if (low[v] >= discTime && parent[u] != -1) {
                        articulation[u] = true;
                    }
                } else if (v != parent[u]) {
                    low = min(low, discTime[v]);
                }
            }
        }

        if (parent[u] == -1 && children > 1) {
            articulation[u] = true;
        }
    };

    dfsArticulation(u);

    if (!visited[v]) {
        return false; // Nếu không có đường đi nối giữa s và t, đồ thị không biconnected
    }

    return !articulation[u] && !articulation[v];
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 1},
        {1, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    int s = 0;
    int t = 4;
    vector<bool> visited(graph.size(), false);

    if (isBiconnected(graph, s, t, visited)) {
        cout << "Do thi biconnected." << endl;
    } else {
        cout << "Do thi khong biconnected." << endl;
    }

    return 0;
}


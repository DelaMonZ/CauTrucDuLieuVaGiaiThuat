#include <iostream>
#include <vector>
using namespace std;

bool isEdgeConnected(vector<vector<int>>& graph, int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent) {
    static int time = 0;
    visited[u] = true;
    disc[u] = low[u] = time++;

    for (int v = 0; v < graph.size(); v++) {
        if (graph[u][v]) {
            if (!visited[v]) {
                parent[v] = u;
                if (!isEdgeConnected(graph, v, visited, disc, low, parent)) {
                    return false;
                }
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    return false; // Cạnh (u, v) là cầu
                }
            } else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
    return true;
}

bool isEdgeConnectedGraph(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<bool> visited(V, false);
    vector<int> disc(V, -1), low(V, -1), parent(V, -1);

    if (!isEdgeConnected(graph, 0, visited, disc, low, parent)) {
        return false; // Tồn tại cầu trong đồ thị
    }

    // Kiểm tra xem tất cả các đỉnh đã được duyệt qua hay chưa
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            return false; // Đồ thị không liên thông
        }
    }
    return true;
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };

    if (isEdgeConnectedGraph(graph)) {
        cout << "Do thi lien thong canh." << endl;
    } else {
        cout << "Do thi khong lien thong canh." << endl;
    }

    return 0;
}


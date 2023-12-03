#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool hasHamiltonianPath(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> inDegree(n, 0); // Đếm số cạnh vào của mỗi đỉnh
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            inDegree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++;
        for (int v : graph[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return count == n;
}

int main() {
    int n, m;
    cin >> n >> m; // Đọc số đỉnh và số cạnh của đồ thị
    vector<vector<int>> graph(n); // Khởi tạo đồ thị có hướng

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; // Đọc các cạnh của đồ thị
        graph[u].push_back(v); // Thêm cạnh từ u đến v
    }

    if (hasHamiltonianPath(graph)) {
        cout << "Đồ thị chứa đường đi Hamilton";
    } else {
        cout << "Đồ thị không chứa đường đi Hamilton";
    }

    return 0;
}


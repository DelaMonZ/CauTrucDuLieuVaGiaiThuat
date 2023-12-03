#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool hasHamiltonianPath(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> inDegree(n, 0);
    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            inDegree[v]++;
        }
    }

    queue<int> q;
    for (int u = 0; u < n; u++) {
        if (inDegree[u] == 0) {
            q.push(u);
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

bool hasUniqueTopologicalOrder(vector<vector<int>>& graph) {
    if (!hasHamiltonianPath(graph)) {
        return false;
    }

    int n = graph.size();
    vector<int> order(n, -1);
    vector<int> path = getHamiltonianPath(graph);

    for (int i = 0; i < n; i++) {
        order[path[i]] = i;
    }

    for (int u = 0; u < n - 1; u++) {
        for (int v : graph[u]) {
            if (order[u] > order[v]) {
                return false;
            }
        }
    }

    return true;
}

vector<int> getHamiltonianPath(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> path;

    // TODO: Implement the algorithm to find a Hamiltonian path in the graph

    return path;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; // Đọc các cạnh của đồ thị
        graph[u].push_back(v); // Thêm cạnh từ u đến v
    }

    if (hasUniqueTopologicalOrder(graph)) {
        cout << "Đồ thị có thứ tự tô pô duy nhất";
    } else {
        cout << "Đồ thị không có thứ tự tô pô duy nhất";
    }

    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& path, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonCycleUtil(vector<vector<int>>& graph, vector<int>& path, int pos) {
    if (pos == graph.size()) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < graph.size(); v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamiltonCycleUtil(graph, path, pos + 1))
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

bool hasHamiltonCycle(vector<vector<int>>& graph) {
    vector<int> path(graph.size(), -1);
    path[0] = 0;

    if (!hamiltonCycleUtil(graph, path, 1)) {
        cout << "Khong ton tai chu trinh Hamilton" << endl;
        return false;
    }

    cout << "Ton tai chu trinh Hamilton" << endl;
    return true;
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hasHamiltonCycle(graph);

    return 0;
}


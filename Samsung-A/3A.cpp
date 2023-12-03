#include <iostream>
#include <vector>
using namespace std;

int countParallelEdges(vector<vector<int>>& graph) {
    int V = graph.size();
    int count = 0;

    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (u != v) {
                int edges_between_uv = 0;
                for (int i = 0; i < graph[u].size(); i++) {
                    if (graph[u][i] == 1 && graph[v][i] == 1) {
                        edges_between_uv++;
                    }
                }
                count += edges_between_uv / 2; // Chia 2 vì cần đếm cạnh song song một lần
            }
        }
    }

    return count;
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };

    cout << "So canh song song trong do thi: " << countParallelEdges(graph) << endl;

    return 0;
}


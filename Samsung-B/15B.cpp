#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN]; // danh sách kề
int indegree[MAXN]; // mảng lưu bậc vào của mỗi đỉnh
int n, m; // số đỉnh và số cạnh

void topoSort() {
    queue<int> q; // hàng đợi chứa các đỉnh nguồn
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " "; // đánh nhãn cho đỉnh u
        for (int v : adj[u]) {
            indegree[v]--; // giảm bậc vào của đỉnh v đi 1
            if (indegree[v] == 0) {
                q.push(v); // nếu bậc vào của v bằng 0 thì thêm v vào hàng đợi
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++; // tăng bậc vào của đỉnh v lên 1
    }
    topoSort();
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
bool isConnected(vector< vector<int> > adj2) {
    vector<bool> visited(adj2.size(), false);
    int start = 0;
    for (int i = 0; i < adj2.size(); i++) {
        if (adj2[i].size() > 0) {
            start = i;
            break;
        }
    }
    stack<int> stack;
    stack.push(start);
    while (!stack.empty()) {
        int u = stack.top();
        stack.pop();
        if (!visited[u]) {
            visited[u] = true;
            for (int v : adj2[u]) {
                if (!visited[v]) {
                    stack.push(v);
                }
            }
        }
    }
    for (bool v : visited) {
        if (!v) {
            return false;
        }
    }
    return true;
}
bool hasEqualInAndOutDegree(vector< vector<int> > adj1) {
    for (int i = 0; i < adj1.size(); i++) {
        if (adj1[i].size() % 2 != 0) {
            return false;
        }
    }
    return true;
}
bool hasEulerCycle(vector< vector<int> > adj1, vector< vector<int> > adj2) {
    if (!isConnected(adj2) || !hasEqualInAndOutDegree(adj1)) {
        return false;
    }
    return true;
}
void printCircuit(vector< vector<int> > adj1, vector< vector<int> > adj2) {
    if (!hasEulerCycle(adj1, adj2)) {
        cout << "Không có chu trình Euler";
        return;
    }
    unordered_map<int,int> edge_count;
    for (int i=0; i<adj2.size(); i++) {
        edge_count[i] = adj2[i].size();
    }
    if (!adj2.size()) return;
    stack<int> curr_path;
    vector<int> circuit;
    curr_path.push(0);
    int curr_v = 0;
    while (!curr_path.empty()) {
        if (edge_count[curr_v]) {
            curr_path.push(curr_v);
            int next_v = adj2[curr_v].back();
            edge_count[curr_v]--;
            adj2[curr_v].pop_back();
            curr_v = next_v;
        } else {
            circuit.push_back(curr_v);
            curr_v = curr_path.top();
            curr_path.pop();
        }
    }
    for (int i=circuit.size()-1; i>=0; i--) {
        cout << circuit[i] + 1;
        if (i) cout<<" -> ";
    }
}

int main() {
    vector< vector<int> > adj1, adj2;

    adj2.resize(9);
    adj2[0].push_back(1);
    adj2[1].push_back(2);
    adj2[2].push_back(3);
    adj2[2].push_back(8);
    adj2[3].push_back(4);
    adj2[4].push_back(2);
    adj2[4].push_back(5);
    adj2[5].push_back(0);
    adj2[5].push_back(6);
    adj2[6].push_back(7);
    adj2[7].push_back(5);
    adj2[8].push_back(4);

    adj1 = adj2;
    adj1[1].push_back(0);
    adj1[2].push_back(1);
    adj1[3].push_back(2);
    adj1[8].push_back(2);
    adj1[4].push_back(3);
    adj1[2].push_back(4);
    adj1[5].push_back(4);
    adj1[0].push_back(5);
    adj1[6].push_back(5);
    adj1[7].push_back(6);
    adj1[5].push_back(7);
    adj1[4].push_back(8);

    printCircuit(adj1, adj2);

    return 0;
}

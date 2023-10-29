#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node {
  int id;
  vector<int> neighbors;
};

void dfs(vector<Node>& graph, int node, vector<bool>& visited) {
  visited[node] = true;
  cout << node << " ";

  for (int neighbor : graph[node].neighbors) {
    if (!visited[neighbor]) {
      dfs(graph, neighbor, visited);
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<Node> graph(n);
  for (int i = 0; i < n; i++) {
    graph[i].id = i;
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    graph[u].neighbors.push_back(v);
    graph[v].neighbors.push_back(u);
  }

  vector<bool> visited(n, false);

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs(graph, i, visited);
    }
  }

  cout << endl;

  return 0;
}

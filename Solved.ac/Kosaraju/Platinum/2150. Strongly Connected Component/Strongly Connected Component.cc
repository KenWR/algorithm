// Kosaraju

#include <algorithm>
#include <deque>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int Kosaraju(const vector<vector<int>> &graph_original,
             const vector<vector<int>> &graph_reversed,
             vector<vector<int>> &components);
void dfs(const vector<vector<int>> &adj, vector<bool> &visited, deque<int> &s,
         int node);
void dfs(const vector<vector<int>> &adj, vector<bool> &visited, int node,
         vector<int> &component);
void clearVisited(vector<bool> &visited);
void printAnswer(const int count, const vector<vector<int>> &components);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int v, e; // number of vertices and edges
  cin >> v >> e;

  vector<vector<int>> graph_original(v + 1);
  vector<vector<int>> graph_reversed(v + 1);

  for (int i = 0; i < e; i++) {
    int node1, node2; // vertices of the edge
    cin >> node1 >> node2;

    graph_original[node1].push_back(node2);
    graph_reversed[node2].push_back(node1);
  }

  vector<vector<int>> components;
  int count = Kosaraju(graph_original, graph_reversed, components);

  // Sort the components by the first element of each component
  // and then sort each component in ascending order
  for (auto &component : components) {
    sort(component.begin(), component.end());
  }
  sort(components.begin(), components.end());

  printAnswer(count, components);
}

int Kosaraju(const vector<vector<int>> &graph_original,
             const vector<vector<int>> &graph_reversed,
             vector<vector<int>> &components) {
  vector<bool> visited(graph_original.size(), false);
  deque<int> s;
  for (int i = 1; i < graph_original.size(); i++) {
    if (visited[i] == false) {
      dfs(graph_original, visited, s, i);
    }
  }
  clearVisited(visited);

  int count = 0;

  while (!s.empty()) {
    int node = s.back();
    s.pop_back();
    if (visited[node] == false) {
      vector<int> component;
      dfs(graph_reversed, visited, node, component);
      components.push_back(component);
      count++;
    }
  }

  return count;
}

void dfs(const vector<vector<int>> &adj, vector<bool> &visited, deque<int> &s,
         int node) {
  if (visited[node] == true) {
    return;
  }

  visited[node] = true;
  for (const auto &next_node : adj[node]) {
    if (visited[next_node] == false) {
      dfs(adj, visited, s, next_node);
    }
  }

  s.push_back(node);
}

void dfs(const vector<vector<int>> &adj, vector<bool> &visited, int node,
         vector<int> &component) {
  if (visited[node])
    return;

  visited[node] = true;
  component.push_back(node);

  for (const auto &next_node : adj[node]) {
    if (!visited[next_node]) {
      dfs(adj, visited, next_node, component);
    }
  }
}

void printAnswer(const int count, const vector<vector<int>> &components) {
  cout << count << "\n";
  for (const auto &component : components) {
    for (const auto &node : component) {
      cout << node << " ";
    }
    cout << "-1\n";
  }
}

void clearVisited(vector<bool> &visited) {
  for (int i = 0; i < visited.size(); i++) {
    visited[i] = false;
  }
}

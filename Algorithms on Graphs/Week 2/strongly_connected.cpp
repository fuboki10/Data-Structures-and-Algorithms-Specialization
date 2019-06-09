#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using std::stack;
using std::vector;
using std::pair;
using std::cout;
using std::endl;

void dfs(int v, vector<bool>& vis, vector<vector<int>> &adj, stack<int> &st)
{
    vis[v] = 1;
    for (auto u : adj[v])
    {
        if (!vis[u]) dfs(u, vis, adj, st);
    }
    st.push(v);
}
vector<vector<int>> transpose(vector<vector<int>> &adj)
{
    vector<vector<int>> radj(adj.size(), vector<int>());
    for (int i = 0; i < adj.size(); ++i)
    {
        for (auto u : adj[i])
        {
            radj[u].push_back(i);
        }
    }
    return radj;
}
int number_of_strongly_connected_components(vector<vector<int>> &adj) {
  int result = 0;
  stack<int> st;
  vector<bool> vis(adj.size(), 0);
  vector<vector<int>> radj = transpose(adj);
  for (int i = 0; i < radj.size(); ++i)
  {
      if (!vis[i])
      {
          dfs(i,vis,radj,st);
      }
  }

  std::fill(vis.begin(), vis.end(), 0);
  while (!st.empty())
  {
      int x = st.top();
      st.pop();
      if (!vis[x])
      {
          stack<int> st2;
          dfs(x , vis, adj, st2);
          result++;
      }
  }
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << number_of_strongly_connected_components(adj);
}

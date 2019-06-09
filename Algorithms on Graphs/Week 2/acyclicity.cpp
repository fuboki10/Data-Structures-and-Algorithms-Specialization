#include <iostream>
#include <vector>

using std::vector;
using std::pair;
vector<bool> vis;
vector<bool> stack;
bool dfs(int u, vector<vector<int> > &adj)
{
    if (!vis[u])
    {
        vis[u] = 1;
        stack[u] = 1;
        for (auto var : adj[u])
        {
            if (!vis[var] && dfs(var, adj))
            {
                return 1;
            }
            else if (stack[var])
            {
                return 1;
            }
        }
    }
    stack[u] = 0;
    return 0;
}

int acyclic(vector<vector<int> > &adj) {
  for (int i = 0; i < adj.size(); ++i)
  {
     if (!vis[i])
     {
        if (dfs(i,adj)) return 1;
     }
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vis.resize(n, 0);
  stack.resize(n, 0);
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}

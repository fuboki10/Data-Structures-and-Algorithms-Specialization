#include <iostream>
#include <vector>

using std::vector;

#define INT_MAX 2147483647

bool negative_cycle_util(vector<vector<int> > &adj, vector<vector<int> > &cost, int src, int dst[])
{
    int n = adj.size();
    for (int i = 0; i < n; ++i)
    {
        dst[i] = INT_MAX;
    }
    dst[src] = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < adj.size(); ++j)
        {
            if (dst[j] != INT_MAX)
                for (int k = 0; k < adj[j].size(); ++k)
                {
                    if (dst[j] + cost[j][k] < dst[adj[j][k]])
                    {
                       dst[adj[j][k]] = dst[j] + cost[j][k];
                    }
                }
        }
    }

    for (int j = 0; j < adj.size(); ++j)
    {
        if (dst[j] != INT_MAX)
            for (int k = 0; k < adj[j].size(); ++k)
            {
                if (dst[j] + cost[j][k] < dst[adj[j][k]])
                {
                   return 1;
                }
            }
    }

    return 0;
}


int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  int dst[adj.size()];
  int n = adj.size();
  for (int i = 0; i < n; ++i)
  {
      dst[i] = INT_MAX;
  }
  for (int i = 0; i < n; ++i)
  {
      if (dst[i] == INT_MAX)
        if (negative_cycle_util(adj, cost, i, dst)) return 1;
  }

  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}

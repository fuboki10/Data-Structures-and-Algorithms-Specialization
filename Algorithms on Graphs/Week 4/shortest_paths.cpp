#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <algorithm>
const long long MAX = std::numeric_limits<long long>::max();

using std::min;
using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

void shortest_paths(vector<vector<int> > &adj, vector<vector<long long> > &cost, int s, vector<long long> &dst, vector<int> &reachable, vector<int> &shortest) {
  int n = adj.size();
  bool vis[n] = {0};
  queue<int> q;
  dst[s] = 0;

  for (int i = 0; i < n - 1; ++i)
  {

      for (int j = 0; j < n; ++j)
      {
          if (dst[j] != MAX)
          for (int k = 0; k < adj[j].size(); ++k)
          {
              dst[adj[j][k]] = min(dst[adj[j][k]], dst[j] + cost[j][k]);
          }
      }
  }

  for (int j = 0; j < n; ++j)
  {
      if (dst[j] != MAX)
      for (int k = 0; k < adj[j].size(); ++k)
      {
        if (dst[adj[j][k]] <= dst[j] + cost[j][k] || vis[adj[j][k]])
        {
            continue;
        }

        // bfs
        q.push(adj[j][k]);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            vis[cur] = 1;
            shortest[cur] = 0;
            for (auto u : adj[cur])
            {
                if (!vis[u]) q.push(u);
            }
        }
      }
  }

  for (int i = 0; i < n; ++i)
  {
      if (dst[i] != MAX) reachable[i] = 1;
  }

}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<long long> > cost(n, vector<long long>());
  for (int i = 0; i < m; i++) {
    int x, y;
    long long w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}

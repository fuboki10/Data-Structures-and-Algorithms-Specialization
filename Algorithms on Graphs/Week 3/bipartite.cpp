#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

bool isBipartite(vector<vector<int> > &adj, int src)
{
    int colorArr[adj.size()];
    for (int i = 0; i < adj.size(); ++i)
        colorArr[i] = -1;

    colorArr[src] = 1;
    queue <int> q;
    q.push(src);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto child : adj[u])
        {
            if (colorArr[child] == -1)
            {
                colorArr[child] = 1 - colorArr[u];
                q.push(child);
            }
            else if (colorArr[child] == colorArr[u])
                return false;
        }
    }
    return true;
}

int bipartite(vector<vector<int> > &adj) {

  return isBipartite(adj, 0);
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}

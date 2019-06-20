#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

struct node
{
	int id,cost;
	node(int ii , int cc)
	{
		id = ii , cost = cc;
	}
	bool operator < (const node & nn) const
	{
		return cost > nn.cost;
	}
};


int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  priority_queue<node> q;   // cost , index
  q.push(node(s, 0));

  bool vis[adj.size()];
  memset(vis, 0, sizeof vis);

  vis[s] = 1;

  while (!q.empty())
  {
      node cur = q.top();
      q.pop();
      vis[cur.id] = 1;
      if (cur.id == t)
      {
          return cur.cost;
      }

      int i = 0;

      for (auto u : adj[cur.id])
      {
          if (!vis[u])
          {
              q.push(node(u, cur.cost + cost[cur.id][i]));
          }

          i++;
      }

  }

  return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}

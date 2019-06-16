#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using std::vector;
using std::queue;


int distance(vector<vector<int> > &adj, int s, int t) {
  queue<int> q;
  q.push(s);
  int SP[adj.size()];

  memset(SP, -1, sizeof SP);

  SP[s] = 0;


  while (!q.empty())
  {
  	int u = q.front();
  	q.pop();

  	if (u == t)
  	{
  		return SP[t];
  	}

  	for (auto child : adj[u])
  	{
		if (SP[child] == -1)
		{
       		SP[child] = SP[u] + 1;
       		q.push(child);
		}
  	}
  }

  return -1;
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}

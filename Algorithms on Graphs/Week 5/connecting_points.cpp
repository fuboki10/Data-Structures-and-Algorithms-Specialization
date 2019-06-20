#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>

using std::pair;
using std::priority_queue;
using std::vector;
using std::hypot;
using std::swap;

struct edge
{
    int src;
    int dst;
    double w;
    edge(double _w, int _src, int _dst)
    {
        w = _w;
        src = _src;
        dst = _dst;
    }

    bool operator < (const edge& e) const
    {
        return w > e.w;
    }

};

const int N = 1e5 + 10;
int parent[N];
int rank[N];

void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;

  priority_queue<edge> pq;
  for (int i = 0; i < x.size(); ++i)
  {
      make_set(i);
      for (int j = i + 1; j < x.size(); ++j)
      {
          pq.push(edge(hypot(x[i] - x[j], y[i] - y[j]), i, j));
      }
  }

  while (!pq.empty())
  {
      struct edge cur = pq.top();
      pq.pop();

      if (find_set(cur.src) != find_set(cur.dst))
      {
          result += cur.w;
          union_sets(cur.src, cur.dst);
      }
  }

  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}

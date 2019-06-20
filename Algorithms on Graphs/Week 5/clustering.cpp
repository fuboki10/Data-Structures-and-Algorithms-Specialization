#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>
#include <queue>
#include <limits>

using std::priority_queue;
using std::vector;
using std::pair;
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
int size = 0;

void make_set(int v) {
    parent[v] = v;
    rank[v] = 0;
    size++;
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
        size--;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }

}

double clustering(vector<int> x, vector<int> y, int k) {
  double result = std::numeric_limits<int>::max();

  priority_queue<edge> pq;
  for (int i = 0; i < x.size(); ++i)
  {
      make_set(i);
      for (int j = i + 1; j < x.size(); ++j)
      {
          pq.push(edge(hypot(x[i] - x[j], y[i] - y[j]), i, j));
      }
  }

  while (!pq.empty() && size != k)
  {
      struct edge cur = pq.top();
      pq.pop();

      if (find_set(cur.src) != find_set(cur.dst))
      {
          union_sets(cur.src, cur.dst);
      }
  }

  while (!pq.empty())
  {
      struct edge cur = pq.top();
      pq.pop();

      if (find_set(cur.src) != find_set(cur.dst))
        result = std::min(result, cur.w);
  }

  return result;
}

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
}

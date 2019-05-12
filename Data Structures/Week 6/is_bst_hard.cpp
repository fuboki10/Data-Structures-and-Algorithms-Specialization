#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max;
using std::min;

const long long mx = 214748364700;
const long long mn = -214748364800;
struct Node {
  long long key;
  long long left;
  long long right;

  Node() : key(0), left(-1), right(-1) {}
  Node(long long key_, long long left_, long long right_) : key(key_), left(left_), right(right_) {}
};
bool rec_isBST(int i, const vector<Node>& tree, long long mini, long long maxi)
{
    if (i == -1) return 1;

    if (tree[i].key < mini || tree[i].key > maxi)
    {
        return 0;
    }

    return rec_isBST(tree[i].left, tree, mini, tree[i].key - 1) && rec_isBST(tree[i].right, tree, tree[i].key, maxi);
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  if (!tree.size()) return 1;

  return rec_isBST(0, tree, mn, mx);
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    long long key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}

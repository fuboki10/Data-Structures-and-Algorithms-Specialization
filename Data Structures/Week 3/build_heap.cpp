#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }
 int parent(int i)
 {
  return ((i-1)/2);
 }

 int left_child(int i){
  return 2*i + 1;
 }
 int right_child(int i){
  return 2*i + 2;
 }
 void SiftDown(int i){
  int minidx = i;
  int left = left_child(i);
  if (left < data_.size() && data_[left] < data_[minidx])
  {
    minidx = left;
  }
  int right = right_child(i);
  if (right < data_.size() && data_[right] < data_[minidx])
  {
    minidx = right;
  }
  if (i != minidx)
  {
    swaps_.push_back({i,minidx});
    swap(data_[i],data_[minidx]);
    SiftDown(minidx);
  }
 }
  void GenerateSwaps() {
    swaps_.clear();
   for (int i = data_.size()/2; i >= 0; --i)
   {
    SiftDown(i);
   }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}

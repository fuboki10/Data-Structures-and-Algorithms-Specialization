#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct worker
{
	int finTime;
	int idx;
	worker(int _idx, int _finTime) : idx(_idx),finTime(_finTime) {}
	bool operator < (const worker & w1) const
	{
		if (finTime == w1.finTime)
		{
			return idx > w1.idx;
		}
		return finTime > w1.finTime;
	}
    bool operator > (const worker & w1) const
	{
		if (finTime == w1.finTime)
		{
			return idx < w1.idx;
		}
		return finTime < w1.finTime;
	}
};

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;
  vector<int> assigned_workers_;
  vector<long long> start_times_;

  std::priority_queue<worker> pq;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    for (int i = 0; i < num_workers_; ++i)
    {
    	pq.push(worker(i,0));
    }
    for (int i = 0; i < jobs_.size(); ++i)
    {
    	int duration = jobs_[i];
    	worker w = pq.top();
    	pq.pop();
    	assigned_workers_[i] = w.idx;
    	start_times_[i] = w.finTime;
    	w.finTime += duration;
    	pq.push(w);
    }
  }
 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}

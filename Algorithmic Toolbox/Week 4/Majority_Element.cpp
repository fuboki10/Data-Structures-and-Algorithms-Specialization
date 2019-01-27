// Fub0ki
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define  mp make_pair
#define  pb push_back
#define bn begin()
#define nd end()
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define EPS 1e-7
int count(vector<int> &a, int left, int right, int element)
{
	int count = 0;
	for (int i = left; i <= right; i++)
	{
		if (a[i] == element)
		{
			count++;
		}
	}
	return count;
}

int get_majority_element(vector<int> &a, int left, int right) {
	if (left > right) return -1;
	if (left == right) return a[left];
	int mid = left + (right - left) / 2;
	int leftCount = get_majority_element(a, left, mid);
	int rightCount = get_majority_element(a, mid + 1, right);
	if (leftCount == -1 && rightCount != -1)
	{
		int num = count(a, left, right, rightCount);
		if (num > (right - left + 1) / 2)
		{
			return rightCount;
		}
		else
		{
			return -1;
		}

	}
	else if (rightCount == -1 && leftCount != -1)
	{
		int num = count(a, left, right, leftCount);
		if (num > (right - left + 1) / 2)
		{
			return leftCount;
		}
		else
		{
			return -1;
		}
	}
	else if (leftCount != -1 && rightCount != -1)
	{
		int leftNum = count(a, left, right, leftCount);
		int rightNum = count(a, left, right, rightCount);
		if (leftNum > (right - left + 1) / 2)
		{
			return leftCount;
		}
		else if (rightNum > (right - left + 1) / 2)
		{
			return rightCount;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}

}


int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < a.size(); ++i) {
		cin >> a[i];
	}
	cout << (get_majority_element(a, 0, a.size() - 1) != -1) << '\n';
}

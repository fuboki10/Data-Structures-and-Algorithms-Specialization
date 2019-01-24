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
int safe_max(int max ,int num)
{
    string a = to_string(max) + to_string(num);
    string b = to_string(num) + to_string(max);
    int i_a = stoi(a);
    int i_b = stoi(b);
    return (i_a) > (i_b) ? max : num;
}
int find_safe_max(std::vector<int> &num)
{
    int max = num[0];
    int max_index = 0;
    for (int j = 0; j < num.size(); ++j)
    {
        max = safe_max(max,num[j]);
        if (max == num[j]) max_index = j;
    }
    num.erase(num.begin() + max_index);
    return max;
}
int main()
{
    //freopen("simple.in", "r", stdin);
    int n;
    cin >> n;
    vector<int> nums;
    int num;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        nums.pb(num);
    }
    for (int i = 0; i < n; ++i)
    {
        int max = find_safe_max(nums);
        cout << max;
    }
    return 0;
}

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

bool partition(std::vector<int>& nums)
{
    int sum = 0;
    int n = nums.size();
    for (size_t i = 0; i < n; i++) {
        sum += nums[i];
    }
    if (sum % 3 != 0)
        return false;   // <3 <3 <3 love this case <3 <3 <3
    // the sad part :")
    std::vector<vector<bool>> dp(sum/3 + 1, vector<bool>(n + 1,false));
    for (size_t i = 0; i <= n; i++) {
        dp[0][i] = true;
    }
    for (size_t i = 1; i <= sum/3; i++) {
        for (size_t j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j-1];
            if (i >= nums[j - 1]) {
                dp[i][j] = dp[i][j] || dp[i - nums[j-1]][j-1];
            }
        }
    }

    return dp[sum/3][n];
}

int main()
{
    //freopen("simple.in", "r", stdin);
    int n;
    cin >> n;
    std::vector<int> nums(n);
    for (size_t i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << partition(nums) << endl;
    return 0;
}

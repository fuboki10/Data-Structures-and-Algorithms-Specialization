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

int Longest_Common(string a, string b, string c)
{
    int n,m,p;
    n = a.size();
    m = b.size();
    p = c.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(p + 1)));
    for (size_t i = 0; i <= n; i++) {
        for (size_t j = 0; j <= m; j++) {
            for (size_t k = 0; k <= p; k++) {
                if (i == 0 || j == 0 || k == 0) {
                    dp[i][j][k] = 0;
                }
                else if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else {
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
                }
            }
        }
    }
    return dp[n][m][p];
}


int main()
{
    //freopen("simple.in", "r", stdin);
    int n;
    string first = "",sec = "",third="";
    int t;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> t;
        first += t;
    }
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> t;
        sec += t;
    }
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> t;
        third += t;
    }
    cout << Longest_Common(first, sec, third) << endl;
    return 0;
}

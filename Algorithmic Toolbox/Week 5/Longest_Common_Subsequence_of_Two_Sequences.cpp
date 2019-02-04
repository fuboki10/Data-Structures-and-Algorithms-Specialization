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

int Longest_Common(string a, string b)
{
    int m = a.size();
    int n = b.size();
    std::vector< vector<int> > D(m + 1, vector<int>(n + 1));

    for (size_t i = 0; i <= m; i++) {
        for (size_t j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                D[i][j] = 0;
            }
            else if (a[i - 1] == b[j - 1]) {
                D[i][j] = D[i - 1][j - 1] + 1;
            }
            else {
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);
            }
        }
    }
    return D[m][n];
}

int main()
{
    //freopen("simple.in", "r", stdin);
    int m,n;
    cin >> n;
    string first = "",sec = "";
    int t;
    for (size_t i = 0; i < n; i++) {
        cin >> t;
        first += t;
    }
    cin >> m;
    for (size_t i = 0; i < m; i++) {
        cin >> t;
        sec += t;
    }
    cout << Longest_Common(first,sec) << '\n';
    return 0;
}

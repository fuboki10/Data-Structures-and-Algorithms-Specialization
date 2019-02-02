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

int editDistance(string a, string b)
{
    int m = a.size();
    int n = b.size();
    std::vector< vector<int> > D(m + 1, vector<int>(n + 1));

    for (size_t i = 0; i <= m; i++) {
        for (size_t j = 0; j <= n; j++) {
            if (i == 0) {
                D[i][j] = j;
            }
            else if (j == 0) {
                D[i][j] = i;
            }
            else if (a[i - 1] == b[j - 1]) {
                D[i][j] = D[i - 1][j - 1];
            }
            else {
                D[i][j] = 1 + min(D[i - 1][j], min(D[i][j - 1], D[i - 1][j - 1]));
            }
        }
    }
    return D[m][n];
}

int main()
{
    //freopen("simple.in", "r", stdin);
    string a,b;
    cin >> a;
    cin >> b;
    cout << editDistance(a,b) << endl;
    return 0;
}

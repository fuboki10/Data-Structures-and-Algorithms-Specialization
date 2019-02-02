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

int Knapsack(int W, int n, vector<int>& bars)
{
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    for (size_t i = 0; i <= n; i++) {
        for (size_t w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            }
            else if (bars[i - 1] <= w) {
                K[i][w] = max(bars[i - 1] + K[i - 1][w - bars[i - 1]], K[i - 1][w]);
            }
            else {
                K[i][w] = K[i - 1][w];
            }
        }
    }
    return K[n][W];
}

int main()
{
    //freopen("simple.in", "r", stdin);
    int W,n;
    cin >> W >> n;
    std::vector<int> bars(n);
    for (size_t i = 0; i < n; i++) {
        cin >> bars[i];
    }
    int sol = Knapsack(W, n, bars);
    cout << sol << endl;
    return 0;
}

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

int main()
{
    //freopen("simple.in", "r", stdin);
    int n;
    ll arr[200010];
    cin >> n;
    ll a;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        arr[i] = a;
    }
    sort(arr,arr + n);
    cout << arr[n-1] * arr[n-2] << endl;
    return 0;
}

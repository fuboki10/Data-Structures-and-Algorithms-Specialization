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

long long calc_fib(long long n) {

    n = (n+2)%60;
    ll first = 0;
    ll second = 1;
    ll res = 1;
    for (int i = 2; i <= n; ++i)
    {
        res = (first%10 + second%10)%10;
        first = second;
        second = res;
    }
    if (res == 0) return 9;

    return res%10 - 1;
}

int main()
{
    //freopen("simple.in", "r", stdin);
    ll n;
    cin >> n;

    cout << calc_fib(n) << endl;
    return 0;
}

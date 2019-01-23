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
bool asc(ll i,ll j)
{
    return i > j;
}
int main()
{
    //freopen("simple.in", "r", stdin);
    int n;
    cin >> n;
    vector<ll> num1,num2;
    ll num;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        num1.pb(num);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        num2.pb(num);
    }
    sort(all(num1),asc);
    sort(all(num2),asc);
    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += num1[i]*num2[i];
    }
    cout << sum << endl;
    return 0;
}

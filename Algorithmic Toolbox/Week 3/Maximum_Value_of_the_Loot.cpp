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
bool asc(pair<float ,int> p1,pair<float,int> p2)
{
    return p1.first > p2.first;
}
int main()
{
    //freopen("simple.in", "r", stdin);
    int n,w;
    cin >> n >> w;
    vector< pair<float,int> > items;
    int val,weight;
    for (int i = 0; i < n; ++i)
    {
        cin >> val >> weight;
        items.pb(mp(float(val)/weight,weight));
    }
    sort(all(items),asc);
    int i = 0;
    double sum= 0;
    while (w > 0 && i < n)
    {
        sum += items[i].first*min(w,items[i].second);
        w -= min(w,items[i].second);
        i += 1;
    }
    printf("%.3f",sum);
    return 0;
}

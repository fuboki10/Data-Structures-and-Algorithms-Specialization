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
bool sort_alg (pair<int,int> p1,pair<int,int> p2)
{
    return p1.second < p2.second;
}
int main()
{
    //freopen("simple.in", "r", stdin);
    int n;
    cin >> n;
    vector< pair<int,int> > segment;
    int start,end;
    for (int i = 0; i < n; ++i)
    {
        cin >> start >> end;
        segment.pb(mp(start,end));
    }
    set<int> points;
    sort(all(segment),sort_alg);
    int tmp_point = segment[0].second;
    for (int i = 1; i < n; ++i)
    {
        if (segment[i].first > tmp_point)
        {
            points.insert(tmp_point);
            tmp_point = segment[i].second;
        }
    }
    points.insert(tmp_point);
    cout << points.size() << endl;
    std::vector<int> v(all(points));
    sort(all(v));
    for (int i = 0; i < points.size(); ++i)
    {
        cout << v[i] << " ";
    }
    return 0;
}

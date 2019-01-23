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
    int m;
    cin >> m;
    int num = 0;
    while (m > 0)
    {
        if (m >= 10)
        {
            num++;
            m -= 10;
        }
        else if(m >= 5)
        {
            num++;
            m -= 5;
        }
        else
        {
            num++;
            m -=1;
        }
    }
    cout << num << endl;
    return 0;
}

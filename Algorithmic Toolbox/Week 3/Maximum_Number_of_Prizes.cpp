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

bool last_num(int i, int s)
{
    return i*2 >= s;
}

vector<int> optimal_summands(int n)
{
    vector<int> summand;
    for (int i = 1; i < n + 1; ++i)
    {
        if (last_num(i,n))
        {
            summand.pb(n);
            break;
        }
        summand.pb(i);
        n -= i;
    }
    return summand;
}


int main()
{
    //freopen("simple.in", "r", stdin);
    int n;
    cin >> n;
    std::vector<int> sol = optimal_summands(n);
    cout << sol.size() << endl;
    for (int i = 0; i < sol.size(); ++i)
    {
        cout << sol[i] << " ";
    }
    return 0;
}

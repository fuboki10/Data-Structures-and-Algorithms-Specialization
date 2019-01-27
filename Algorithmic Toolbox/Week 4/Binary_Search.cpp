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

int binarySearch(vector<ll> &arr,ll element)
{
    int l = 0;
    int r = arr.size() - 1;
    int mid;
    while (l <= r)
    {
        mid = l + (r - l)/2;
        if (arr[mid] == element)
            return mid;
        else if (arr[mid] < element)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}


int main()
{
    //freopen("simple.in", "r", stdin);
    int n;
    ll num;
    cin >> n;
    std::vector<ll> A(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        A[i] = num;
    }
    cin >> n;
    std::vector<ll> B(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        B[i] = num;
    }
    for (int i = 0; i < B.size(); ++i)
    {
        cout << binarySearch(A,B[i]) << " ";
    }
    return 0;
}

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

void prim_Calc(int num)
{
    std::vector<int> nums(num + 1,0);
    nums[0] = nums[1] = 1;
    int min1,min2,min3;
    for (size_t i = 2; i < num + 1; i++) {
        min2 = INT_MAX;
        min3 = INT_MAX;
        min1 = nums[i - 1];
        if (i % 3 == 0) {
            min3 = nums[i/3];
        }
        if (i % 2 == 0) {
            min2 = nums[i/2];
        }
        nums[i] = min(min1,min(min2,min3)) + 1;
    }
    // 2 , 2 , 3, 4
    std::vector<int> result;
    while (num > 0) {
        result.pb(num);
        if (num %2 == 0 && num %3 ==0) {
            num /= 3;
        }
        else if (num %2 == 0) {
            if (nums[num - 1] < nums[num/2]) {
                num -= 1;
            }
            else {
                num /= 2;
            }
        }
        else if (num %3 == 0) {
            if (nums[num - 1] < nums[num/3]) {
                num -= 1;
            }
            else {
                num /= 3;
            }
        }
        else {
            num -= 1;
        }
    }
    cout << result.size() - 1 << endl;
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}

int main()
{
    //freopen("simple.in", "r", stdin);
    int n;
    cin >> n;
    prim_Calc(n);
    return 0;
}

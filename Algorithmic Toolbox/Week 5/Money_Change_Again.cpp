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

int DPchange(int money,int coin[],int coin_size)
{
    std::vector<int> min_num(money + 1,INT_MAX);
    min_num[0] = 0;
    int min_coin;
    for (size_t i = 1; i < money + 1; i++) {
        for (size_t j = 0; j < coin_size; j++) {
            if (i >= coin[j]) {
                min_coin = min_num[i - coin[j]] + 1;
                if (min_coin < min_num[i]) {
                    min_num[i] = min_coin;
                }
            }
        }
    }
    return min_num[money];
}


int main()
{
    //freopen("simple.in", "r", stdin);
    int money;
    cin >> money;
    int coins[3] = {1,3,4};
    int Min_Num_Coins = DPchange(money, coins, 3);
    cout << Min_Num_Coins << endl;
    return 0;
}

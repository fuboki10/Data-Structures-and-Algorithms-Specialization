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


class StackWithMax {
    stack<int> st;

  public:

    void Push(int value) {
        if (st.empty()) {
            st.push(value);
        }
        else
        {
            if (value > st.top()) {
                st.push(value);
            }
            else
            {
                st.push(st.top());
            }
        }
    }

    void Pop() {
        st.pop();
    }

    int Max() const {
        return st.top();
    }
};



int main()
{
    int n;
    cin >> n;
    string fnc;
    StackWithMax st;
    int data;
    for (size_t i = 0; i < n; i++) {
        cin >> fnc;
        if (fnc == "push") {
            cin >> data;
            st.Push(data);
        }
        else if (fnc == "max") {
            cout << st.Max() << '\n';
        }
        else if (fnc == "pop") {
            st.Pop();
        }
    }
    return 0;
}

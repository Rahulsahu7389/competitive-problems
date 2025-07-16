#include <bits/stdc++.h>
using namespace std;

#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORLL(a, c) for (long long(a) = 0; (a) < (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define pb push_back
#define pob pop_back
ll MOD = 1e9 + 7;

template <typename T>
T mod(T a)
{
    if (a < 0)
        return -a;
    return a;
}

template <typename T>
T power(T x, T n)
{
    T pro = 1;
    while (n != 0)
    {
        if (n % 2 == 1)
        {
            pro *= x;
        }
        x *= x;
        n /= 2;
    }
    return pro;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    stack<char> st;
    for (char c : s)
    {
        if (st.size() >= 2)
        {
            char second = st.top();
            st.pop();
            char first = st.top();
            st.pop();
            if (first != second && second != c)
            {
                st.push(first);
                st.push(c);
                continue;
            }
            else
            {

                st.push(first);
                st.push(second);
                st.push(c);
            }
        }
        else
        {
            st.push(c);
        }
    }

    cout << st.size() << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
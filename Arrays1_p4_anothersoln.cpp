#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define ull unsigned long long
#define sz(x) x.size()
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) x.begin(), x.end()
#define vi vector<ll>
#define mat vector<vi>
#define pii pair<ll, ll>
#define vii vector<pii>
#define vc vector<char>
#define pcc pair<char, char>
#define vcc vector<pcc>
#define loop(i, a, b) for (ll i = a; i < b; i++)
#define rloop(i, b, a) for (ll i = b; i >= a; i--)
#define fir(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define ff first
#define ss second
#define nl "\n"
#define sp " "
#define uo unordered_set<ll>
#define os set<ll>
const ll z = 1e9 + 7;
const ll mod = 998244353;

int usingdvc(vi &arr, ll l, ll r)
{
    // cout<<"called for "<<l<<sp<<r<<nl;
    // loop(i,l,r+1){
        // cout<<arr[i]<<sp;
    // }
    // cout<<nl;
    if (l == r)
    {
        return arr[l];
    }
    ll mid = (l + r) >> 1;
    // cout<<"mid is "<<mid<<nl;
    ll maxinleft = usingdvc(arr, l, mid);
    ll maxinright = usingdvc(arr, mid + 1, r);
    ll maxinmiddle = arr[mid];
    ll bestpossibleinleft = arr[mid--];
    while (l <= mid)
    {
        bestpossibleinleft += arr[mid];
        maxinmiddle = max(maxinmiddle, bestpossibleinleft);
        mid--;
    }
    mid = ((l + r) >> 1) + 1;
    ll maxinmiddlefr = arr[mid];
    ll bestpossibleinright = arr[mid++];
    while (mid <= r)
    {
        bestpossibleinright += arr[mid];
        maxinmiddlefr = max(maxinmiddlefr,bestpossibleinright);
        mid++;
    }
    // cout<<"all three values are "<<maxinleft<<sp<<maxinright<<sp<<maxinmiddle<<sp<<maxinmiddlefr<<nl;
    return max(maxinleft, max(maxinright, maxinmiddle+maxinmiddlefr));
}

int main()
{
    vi arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << usingdvc(arr, 0, sz(arr) - 1);
    return 0;
}

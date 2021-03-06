/* You can't connect the dots looking forward 
   you can only connect them looking backwards. */

#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cout.precision(10);cout << fixed;
#define dbset(x) for(int i=0 ; i<x.size(); i++) cerr << x[i] << " "; cerr << endl;
#define inf 1000000007
#define INF 1000000000000000000LL
#define PI 3.14159265358979323846
#define mod 1000000007
#define mod1 1000696969
#define flusz fflush(stdout);
#define VI vector<int>
#define VPI vector < pair<int,int> >
#define PII pair<int, int>
#define BIT bitset<N>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
#define FORR(x, y, z) for(int x = y; x >= (z); --x)
using namespace std;

template<class TH> void _dbg(const char *sdbg, TH h){cerr<<sdbg<<"="<<h<<"\n";}
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<"="<<h<<","; _dbg(sdbg+1, a...);
}
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

#define N 1000007
#define int long long

int test;

int n;

int hasz[N];

int pot[N];

string s;

void solve()
{
    cin >> s;

    n = s.length();
    s = "#" + s;

    pot[0] = 1;

    FOR(i,1,n){
        hasz[i] = (hasz[i-1] + s[i] - 'a' + 1) * 27;
        hasz[i] %= mod;

        pot[i] = pot[i-1] * 27;
        pot[i] %= mod;
    }

    int res = 0;
    int len = 1,last = n;

    FOR(i,1,n/2){
        int tmp1 = hasz[i] - ( (hasz[i-len] * pot[len]) % mod ) ;
        tmp1 += mod; tmp1 %= mod;

        int tmp2 = hasz[last] - ( (hasz[last - len] * pot[len]) % mod );
        tmp2 += mod; tmp2 %= mod;

        if (tmp1 == tmp2){
            res+=2; last = last - len; len = 1;
        }else{
            len++;
        }
    }

    if (len>1 || n%2==1){
        res++;
    }

    cout << res << endl;

    return;
}

int32_t main()
{
    boost

    cin >> test;

    while(test--)
    {
        solve();
    }

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ull unsigned long long
#define ll long long 
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define pb push_back
#define fast_cin()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);

const int mod = 1e9+7;

// int maxx = INT_MIN; //for storing the max count
//this is where the recursion happens 

ll getHash(string &str)
{
    ll h = 0;
    for(char ch : str)  h = (h*31 + (ch-'a'+1))%mod;
    return h;
    // we have take 31 as we take prime number so as there are no common divisors
    // the hash formula here is h(s) = E(ch-'a'+1)*31^ind       E->Sigma
    // as the 31^ could be very large we take mod
    // 1e9+7 is popular could its mod provides us a range of 0 to mod-1 which is quite large
    //  and it needs to be prime to avoid divisors
}

void solve() 
{
    string str;
    cin>>str;

    ll hashed = getHash(str);
    cout<<hashed<<endl;

}



int32_t main()
{
    fast_cin();
    // int t;
    // cin>>t;`
    // t=1;

    // while(t--)
    solve();
    
    return 0;
}

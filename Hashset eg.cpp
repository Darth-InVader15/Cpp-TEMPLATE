#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast_cin()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);

    int main()
    {
       long long s1, s2, s3, s4;
       cin>>s1>>s2>>s3>>s4;
        int count =0;

        unordered_set<int> hashset;
        hashset.insert(s1);
        hashset.insert(s2);
        hashset.insert(s3);
        hashset.insert(s4);
        
        cout<<(4-hashset.size());



        return 0;
    }

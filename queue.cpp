#include <bits/stdc++.h>
using namespace std;
#define fast_cin()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);
// queue = FIFO

int32_t main()
{
    queue<int> qu;
    int n;
    cin>>n;
    int l = n;
    while(n--)
    {
        int temp;
        cin>>temp;
        qu.push(temp);
    }
    while(l--)
    {
        cout<<qu.front();
        qu.pop();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ull unsigned long long
#define ll long long 
#define forn(n) for (int i = 0; i < int(n); i++)
#define pb push_back
#define fast_cin()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);

int mod = 1e9+7;

struct node
{
	int sum;
	node()
	{
		sum = 0;
	}
};

node merge(node a, node b)
{
	node ans;
	ans.sum = a.sum + b.sum;
	return ans;
}

node t[4*200200]; //hmesa size k 4 times lete hai, kyuki perfectly balanced tree nhi banta 

void build(int id, int l, int r)
{
	if(l==r)
	{
		//leaf node
		t[id].sum = 0;
		return;
	}
	int mid = (l+r)/2;
	build(2*id,l,mid);
	build(2*id +1,mid+1,r);
	t[id] = merge(t[2*id],t[2*id +1]);
}

void update(int id, int l, int r, int pos, int val)
{
	if(pos<l || pos>r)	return; //if not in range
	if(l==r)
	{
		//leaf node
		t[id].sum += val;
		return;
	}
	int mid = (l+r)/2;
	update(2*id,l,mid,pos,val);
	update(2*id+1,mid+1,r,pos,val);
	t[id] = merge(t[2*id],t[2*id+1]);
}
node query(int id, int l, int r, int lq, int rq)
{
	if(lq>r || l>rq)	return node();	//node() basically returns node with ele 0, it is diff for diff questions

	if(lq<= l && r<=rq)	return t[id]; //in this ques we need prefix sum for a given range hence we are returning t[id]
	//for diff logic this part will change
	int mid = (l+r)/2;
	return merge(query(2*id,l,mid,lq,rq),query(2*id+1,mid+1,r,lq,rq));



}

//This code is the solution for CSES 1651 Range Update Queries
//A similar code came in a LC contest, i solved using array with same approach
//here rather than a array we use segment tree
//querying and updating both takes logn time


int32_t main()
{
	fast_cin();

	int n;
	cin>>n>>q;

	int arr[n];

	forn(n){
		cin>>arr[i];
	}

	build(1,0,n-1); //build a 0 indexed segment tree

	while(q--)
	{
		int ch;
		cin>>ch;
		if(ch == 1)
		{
			int a,b,u;
			cin>>a>>b>>u;
			a--;b--;//convert to 0 index

			update(1,0,n-1,a,u);
			update(1,0,n-1,b+1,-u);
		}
		else{
			int k;
			cin>>k;
			k--;//converted to 0 index

			node ans = query(1,0,n-1,0,k);
			cout<<ans.sum + arr[k]<<endl;
		}
	}

}
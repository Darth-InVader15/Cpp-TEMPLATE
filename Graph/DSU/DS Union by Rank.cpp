class DisjointSet {
    vector<int> parent, rank;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);

        for(int i=0;i<=n;i++)    parent[i] = i; //initially sab khud ka parent hai ie no edges
    }

    int findUltimateParent(int node)
    {
        if(node == parent[node])    return node;
        return findUltimateParent(parent[node]);
        //Path Compression
        //if we dont do this then traversal will be log n, this makes it almost constant
        //Basically if the graph is like 1<-2<-3 : this line makes each node point to its ultimate parent directly
        // like 3->1<-2, so next traversal would be constant time
        //kinda like memoizing the uparent
        // return parent[node] = findUltimateParent(parent[node]);
    }

    void UnionByRank(int u, int v)
    {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);

        if(pu == pv)    return; //both are already connected components

        int ranku = rank[pu], rankv = rank[pv];
        if(ranku == rankv) //this case mein dono ultimate parents k level same hai, so kisi ko kisi m chipaka do
        {
            parent[pv] = pu;
            rank[pu]++; 
            //suppose dono k rank 2 the yaani 1->2->3 , 4->5->6 iss type ka structure hoga
            //then if we stick 4 to 1, as 4,5,6 = 3 ele, rank of 1 becomes 3
            //it will always increase by only 1 coz dono k rank same the initially
        }
        else
        {
            if(ranku > rankv) //pv will attach to pu
            {
                parent[pv] = pu;
            }
            else
            {
                parent[pu] = pv;
            }
        }
    }
};
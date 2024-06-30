class DisjointSet{
    vector<int> siz, parent;
    public:
    DisjointSet(int n){
        siz.resize(n+1,1); //the size is basically the tot no of nodes under this node, initially it just has itself
        parent.resize(n+1);

        for(int i=0;i<=n;i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if(node == parent[node])    return node;
        return parent[node] = findUPar(node); //path compression
    }

    void unionBySize(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(pu == pv)    return;

        if(siz[pu] >= siz[pv])
        {
            parent[pv] = pu;
            siz[pu] += siz[pv];
        }
        else
        {
            parent[pu] = pv;
            siz[pv] += pu;
        }
    }

};
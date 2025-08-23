class disjointset{
    vector<int>rank,parent;
    public:
    disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)parent[i]=i;

    }
    int findparent(int u){
        if(u==parent[u])return u;
        return parent[u]=findparent(parent[u]);
    }
    void unionbyrank(int u,int v){
        int ulp_u=findparent(u);
        int ulp_v=findparent(v);
        if(ulp_u==ulp_v)return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=parent[ulp_v];

        }
        else
        if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=parent[ulp_u];
        }
        else
        {
            parent[ulp_v]=parent[ulp_u];
            rank[ulp_u]++;
        }
    }


};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>>res;
        map<string,int>m;
        int n=accounts.size();
        disjointset ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++)
            {
                if(m.find(accounts[i][j])==m.end()){
                    m[accounts[i][j]]=i;
                }
                else
                {
                    ds.unionbyrank(i,m[accounts[i][j]]);
                }
            }
        }
        vector<string>str[n];
        for(auto i:m){
            string st=i.first;
            int node=i.second;
            str[ds.findparent(node)].push_back(st);
        }
        for(int i=0;i<n;i++){
            
            if(str[i].size()==0)continue;
            sort(str[i].begin(),str[i].end());
            vector<string>cur;
            cur.push_back(accounts[i][0]);
            for(auto i:str[i])cur.push_back(i);
            res.push_back(cur);
        }

return res;

    }
};
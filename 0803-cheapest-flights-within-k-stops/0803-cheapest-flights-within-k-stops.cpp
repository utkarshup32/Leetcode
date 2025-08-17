class Solution 
{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int,int>>>adjls(n);

        for(int i=0;i<flights.size();i++)
        {
            adjls[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        vector<int>dist(n,INT_MAX);
        dist[src]=0;

        queue<pair<int,pair<int,int>>>q; //stops,node,dist
        q.push({0,{src,0}});

        while(!q.empty())
        {
            int stops=q.front().first;
            int node=q.front().second.first;
            int dt=q.front().second.second;

            q.pop();

            for(auto itr:adjls[node])
            {
                int adjnode=itr.first;
                int moredt=itr.second;

                if(dt+moredt<dist[adjnode] && stops+1<=k+1)
                {
                    dist[adjnode]=dt+moredt;
                    q.push({stops+1,{adjnode,dt+moredt}});
                }
            }

        }
        return dist[dst]==INT_MAX ? -1 : dist[dst];
    }
};
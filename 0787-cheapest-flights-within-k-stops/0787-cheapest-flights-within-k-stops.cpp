class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            vector<vector<pair<int,int>>>adj(n);
            for(int i=0;i<flights.size();i++){
                int sc=flights[i][0];
                int des=flights[i][1];
                int wt=flights[i][2];
                adj[sc].push_back({des,wt});
            };
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
            pq.push({0,{src,0}});
            vector<int> stops(n, INT_MAX);
            while(!pq.empty() ){
                pair<int,pair<int,int>>p=pq.top();
                pq.pop();
                int cost=p.first;
                int node=p.second.first;
                int stop=p.second.second;
                if (stop > k + 1)
                continue;

                if (stop > stops[node])continue;
                stops[node]=stop;
                if(node==dst){
                    return cost;
                }
                for(int i=0;i<adj[node].size();i++){
                    int nbr=adj[node][i].first;
                    int nxtcost=adj[node][i].second;
                    pq.push({cost+nxtcost,{nbr,stop+1}});
                }

            }
            return -1;


        }
        
                
                        
                            
};
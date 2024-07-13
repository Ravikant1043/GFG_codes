//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

typedef pair<int,int> p;
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<p> adj[n+1];
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        vector<int> par(n+1,-1),dis(n+1,1e9);
        vector<bool> vis(n+1,false);
        dis[1]=0;
        priority_queue<p,vector<p>,greater<p>> pq;
        
        pq.push({0,1});
        
        while(pq.size()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int val=it.first;
            
            // cout<<node<<"\n";
            
            vis[node]=true;
            if(node==n)break;
            
            for(auto t:adj[node]){
                if(!vis[t.first] && dis[t.first]>dis[node]+t.second){
                    dis[t.first]=dis[node]+t.second;
                    pq.push({dis[t.first],t.first});
                    par[t.first]=node;
                }
            }
        }
        // cout<<dis[n]<<"\n";
        // return {dis[n]};
        if(dis[n]==(int)1e9)return {-1};
        vector<int> ans;
        ans.push_back(n);
        int p=par[n];
        while(p!=-1){
            ans.push_back(p);
            p=par[p];
        }
        // ans.push_back(1);
        ans.push_back(dis[n]);
        reverse(ans.begin(),ans.end());
        // for(auto it:ans)cout<<it<<" ";
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends
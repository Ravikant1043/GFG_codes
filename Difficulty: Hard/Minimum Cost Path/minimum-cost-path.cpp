//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    int d[2]={0,1};
	int dd[4]={-1,1,0,0};
    public:
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        vector<vector<int>>help(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
                greater<pair<int,pair<int,int>>> >q;
        q.push({grid[0][0],{0,0}});
        help[0][0]=grid[0][0];
        while(!q.empty()){
            int a=q.top().first;
            int i=q.top().second.first;
            int j=q.top().second.second;
            q.pop();
            if(i==n-1 && j==n-1)return a;
            for(int p=0;p<4;p++){
                int ni=i+dd[p];
                int nj=j+dd[4-p-1];
                if(ni>=0 && nj>=0 && ni<n && nj<n && help[ni][nj]>grid[ni][nj]+a){
                    help[ni][nj]=grid[ni][nj]+a;
                    q.push({help[ni][nj],{ni,nj}});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
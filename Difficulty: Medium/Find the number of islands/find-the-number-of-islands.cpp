//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        void dfs(vector<vector<char>>&grid ,int i, int j,int n,int m){
            queue<pair<int,int>>q;
            q.push({i,j});
            grid[i][j]='2';
            
            while(!q.empty()){
                int fi=q.front().first;
                int se=q.front().second;
                q.pop();
                for(int ii=-1;ii<2;ii++){
                    for(int jj=-1;jj<2;jj++){
                        if(fi+ii>=0 && fi+ii<n && se+jj>=0 && se+jj<m && 
                        grid[fi+ii][se+jj]=='1'){
                            grid[fi+ii][se+jj]='2';
                            q.push({fi+ii,se+jj});
                        }
                    }
                }
            }
        }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(),s=0;
        int m=grid[0].size();
        // vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,n,m);
                    s++;
                }
            }
        }
        return s;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
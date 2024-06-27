//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToepliz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToepliz(a);

        if (b == true)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



bool isToepliz(vector<vector<int>>& mat) {
    int n=mat.size();
    int m=mat[0].size();
    for(int i=0;i<n;i++){
        int ni=i,nj=0;
        int t=mat[ni][nj];
        while(ni<n&&nj<m){
            if(t!=mat[ni][nj])return false;
            ni++,nj++;
        }
    }
    for(int i=0;i<m;i++){
        int ni=0,nj=i;
        int t=mat[ni][nj];
        while(ni<n&&nj<m){
            if(t!=mat[ni][nj])return false;
            ni++,nj++;
        }
    }
    return true;
}
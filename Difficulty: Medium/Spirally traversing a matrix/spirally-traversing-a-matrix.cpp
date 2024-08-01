//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        // int 
         vector<int> t;
        int r=0,l=0,re=matrix.size()-1,le=matrix[0].size()-1;
        while(r<=re&&l<=le){
            for(int i=l;i<=le;i++)
                t.push_back(matrix[r][i]);
            r++;
            for(int i=r;i<=re;i++)
                t.push_back(matrix[i][le]);
            le--;
            if(r<=re){
            for(int i=le;i>=l;i--){
                t.push_back(matrix[re][i]);
            }}
            re--;
            if(l<=le){
            for(int i=re;i>=r;i--)
                t.push_back(matrix[i][l]);}
            l++;
        }
        return t;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
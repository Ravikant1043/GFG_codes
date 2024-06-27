//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        
        int n=arr.size();
        int m=arr[0].size();
        for(int i=0;i<n;i++){
            int l=0,h=m-1;
            while(l<h){
                if(arr[i][l]==arr[i][h]){
                    l++;
                    h--;
                }else break;
            }
            if(l>=h){
                return to_string(i)+" R";
            }
        }
        for(int i=0;i<m;i++){
            int l=0,h=n-1;
            while(l<h){
                if(arr[l][i]==arr[h][i]){
                    l++;
                    h--;
                }else break;
            }
            if(l>=h){
                return to_string(i)+" C";
            }
        }
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends
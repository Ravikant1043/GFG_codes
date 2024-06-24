//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef long long ll;
class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
        ll right=2+n-1;
        if(q>right+n-1)return 0;
        if(q<=right){
            return q-1;
        }
        else{
            return n-(q-right);
        }
        return 0;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,q;
        
        cin>>n>>q;

        Solution ob;
        cout << ob.sumMatrix(n,q) << endl;
    }
    return 0;
}
// } Driver Code Ends
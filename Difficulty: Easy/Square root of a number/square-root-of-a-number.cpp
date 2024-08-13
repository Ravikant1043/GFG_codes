//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long i=1,t=x,m;
        while(1){
            m=(i+t)/2;
            if(i>t)return m;
            if(m*m==x)return m;
            else if(m*m>x) t=m-1;
            else i=m+1;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
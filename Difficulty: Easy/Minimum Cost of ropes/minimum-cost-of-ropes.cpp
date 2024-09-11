//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

typedef long long ll;
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        int n=arr.size();
        priority_queue<ll, vector<ll>, greater<ll> >t;
        for(int i=0;i<n;i++){
            t.push(arr[i]);
        }
        ll k=0;
        while(t.size()!=1){
            ll a=t.top();
            t.pop();
            a+=t.top();
            t.pop();
            k+=a;
            t.push(a);
        }
        return k;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends
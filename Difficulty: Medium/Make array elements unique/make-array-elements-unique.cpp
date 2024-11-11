//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        unordered_set<int> mp;
        sort(arr.begin(),arr.end());
        int ans=0;
        int tp=0;
        for(auto it:arr){
            tp=max(it,tp);
            if(mp.count(it)){
                ans+=tp+1-it;
                tp++;
                mp.insert(tp);
            }
            else{
                mp.insert(it);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
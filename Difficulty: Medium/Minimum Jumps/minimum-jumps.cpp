//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 0;
        if(arr[0] == 0) return -1;
        int count=0,j=0,t=0;
        for(int i=0;i<n-1;i++){
            t=max(t,arr[i]+i);
            if(j==i){
                if(i==t)return -1;
                j=t;
                count++;
            }
        }
        return t<n-1?-1:count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends
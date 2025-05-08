//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        int n=arr.size(),f;
        if(arr[0]<arr[1])
            f=min(arr[1]-arr[0],arr[n-1]-arr[n-2]);
        else
            f=max(arr[1]-arr[0],arr[n-1]-arr[n-2]);
        if(n==2)return 2*(f)+arr[0];
        for(int i=0;i<n;i++){
            if(f*i + arr[0] != arr[i])return f*i + arr[0];
        }
        return f*n +arr[0];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2) {
    int m = v2.size();
    int n = v1.size();
    int j = 0; // For index of v2

    // Traverse v1 and v2
    for (int i = 0; i < n && j < m; i++) {
        if (v1[i] == v2[j]) {
            j++;
        }
    }
    return (j == m);
}


// } Driver Code Ends
/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
class Solution{
  public:
  void help(int a,int b,int c,vector<int>&arr,int i){
      if(i>=arr.size())return ;
      if(c!=-1)return ;
      if(a==-1){
          
      }
  }
    vector<int> find3Numbers(vector<int> arr) {
        int n=arr.size();
        vector<int>a(n,-1),b(n,-1);
        int t=arr[0];
        for(int i=0;i<n;i++){
            if(t<arr[i])a[i]=t;
            t=min(t,arr[i]);
        }
        t=arr[n-1];
        for(int i=n-1;i>=0;i--){
            if(t>arr[i])b[i]=t;
            t=max(t,arr[i]);
        }
        for(int i=1;i<n-1;i++){
            if(a[i]!=-1 && b[i]!=-1)return {a[i],arr[i],b[i]};
        }
        return {};
    }
};


//{ Driver Code Starts.

// Driver program to test above function
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
        int n = arr.size();
        Solution obj;
        auto res = obj.find3Numbers(arr);
        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and isSubSequence(arr, res)) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMaxDiff(vector<int> &arr) {
        int n=arr.size();
        vector<int> left(n,0),right(n,0);
        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(st.size() && arr[st.top()]>=arr[i])st.pop();
            if(st.size())left[i]=arr[st.top()];
            st.push(i);
        }
        while(st.size())st.pop();
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size() && arr[st.top()]>=arr[i])st.pop();
            if(st.size())right[i]=arr[st.top()];
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)ans=max(ans,abs(left[i]-right[i]));
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends
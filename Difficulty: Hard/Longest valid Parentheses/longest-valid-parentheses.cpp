//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& s) {
        int ans=0;
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push(i);
            else{
                if(!st.empty() && s[st.top()]=='('){
                    st.pop();
                    ans=max(ans, i-(st.size()?st.top():-1));
                }
                else st.push(i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends
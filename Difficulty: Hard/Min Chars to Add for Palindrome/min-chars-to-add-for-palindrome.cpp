//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        string rev = s; 
        reverse(rev.begin(), rev.end()); 
        string complete = s + '$' + rev; 

        int n = complete.length();
        int i = 0, j = 1;
        vector<int> helperArr(n, 0); 

      
        while (j < n) {
            if (complete[i] == complete[j]) {
                helperArr[j++] = ++i; 
            } else if (i != 0) {
                i = helperArr[i - 1]; 
            } else {
                j++; 
            }
        }

        int longest_palindrome_suffix = helperArr[n - 1];
        return s.length() - longest_palindrome_suffix;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
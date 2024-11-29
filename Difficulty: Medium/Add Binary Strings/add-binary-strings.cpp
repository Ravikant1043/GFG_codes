//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        string ans="";
        int n=s1.size()-1;
        int m=s2.size()-1;
        int c=0;
        while(n>=0 && m>=0){
            if(s1[n]=='1' && s2[m]=='1'){
                if(c){
                    ans+="1";
                }
                else{
                    ans+="0";c=1;
                }
            }
            else if(s1[n]=='1' || s2[m]=='1'){
                if(c){
                    ans+="0";
                }else ans+="1";
            }
            else{
                if(c)ans+="1",c=0;
                else ans+="0";
            }
            n--,m--;
        }
        while(n>=0){
            if(s1[n]=='1'){
                if(c)ans+="0";
                else ans+="1";
            }
            else{
                if(c)ans+="1",c=0;
                else ans+="0";
            }
            n--;
        }
        while(m>=0){
            if(s2[m]=='1'){
                if(c)ans+="0";
                else ans+="1";
            }
            else{
                if(c)ans+="1",c=0;
                else ans+="0";
            }
            m--;
        }
        if(c)ans+="1";
        int i=0;
        reverse(ans.begin(),ans.end());
        while(i<ans.size() && ans[i]=='0')i++;
        ans=ans.substr(i);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
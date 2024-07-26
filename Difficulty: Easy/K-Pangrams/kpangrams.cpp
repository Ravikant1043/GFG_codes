//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        unordered_map<char,int> m;
        int t=0;
        for(auto it:str){
            if(it>='a' && it<='z')t++,m[it]++;
        }
        // cout<<t<<" "<<m.size()<<" ";
        if(t<26)return false;
        if(m.size()==26 || 26-m.size()<=k)return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends
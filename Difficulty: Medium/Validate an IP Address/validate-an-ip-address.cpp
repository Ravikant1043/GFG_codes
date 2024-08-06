//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
  public:
    int isValid(string str) {
        str+=".";
        int c=0;
        bool ch=false;
        int count=0;
        for(auto it:str){
            if(it=='.'){
                if(!ch || (c<0 || c>255))return false;
                c=0;
                count++;
            }
            else{
                ch=true;
                c=c*10 + (it-'0');
            }
        }
        if(count>4)return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    string smallestWindow (string s, string p)
    {
        string res="";
        pair<int,int> pt;
        vector<int> v(26,0);
        for(auto i:p)v[i-'a']++;
        vector<int> u(26,0);
        auto check=[&](){
            for(int i=0;i<26;i++){
                if(v[i]>u[i])return false;
            }
            return true;
        };
        int i=0,j=0;
        int n=s.size();
        int ans=n+1;
        while(j<n){
            u[s[j]-'a']++;
            while(check()){
                if(ans>j-i+1){
                    ans=j-i+1;
                    pt={i,j};
                }
                u[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return  ans==n+1?"-1":s.substr(pt.first,pt.second-pt.first+1);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
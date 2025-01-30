//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isRepeat(string s)
	{
	    int n=s.size();
	    vector<int> a(n,0);
	    int j;
	    for(int i=1;i<n;i++){
	        j=a[i-1];
	        while(j>0 && s[i]!=s[j])j=a[j-1];
	        if(s[i]==s[j])j++;
	        a[i]=j;
	    }
	   // for(auto it:a)cout<<it<<" ";
	   // return 1;
	   return ((n%(n-a[n-1])==0) && a[n-1]>0);
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends
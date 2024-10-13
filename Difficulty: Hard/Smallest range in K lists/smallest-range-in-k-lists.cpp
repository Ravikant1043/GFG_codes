//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    typedef pair<int,pair<int,int>> pp;
    pair<int,int> findSmallestRange(int ka[][N], int n, int k)
    {
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        int mi=INT_MAX;
        int ma=INT_MIN;
        for(int i=0;i<k;i++){
            pq.push({ka[i][0],{i,0}});
            mi=min(mi,ka[i][0]);
            ma=max(ma,ka[i][0]);
        }
        // int range=ka[k-1][n-1]-ka[0][0];
        int range=ma-mi;
        int h=ma,l=mi;
        while(!pq.empty()){
            int val=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            
            if(range>ma-val){
                mi=val;
                range=ma-val;
                l=mi;
                h=ma;
            }
            
            if(col==n-1){break;}
            
            pq.push({ka[row][col+1],{row,col+1}});
            ma=max(ma,ka[row][col+1]);
        }
        return {l,h};
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


//  } Driver Code Ends
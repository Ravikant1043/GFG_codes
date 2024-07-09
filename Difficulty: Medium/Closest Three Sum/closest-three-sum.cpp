//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        int ans=1e9,res=-1e9;
        int n=arr.size();
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];
                // cout<<sum<<" ";
                // if(sum==target)return target;
                if(sum>=target){
                    ans=min(ans,sum);
                    k--;
                }
                else{
                    res=max(res,sum);
                    j++;
                }
            }
        }
        if(res==-1e9 && ans==1e9)return -1;
        if(res==-1e9)return ans;
        if(ans==1e9)return res;
        int dif=abs(res-target);
        int dif2=abs(ans-target);
        
        return dif<dif2?res:ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends
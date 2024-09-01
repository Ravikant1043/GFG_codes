//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    int N,M;
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        N=arr1.size();
        M=arr2.size();
        
        int ans=0;
        int i=0,j=0;
        int s1=0,s2=0;
        while(i<N && j<M){
            if(arr1[i]==arr2[j]){
                ans+=max(s1,s2)+arr1[i];
                i++;
                j++;
                s1=0,s2=0;
            }
            else if(arr1[i]<arr2[j])s1+=arr1[i++];
            else s2+=arr2[j++];
        }
        while(i<N)s1+=arr1[i++];
        while(j<M)s2+=arr2[j++];
        return max(s1,s2)+ans;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        int n=arr.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)mp[arr[i]]++;
        vector<pair<int,int>>ans1;
        for(auto &i:mp)ans1.push_back({i.first,i.second});
        sort(ans1.begin(),ans1.end(),[](pair<int,int>&a,pair<int,int>&b){
            if(a.second==b.second)return a.first<b.first;
            return a.second>b.second;
        });
        vector<int>ans;
        for(int i=0;i<ans1.size();i++){
            int a=ans1[i].first,b=ans1[i].second;
            while(b--)ans.push_back(a);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
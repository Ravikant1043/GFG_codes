// User function template for C++
class Solution {
  public:
    int ans=0;
    int l=-1,r=-1;
    int n;
    void help(int ind,vector<int>&arr){
        if(ind>=n)return;
        int s=0;
        int i=ind;
        for(;i<n;i++){
            if(arr[i]<0)break;
            s+=arr[i];
        }
        if(s>ans){
            l=ind,r=i-1;
            ans=s;
        }
        while(i<n && arr[i]<0){
            i++;
        }
        help(i,arr);
    }
    vector<int> findSubarray(vector<int>& arr) {
        n=arr.size();
        help(0,arr);
        vector<int> v={arr.begin()+l,arr.begin()+r+1};
        if(l==-1 && r==-1){
            v={-1};
        }
        return v;
    }
};
class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        vector<pair<int,int>> v;
        int n=a.size();
        for(int i=0;i<n;i++)v.push_back({a[i],i});
        sort(b.begin(),b.end());
        sort(v.begin(),v.end());
        int i=0,j=0;
        for(;i<n;i++){
            for(;j<b.size();j++){
                if(b[j]>v[i].first)break;
            }
            v[i].first = j;
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++)ans[v[i].second] = v[i].first;
        return ans;
    }
};
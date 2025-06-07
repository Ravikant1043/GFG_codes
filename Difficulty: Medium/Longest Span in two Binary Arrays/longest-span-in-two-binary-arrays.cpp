class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        map<int,int> m;
        m[0]=-1;
        int ans=0,l=0,r=0;
        for(int i=0;i<a1.size();i++){
            l+=a1[i];
            r+=a2[i];
            if(m.count(l-r)){
                ans=max(ans,i-(m[l-r]));
            }
            else m[l-r]=i;
        }
        return ans;
    }
};
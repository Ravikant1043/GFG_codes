class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        priority_queue<int> l;
        priority_queue<int,vector<int>,greater<int>> u;
        for(auto it:arr){
            if(it<x)l.push(it);
            else if(it>x)u.push(it);
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            int ll = INT_MIN;
            int uu = INT_MAX;
            if(l.size())ll=l.top();
            if(u.size())uu=u.top();
            if(abs(x-uu)<=abs(x-ll)){
                ans.push_back(uu);
                u.pop();
            }
            else{
                ans.push_back(ll);
                l.pop();
            }
        }
        return ans;
    }
};
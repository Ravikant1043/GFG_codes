class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        stack<int> st;
        for(int i=0;i<color.size();i++){
            if(st.size()){
                int t=st.top();
                if(color[i]==color[t] && radius[i]==radius[t])
                    st.pop();
                else st.push(i);
            }
            else st.push(i);
            
        }
        return st.size();
    }
};
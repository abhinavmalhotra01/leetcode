class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j=0;
        for(int i=0;i<pushed.size();i++){
            if(!st.empty() && st.top()==popped[j]){
                while(!st.empty() && j<popped.size() && st.top()==popped[j] ){
                    st.pop();
                    j++;
                }
            }
            st.push(pushed[i]);
        }
        if(!st.empty()&&st.top()==popped[j]){
                while(!st.empty() && j<popped.size() && st.top()==popped[j] ){
                    st.pop();
                    j++;
                }
            }
        return st.empty();
    }
};
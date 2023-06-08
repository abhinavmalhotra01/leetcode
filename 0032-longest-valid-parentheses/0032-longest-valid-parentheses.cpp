class Solution {
public:
    int longestValidParentheses(string s)
    {
        stack<int>st;
        st.push(-1);
        int maxi=0;
        for(int i =0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else 
            {
                st.pop();
                if(st.empty())
                {
                    // cout<<"a"<<endl;
                    st.push(i);
                }
                else
                {
                    // cout<<i<<endl;
                    // cout<<i<<" "<<i-st.top()<<endl;
                    int curr = i-st.top();
                    maxi=max(maxi,curr);
                }
            } 
        }
        return maxi;
    }
};
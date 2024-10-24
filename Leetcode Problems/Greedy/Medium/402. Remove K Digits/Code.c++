class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char>st;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                while(!st.empty() and k>0 and st.top()>s[i])
                {
                    k--;
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty() and k>0){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.length();i++){
            if(ans[i]!='0'){
                return ans.substr(i,s.length());
            }
        }
        return "0";
    }
};

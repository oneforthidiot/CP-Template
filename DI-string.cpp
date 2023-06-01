class Solution {
public:
    string smallestNumber(string pattern) {
        stack<char> st;
        int n=pattern.size();
        string ans="";
        if(pattern[0]=='I')ans+='1';
        else st.push('1');
        for(int i=1;i<=n;i++){
            if(pattern[i-1]=='I'){
                while(st.size()){
                    ans+=st.top();
                    st.pop();
                }
            }
            st.push(char('0'+i+1));
        }
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};

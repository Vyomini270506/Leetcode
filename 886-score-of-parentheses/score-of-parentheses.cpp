class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for(char x : s) {
            if(x == '(') {
                st.push(0);
            }
            else {
                int a = st.top();
                st.pop();

                if(a == 0)
                    st.top() += 1;
                else
                    st.top() += 2 * a;
            }
        }

        return st.top();
    }
};
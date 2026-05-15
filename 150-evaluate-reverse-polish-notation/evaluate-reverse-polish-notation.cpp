class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1){
            return stoi(tokens[0]);
        }
        stack<int> st;
        int eval;
        reverse(tokens.begin(), tokens.end());
        int x = stoi(tokens.back());
        st.push(x);
        tokens.pop_back();
        x = stoi(tokens.back());
        st.push(x);
        tokens.pop_back();
        while(!st.empty() && !tokens.empty()){
            string o = tokens.back();
            tokens.pop_back();
            if(o == "+" || o == "-" || o == "*" || o == "/"){
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int r = 0;
                if(o == "+"){
                    r = op1 + op2;
                }
                else if(o == "-"){
                    r = op2 - op1;
                }
                else if(o == "*"){
                    r = op1 * op2;
                }
                else{
                    r = op2 / op1;
                }
                st.push(r);
            }
            else{
                st.push(stoi(o));
            }
        }

        int res = st.top();
        st.pop();

        if(st.empty()){
            return res;
        }
        else{
            return -400;
        }
    }
};
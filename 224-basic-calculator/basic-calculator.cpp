class Solution {
public:
    int prec(char c){
        if(c=='+' || c=='-') return 1;
        if(c=='*' || c=='/') return 2;
        else return 0;
    }
    int calculate(string s) {
        stack<int> values;
        stack<char> ops;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==' ') continue;
            if(isdigit(s[i])){
                long long num=0;
                while(i<n && isdigit(s[i])){
                    num=num*10+(s[i]-'0');
                    i++;
                }
                values.push(num);
                i--;
            }
            else if(s[i]=='('){
                ops.push(s[i]);
            }
            else if(s[i]==')'){
                while(ops.top()!='('){
                    long long op1=values.top();
                    values.pop();
                    long long op2=values.top();
                    values.pop();
                    char op=ops.top();
                    ops.pop();
                    if(op=='+'){
                        values.push(op2+op1);
                    }
                    else if(op=='-'){
                        values.push(op2-op1);
                    }
                    else if(op=='*'){
                        values.push(op2*op1);
                    }
                    else{
                        values.push(op2/op1);
                    }
                }
                ops.pop();
            }
            else{
                int j=i-1;
                while(j>=0 && s[j]==' '){
                    j--;
                }
                if((s[i]=='-' || s[i]=='+') &&
                    (j<0 ||
                        s[j]=='(' ||
                        s[j]=='+' ||
                        s[j]=='-' ||
                        s[j]=='*' ||
                        s[j]=='/'))
                    {
                        values.push(0);
                    }
                while(!ops.empty() && ops.top()!='(' &&
                  prec(ops.top()) >= prec(s[i])){
                    long long op1=values.top();
                    values.pop();
                    long long op2=values.top();
                    values.pop();
                    char op=ops.top();
                    ops.pop();
                    if(op=='+'){
                        values.push(op2+op1);
                    }
                    else if(op=='-'){
                        values.push(op2-op1);
                    }
                    else if(op=='*'){
                        values.push(op2*op1);
                    }
                    else{
                        values.push(op2/op1);
                    }

                  }
                    ops.push(s[i]);
                }
            }
            while(!ops.empty()){
                    long long op1=values.top();
                    values.pop();
                    long long op2=values.top();
                    values.pop();
                    char op=ops.top();
                    ops.pop();
                    if(op=='+'){
                        values.push(op2+op1);
                    }
                    else if(op=='-'){
                        values.push(op2-op1);
                    }
                    else if(op=='*'){
                        values.push(op2*op1);
                    }
                    else{
                        values.push(op2/op1);
                    }

                  }
                  return values.top();
        }
    
};
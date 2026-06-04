class Solution {
public:
    int wave(int x){
        string s=to_string(x);
        int c=0;
        int n=s.size();
        for(int i=1;i<n-1;i++){
            if((s[i]>s[i-1]&&s[i]>s[i+1]) || (s[i]<s[i-1]&&s[i]<s[i+1])){
                c++;
            }
        }
        return c;
    }
    int totalWaviness(int num1, int num2) {
        if(num2<100){
            return 0;
        }
        int s=0;

        for(int i=num1;i<=num2;i++){
            s+=wave(i);
        }
        return s;
    }
};
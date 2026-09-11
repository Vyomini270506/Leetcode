class Solution {
public:
    void num(vector<int>&digits,int&c,set<int>&x,vector<bool>&used){
        if(c>99&&c<1000&&c%2==0){
            x.insert(c);
            return;
        }

        if(c>999) return;

        for(int i=0;i<digits.size();i++){
            if(used[i]) continue;
            if(c==0&&digits[i]==0) continue;

            used[i]=true;
            c=c*10+digits[i];

            num(digits,c,x,used);

            c=c/10;
            used[i]=false;
        }
    }

    int totalNumbers(vector<int>&digits){
        set<int>x;
        vector<bool>used(digits.size(),false);
        int c=0;

        num(digits,c,x,used);

        return x.size();
    }
};
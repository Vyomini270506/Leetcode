class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> hash(n,1);
        for(int i=0;i<n;i++){
                if((i!=0 && ratings[i]>ratings[i-1])){
                    if(i!=0){
                        hash[i]=hash[i-1]+1;
                    }
                    else{
                        hash[i]++;
                    }
                }
        }
        for(int i=n-1;i>=0;i--){
                if((i!=n-1 && ratings[i]>ratings[i+1])){
                    if(i!=n-1){
                        hash[i] = max(hash[i], hash[i+1] + 1);
                    }
                    else{
                        hash[i]++;
                    }
                }
        }
        int ans=0;
        for(auto x:hash){
            ans+=x;
        }
        return ans;
    }
};
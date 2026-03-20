class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> m;
        int c=0;
        for(auto x:tasks){
            if(m[x]==0){
                c++;
            }
            m[x]++;
        }
        vector<pair<char,int>> vec(m.begin(),m.end());
        sort(vec.begin(),vec.end(),[](auto& a,auto& b){
            return a.second>b.second;
        });
        int x=vec[0].second;
        
        int ans=(x-1)*(n+1)+1;
        int l=vec.size();
        for(int i=1;i<l;i++){
            if(vec[i].second-x+1>0){
                ans+=1;
            }
        }
        return max(ans, (int)tasks.size());

    }
};
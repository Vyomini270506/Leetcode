class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int x : nums){
            pq.push(x*x);
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};

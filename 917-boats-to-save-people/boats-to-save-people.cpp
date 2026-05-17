class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int sum=0;
        sort(people.begin(),people.end());
        int i=0;
        int j=n-1;
        while(i<=j){
            if(i==j){
                sum+=1;
                break;
            }
            if(people[i]+people[j]<=limit){
                sum+=1;
                i++;
                j--;
            }
            else{
                sum+=1;
                j--;
            }
        }
        return sum;
    }
};
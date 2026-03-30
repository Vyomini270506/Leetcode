class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        vector<char> a1;
        vector<char> a2;
        vector<char> a3;
        vector<char> a4;
        for(int i=0;i<n;i++){
            if(i%2){
                a1.push_back(s1[i]);
                a3.push_back(s2[i]);
            }
            else{
                a2.push_back(s1[i]);
                a4.push_back(s2[i]);
            }
        }
        sort(a1.begin(),a1.end());
        sort(a2.begin(),a2.end());
        sort(a3.begin(),a3.end());
        sort(a4.begin(),a4.end());
        return (a1==a3) && (a2==a4);
    }
};
class Solution {
public:
    int product(int n){
        int res = 1;
        do{
            int a = n%10;
            res = res*a;
            n=n/10;
        }while(n>0);
        return res;
    }
    int smallestNumber(int n, int t) {
        int x = n;
        while(true){
            int b = product(x);
            if(b%t==0) return x;
            x++;
        }
        return -1;
    }
};
class Solution {
public:
    double myPow(double x, long long n) {
        if(n==0){
            return 1;
        }
        if(n>0){
            if(n%2==0){
                double t=myPow(x,n/2);
                return t*t;
            }
            else{
                return x*myPow(x,n-1);
            }
        }
        else{
            n=-n;
            return 1/myPow(x,n);
        }
    }
};
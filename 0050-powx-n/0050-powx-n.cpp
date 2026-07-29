class Solution {
public:
    double function(double x,long long n){
       if (n == 0) {
            return 1.0;
        }
        // for even
        if (n % 2 == 0) {
            return function(x * x, n / 2);
        }
        // for odd
        return x * function(x, n - 1);
    }
    double myPow(double x, int n) {
        long long power = n;
        if(power < 0){
            x = 1.0/x;
            power = -power;
        }
        return function(x,power);
    }
};
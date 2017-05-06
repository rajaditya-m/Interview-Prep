class Solution {
public:
    double pow(double x, int n)
    {
        double res = 1.0;
        while(n)
        {
            if(n%2!=0)
                if(n>0)
                    res = res * x;
                else
                    res = res / x;
            x = x*x;
            n /= 2;
        }
        return res;
    }
};
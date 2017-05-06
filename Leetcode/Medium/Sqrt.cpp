class Solution {
public:
    int sqrt(int x) {
        if(x==0)
            return 0;
        double x0 = 10;
        for(int iter=0;iter<25;iter++)
        {
            double fx = (x0*x0)-(double)x;
            double dfx = 2*x0;
            x0 = x0 - (fx/dfx);
        }
        return (int)x0;
    }
};
class Solution {
public:
    int climbStairs(int n) {
        int a=1;
        int b=2,c;
        if(n==1)
            return a;
        if(n==2)
            return b;
        for(int i=3;i<=n;i++)
        {
            c = a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
class Solution {
public:
    int maxProduct(int A[], int n) {
        int maxPdk = A[0];
        int lastMaxPdk = A[0];
        int lastMinPdk = A[0];
        for(int i=1;i<n;i++)
        {
            int cmin = std::min(std::min(lastMinPdk*A[i],lastMaxPdk*A[i]),A[i]);
            int cmax = std::max(std::max(lastMinPdk*A[i],lastMaxPdk*A[i]),A[i]);
            maxPdk = std::max(maxPdk,cmax);
            lastMaxPdk = cmax;
            lastMinPdk = cmin;
        }
        return maxPdk;
    }
};
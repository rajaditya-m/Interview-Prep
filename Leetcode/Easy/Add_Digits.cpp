class Solution {
public:
    int addDigits(int num) {
        int test = num/10;
        if(!test)
            return num;
        else {
            int sum = 0;
            while(num){
                sum += (num%10);
                num /= 10;
            }
            return addDigits(sum);
        }
    }
};
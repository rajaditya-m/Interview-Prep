class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();
        std::vector<int> result;
        result.resize(len+1);
        int carry = 1;
        for(int i=len-1;i>=0;i--)
        {
            int newSum = digits[i]+carry;
            int newDig = newSum%10;
            carry = newSum/10;
            result[i+1] = newDig;
        }
        if(carry)
        {
            result[0] = carry;
        }
        else
        {
            result.erase(result.begin());
        }
        return result;
    }
};
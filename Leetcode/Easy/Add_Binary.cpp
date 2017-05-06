class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        int lena = a.length();
        int lenb = b.length();
        if(lena<lenb)
        {
            std::string temp;
            int tempi;
            temp = a;
            a = b;
            b = temp;
            tempi = lena;
            lena = lenb;
            lenb = tempi;
        }
        //Pad with leading 0
        int diff = lena-lenb;
        std::string zero("0");
        while(diff)
        {
            b = zero + b;
            diff--;
        }
        int c = 0;
        std::string res;
        for(int i=lena-1;i>=0;i--)
        {
            int x = a[i]-'0';
            int y = b[i]-'0';
            int s = x^y^c;
            c = (x&y)|(x&c)|(y&c);
            char z = s +'0';
            res = z + res;
        }
        if(c)
        {
            std::string one("1");
            res = '1' + res;
        }
        return res;
    }
};
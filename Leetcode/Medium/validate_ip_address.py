class Solution(object):
    def validIPAddress(self,IP):
        split_dot = IP.split('.')
        split_colon = IP.split(':')
        print(split_dot)
        print(split_colon)
        if (len(split_dot)==1):
            return self.validateIPV6(split_colon)
        elif (len(split_colon)==1):
            return self.validateIPV4(split_dot)
        else:
            return "Neither"

    def validateIPV4Tokens(self,token):
        if not token:
            return False
        #first there should be nothing but numbers
        power = 0
        num = 0
        leading_zeros = 0
        for chars in token[::-1]:
            char_rep = ord(chars)
            dig_rep = char_rep - ord('0')
            if dig_rep >= 0 and dig_rep < 10:
                num += ((10**power)*dig_rep)
                power += 1
                if dig_rep == 0:
                    leading_zeros += 1
                else:
                    leading_zeros = 0
            else:
                return False
        if num > 255:
            return False
        if leading_zeros > 0:
            if leading_zeros == 1 and num == 0:
                return True
            else:
                return False
        # print(num)
        return True


    def validateIPV4(self,list_str):
        if(len(list_str)!=4):
            return "Neither"
        for toks in list_str:
            if not self.validateIPV4Tokens(toks):
                return "Neither"
        return "IPv4"

    def validateIPV6Tokens(self,token):
        if not token:
            return False
        if(len(token)>4):
            return False
        n_valid_toks = 0
        for chars in token:
            char_rep = ord(chars)
            dig_rep = char_rep-ord('0')
            uc_rep = char_rep-ord('A')
            lc_rep = char_rep-ord('a')
            if ((dig_rep>=0 and dig_rep<10) or (uc_rep>=0 and uc_rep<6) or (lc_rep>=0 and lc_rep<6)):
                n_valid_toks += 1
            else:
                return False
        return True
        

    def validateIPV6(self,list_str):
        if(len(list_str)!=8):
            return "Neither"
        for toks in list_str:
            if not self.validateIPV6Tokens(toks):
                # print(toks)
                return "Neither"
        return "IPv6"




ipd = '2001:0db8:85a3:0000:0:8A2E:0370:7334'

solObj = Solution()
print(solObj.validIPAddress(ipd))

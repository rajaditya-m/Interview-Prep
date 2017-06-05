class BinaryTree:

    def __init__(self, idx):
        self.left = None
        self.right = None
        self.idx = idx

    def __repr__(self):
        return str(self.idx)

class Solution:

    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cntr = 0
        root = BinaryTree(cntr)
        list_bv = []

        maxXor = -1
        #create the false trie 
        for idx, num in enumerate(nums):
            binary_str = self.create32BitPaddedBinary(num)
            list_bv.append(binary_str)
            cntr = self.insertToTree(root, binary_str, idx, cntr)

        for binary_vecs in list_bv:
            new_binary_vec = self.searchTrieWithNumber(root, binary_vecs)
            curNum = self.convertBinVecToInt(binary_vecs)
            xorNum = self.convertBinVecToInt(new_binary_vec)
            xorVal = curNum^xorNum
            maxXor = max(xorVal, maxXor)
            # print('{}^{}={}'.format(curNum, xorNum, curNum^xorNum))
        
        return maxXor

    def convertBinVecToInt(self, binary_vec):
        mult = 1
        num = 0
        for dig in binary_vec[::-1]:
            if(dig=='1'):
                num += mult
            mult *= 2
        return num

    def searchTrieWithNumber(self, root, num_vec):
        new_bit_vec = []
        curNumTreePtr = root
        curMaxTreePtr = root
        for bit in num_vec:
            if bit == '0':
                if curMaxTreePtr.right:
                    new_bit_vec.append('1')
                    curMaxTreePtr = curMaxTreePtr.right
                else:
                    new_bit_vec.append('0')
                    curMaxTreePtr = curMaxTreePtr.left
                curNumTreePtr = curNumTreePtr.left
            if bit == '1':
                if curMaxTreePtr.left:
                    new_bit_vec.append('0')
                    curMaxTreePtr = curMaxTreePtr.left
                else:
                    new_bit_vec.append('1')
                    curMaxTreePtr = curMaxTreePtr.right
                curNumTreePtr = curNumTreePtr.right
        return new_bit_vec
            

    def insertToTree(self, root, binary_str, idx, cntrr):
        if not binary_str:
            return cntrr
        cur_elem = binary_str[0]
        rem = binary_str[1:]
        #root.lineage.append(idx)
        if(cur_elem=='0'):
            if not root.left:
                cntrr += 1
                root.left = BinaryTree(cntrr)
                # print('CLN')
            return self.insertToTree(root.left, rem, idx, cntrr)
        else:
            if not root.right:
                cntrr += 1
                root.right = BinaryTree(cntrr)
                # print('CRN')                
            return self.insertToTree(root.right, rem, idx, cntrr)
            
    
    def create32BitPaddedBinary(self, num):
        """
        :type num: int
        :rtype: string
        """
        rev_binary_str = []
        while(num):
            if num%2:
                rev_binary_str.append('1')
            else:
                rev_binary_str.append('0')
            num = int(num/2)

        rem = 32 - len(rev_binary_str) 
        pad_zeros = ['0']*rem
        rev_binary_str.extend(pad_zeros)
        binary_str = rev_binary_str[::-1]
        return binary_str

#input = [3, 10, 5, 25, 2, 8]
input = [32,18,33,42,29,20,26,36,15,46]
obj = Solution()
print(obj.findMaximumXOR(input))
# obj.findMaximumXOR(input)
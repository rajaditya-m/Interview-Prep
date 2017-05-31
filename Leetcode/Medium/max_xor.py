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
        #create the false trie 
        for idx, num in enumerate(nums):
            binary_str = self.create32BitPaddedBinary(num)
            # print(binary_str)
            cntr = self.insertToTree(root, binary_str, idx, cntr)
        #print('0: {}'.format(root))
        #print('1: {} 2:{}'.format(root.left, root.right))
        #print('3: {} 4:{} 5:{} 6:{}'.format(root.left.left, root.left.right, root.right.left, root.right.right))
        # #climbing down together 
        left = right = root
        leftVec = []
        rightVec = []
        hght = 0
        while left and right:
            if left == right:
                #print('Before {} {}'.format(left,right))
                if left.left and not left.right:
                    left = right = left.left
                    leftVec.append('0')
                    rightVec.append('0')
                elif left.right and not left.left:
                    left = right = left.right
                    leftVec.append('1')
                    rightVec.append('1')
                elif left.right and left.left:
                    # print('Before {} {}'.format(left,right))
                    left = left.left
                    right = right.right
                    leftVec.append('0')
                    rightVec.append('1')
                    # print('After {} {}'.format(left,right))
                    # print(hght)
                else:
                    left = right = None
                    # print('hhhh'+str(hght))
                    # print(hght)
                #print(hght)
                #print('After {} {}'.format(left,right))
            else:
                # if hght==1:
                #     print(left.left, left.right)
                #     print(right.left, right.right)
                if left.left and right.right:
                    left = left.left
                    leftVec.append('0')
                    right = right.right
                    rightVec.append('1')
                    #print(hght)
                elif left.right and right.left:
                    left = left.right
                    leftVec.append('1')
                    right = right.left
                    rightVec.append('0')
                    # print(hght)
                elif left.left and right.left:
                    left = left.left
                    leftVec.append('0')
                    right = right.left
                    rightVec.append('0')
                elif left.right and right.right:
                    left = left.right
                    leftVec.append('1')
                    right = right.right
                    rightVec.append('1')
                else:
                    left = right = None
                    # print('gggg'+str(hght))
            hght += 1
        # print('left[{}]:{}'.format(len(leftVec),leftVec))
        # print('rght[{}]:{}'.format(len(rightVec),rightVec))
        lv = self.convertBinVecToInt(leftVec)
        rv = self.convertBinVecToInt(rightVec)
        return lv^rv


    def convertBinVecToInt(self, binary_vec):
        mult = 1
        num = 0
        for dig in binary_vec[::-1]:
            if(dig=='1'):
                num += mult
            mult *= 2
        return num

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
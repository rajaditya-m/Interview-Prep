class BinaryTree:

    def __init__(self):
        self.left = None
        self.right = None
        self.lineage = []

class Solution:

    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        root = BinaryTree()
        #create the false trie 
        for idx, num in enumerate(nums):
            binary_str = self.create32BitPaddedBinary(num)
            self.insertToTree(root, binary_str, idx)
        #now time to find the least common ancestor 

    def insertToTree(self, root, binary_str, idx):
        if not binary_str:
            return root
        cur_elem = binary_str[0]
        rem = binary_str[1:]
        root.lineage.append(idx)
        if(cur_elem=='0'):
            if not root.left:
                root.left = BinaryTree()
            self.insertToTree(root.left, rem, idx)
        else:
            if not root.right:
                root.right = BinaryTree()
            self.insertToTree(root.right, rem, idx)
            
    
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

input = [3, 10, 5, 25, 2, 8]
# input = [3]
obj = Solution()
obj.findMaximumXOR(input)
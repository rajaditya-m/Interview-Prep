class BinaryTree:
    
    def __init__(self, root_node = None):
        # Check out Use Me section to find out Node Structure
        self.root = root_node
    
    def insert(self,root,data):
        # Return the new root
        if not root:
            return TreeNode(data)
        if data<=root.data:
            if not root.left_child:
                root.left_child = TreeNode(data)
            else:
                _ = self.insert(root.left_child, data)
        else:
            if not root.right_child:
                root.right_child = TreeNode(data)
            else:
                _ = self.insert(root.right_child,data)
        return root

    def po(self,root):
        if not root:
            return 
        print(root.data)
        self.po(root.left_child)
        self.po(root.right_child)

class TreeNode:
    def __init__(self, data,left_child = None, right_child = None):
        self.data = data
        self.left_child = left_child
        self.right_child = right_child
    
    def __str__(self):
        return '%s' %self.data

obj = BinaryTree()
r1 = obj.insert(obj.root,4)
# obj.po(r1)
r2 = obj.insert(r1,2)
# obj.po(r2)
r3 = obj.insert(r2,8)
# obj.po(r3)
r4 = obj.insert(r3,5)
# obj.po(r4)
r5 = obj.insert(r4,10)
obj.po(r5)
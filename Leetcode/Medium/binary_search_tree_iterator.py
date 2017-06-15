class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.cur = root
        self.stack = []
        

    def hasNext(self):
        """
        :rtype: bool
        """
        return True if self.cur or self.stack else False

    def next(self):
        """
        :rtype: int
        """
        while self.cur:
            self.stack.append(self.cur)
            self.cur = self.cur.left
        iterVal = self.stack.pop()
        self.cur = iterVal.right
        return iterVal.val
        
class Solution(object):
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        table = {}
        ans = []
        for item in paths:
            l1 = item.split(' ')
            n_files = len(l1)-1
            for i in range(n_files):
                file_item = l1[i+1]
                ob_inx = file_item.find('(')
                cb_inx = file_item.find(')')
                fname = file_item[0:ob_inx]
                content = file_item[ob_inx+1:cb_inx]
                fpath = l1[0] + '/' + fname
                if not content in table:
                    table[content]  = [fpath]
                else:
                    table[content].append(fpath)
                # table[content] = table.get(content,[]).append(fpath)
        for key,value in table.items():
            if len(value)>1:
                ans.append(value)
        return ans


l = ["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]

obj = Solution()
print(obj.findDuplicate(l))

import queue 

class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        interval_cntr = 0
        char_count = [0]*26
        for ch in tasks:
            char_count[ord(ch)-ord('A')] += 1
        max_heap = queue.PriorityQueue()
        for idx,elem in enumerate(char_count):
            if elem:
                max_heap.put(-elem)
        tmp = []
        while tmp or not max_heap.empty():
            #empty cycle 
            cntr = n+1 
            tmp = []
            while cntr:
                if not max_heap.empty():
                    top = max_heap.get()
                    if top+1 <0:
                        tmp.append(top+1)
                else:
                    if not tmp:
                        break
                interval_cntr += 1
                cntr -= 1
            print(interval_cntr)
            # fill cycle
            for elem in tmp:
                max_heap.put(elem)
        # print(interval_cntr)
        return interval_cntr
            
                
                
                    
                
                    




obj = Solution()
A = ['A','A','A','B','B','B']
obj.leastInterval(A,2)
import random

class SkipNode:
    def __init__(self,num_levels,value=None):
        self._value = value 
        self._next = [None]*num_levels
    
    def is_header(self):
        return not isinstance(self._value,int)

class SkipList:
    def __init__(self):
        self._max_num_levels = 4
        self._head = SkipNode(self._max_num_levels)
        self._current_num_levels = 1

    def flip_a_coin(self):
        prob = random.random()
        return True if prob<0.5 else False

    def get_num_levels(self):
        level = 0
        while self.flip_a_coin() and level<self._max_num_levels-1:
            level += 1
        return level

    def dbg__print(self):
        for level in range(self._current_num_levels-1,-1,-1):
            elems = []
            cur = self._head._next[level]
            while cur:
                if not cur.is_header():
                    elems.append(cur._value)
                cur = cur._next[level]
            print('Level {} Elem {}'.format(level,elems))
            
            
    def insert(self, val):
        #traverse from top level
        prev_nodes = [None]*self._current_num_levels
        cur = self._head
        for level in range(self._current_num_levels-1,-1,-1):
            while cur._next[level] and cur._next[level]._value<val:
                cur = cur._next[level]
            prev_nodes[level] = cur
        # print(prev_nodes)
        #at this point update nodes should have all the traversal paths
        rand_level = self.get_num_levels()
        if rand_level >= self._current_num_levels:
            new_levels = rand_level + 1 - self._current_num_levels
            for i in range(new_levels):
                self._head._next.append(None)
                prev_nodes.append(self._head) 
            self._current_num_levels = rand_level + 1
        elem_node = SkipNode(rand_level+1,val)
        for level in range(0,rand_level+1):
            #insertion same as a linked list node 
            elem_node._next[level] = prev_nodes[level]._next[level]
            prev_nodes[level]._next[level] = elem_node
        print('Inserted {} till level {}'.format(val,rand_level))





#testing 
sp_l = SkipList()
sp_l.insert(3)
sp_l.dbg__print()
sp_l.insert(5)
sp_l.insert(2)
sp_l.dbg__print()
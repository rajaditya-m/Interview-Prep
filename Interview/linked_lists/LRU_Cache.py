class DLLNode:
    def __init__(self, key, value):
        self._key = key
        self._value = value
        self._next = None
        self._prev = None
    
    def modify_value(self, newval):
        self._value = newval
    
class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self._capacity = capacity
        self._nelem = 0
        self._dict = {}
        self._head = None
        self._tail = None

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key in self._dict:
            node = self._dict[key]
            self._remove(node)
            self._add_to_front(node)
            return node._value
        return -1
        

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        node = None
        if key in self._dict:
            node = self._dict[key]
            self._remove(node)
            node.modify_value(value)
            self._add_to_front(node)
        else:
            node = DLLNode(key,value)
            if self._nelem==self._capacity:
                removed_data = self._tail._key
                del self._dict[removed_data]
                self._remove(self._tail)
                self._nelem -= 1
            self._add_to_front(node)
            self._dict[key] = node
            self._nelem += 1
                
    def _remove(self, node):
        prev = node._prev
        nxt = node._next
        node._prev = None
        node._next = None
        if prev:
            prev._next = nxt
        if nxt:
            nxt._prev = prev
        if not prev:
            self._head = nxt
        if not nxt:
            self._tail = prev
    
    def _add_to_front(self, node):
        if not self._head:
            self._head = self._tail = node
        else:
            self._head._prev = node
            node._next = self._head
            self._head = node
            
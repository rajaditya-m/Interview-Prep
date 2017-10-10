class SinglyLinkedList:
    #constructor
    def __init__(self):
        self.head = None
        
    #method for setting the head of the Linked List
    def setHead(self,head):
        self.head = head
        
    def printl(self):
        cur = self.head
        a = []
        while cur:
            a.append(cur.data)
            cur = cur.next
        print(a)
                     
    def arrange_in_pairs(self):
        start = self.head
        end_prev = None 
        end = start
        ctr = 4
        while start:
            while end and end.next:
                end_prev = end 
                end = end.next
            if start.next == end:
                return
            print('start:{}'.format(start.data))
            print('end:{}'.format(end.data))
            next_start = start.next 
            if end_prev:
                end_prev.next = None 
            else:
                return 
            start.next = end 
            end.next = next_start
            start = end = next_start
            
            end_prev = end
            print('fff')
            self.printl()
        return 

class Node:
    def __init__(self):
        self.data = None
        self.next = None
     
    def setData(self,data):
        self.data = data
      
    def getData(self):
        return self.data
     
    def setNext(self,next):
        self.next = next
     
    def getNext(self):
        return self.next

ll = SinglyLinkedList()
n1 = Node()
n1.setData(1)
n2 = Node()
n2.setData(2)
n3 = Node()
n3.setData(3)
n4 = Node()
n4.setData(4)
n1.next = n2
n2.next = n3
n3.next = n4
ll.setHead(n1)
ll.arrange_in_pairs()
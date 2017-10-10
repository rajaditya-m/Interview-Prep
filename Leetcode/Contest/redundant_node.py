import queue
class Solution(object):
    def find(self, pred, i):
        if pred[i] == i:
            return i
        return self.find(pred, pred[i])

    def merge_trees(self, pred, rank, a, b):
        aroot = self.find(pred, a)
        broot = self.find(pred, b)
 
        if rank[aroot] < rank[broot]:
            pred[aroot] = broot
        elif rank[aroot] > rank[broot]:
            pred[broot] = aroot
        else :
            pred[broot] = aroot
            rank[aroot] += 1

    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        v_dict = {}
        v_inv_dict = {}
        counter = 0
        remapped_edges = []
        for edge in edges:
            u = edge[0]
            v = edge[1]
            un, vn = -1,-1
            if not u in v_dict:
                v_dict[u] = counter
                v_inv_dict[counter] = u
                counter += 1
            un = v_dict[u]
            if not v in v_dict:
                v_dict[v] = counter
                v_inv_dict[counter] = v
                counter += 1
            vn = v_dict[v]    
            remapped_edges.append([un,vn])
        # print(remapped_edges)
        n_verts = counter
        # print(n_verts)
        #Our verts are alrady in sorted order for kruskals 
        result = []
        pred = []
        rank = []
        for n in range(n_verts):
            pred.append(n)
            rank.append(0)
        n_edges = 0
        i = 0
        rejected_edges = []
        while n_edges<n_verts-1:
            u,v = remapped_edges[i]
            up = self.find(pred, u)
            vp = self.find(pred ,v)
            if up != vp:
                n_edges = n_edges + 1  
                result.append(i)
                self.merge_trees(pred, rank, up, vp)
            else:
                rejected_edges.append(i)   
            i += 1
        ans = i
        if i==len(edges): 
            ans = rejected_edges[-1]
        ans_u = remapped_edges[ans][0]
        ans_v = remapped_edges[ans][1]
        return [v_inv_dict[ans_u],v_inv_dict[ans_v]]
        

obj = Solution()
e  = [[1,2], [1,3], [3,1]]
print(obj.findRedundantConnection(e))
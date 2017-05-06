/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    std::unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> table;

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
        {
            return NULL;
        }
        UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
        table.insert(std::pair<UndirectedGraphNode*,UndirectedGraphNode*>(node,newNode));
        int n = (node->neighbors).size();
        for(int i=0;i<n;i++)
        {
            auto it = table.find(node->neighbors[i]);
            if(it==table.end())
            {
                UndirectedGraphNode* nClone = cloneGraph(node->neighbors[i]);
                table.insert(std::pair<UndirectedGraphNode*,UndirectedGraphNode*>(node->neighbors[i],nClone));
                (newNode->neighbors).push_back(nClone);
            }
            else
            {
                (newNode->neighbors).push_back(it->second);
            }
        }
        return newNode;
    }
};
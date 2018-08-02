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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==nullptr) return nullptr;
        unordered_map<int, UndirectedGraphNode*> nodes;
        unordered_set<int> visited;
        auto ans = new UndirectedGraphNode(node->label);
        dfs(node, ans, nodes, visited);
        return ans;
    }
private:
    void dfs(UndirectedGraphNode *ori, UndirectedGraphNode*&ans, unordered_map<int, UndirectedGraphNode*>& nodes,
             unordered_set<int>& visited) {
        visited.insert(ori->label);
        for(auto nb: ori->neighbors) {
            if(nb==ori) {
                ans->neighbors.push_back(ans);
                continue;
            }
            if(nodes.find(nb->label)==nodes.end()) {
                auto tmp = new UndirectedGraphNode(nb->label);
                nodes[nb->label] = tmp;
            }
            ans->neighbors.push_back(nodes[nb->label]);
            if(visited.find(nb->label)!=visited.end())
                continue;
            dfs(nb, nodes[nb->label], nodes, visited);
        }
    }
};
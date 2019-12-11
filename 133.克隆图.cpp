/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
//bfs 还要消化一下      
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        map<Node* ,Node*>mymap;
        queue<Node*>myqueue;
        myqueue.push(node);
        Node*clone=new Node(node->val,vector<Node*>(0,nullptr));
        mymap[node]=clone;
        while(!myqueue.empty()){
            Node* old_ptr=myqueue.front();
            myqueue.pop();
            //bfs
            for(auto old_nei:old_ptr->neighbors){
                if(!mymap.count(old_nei)){
                    Node * clone =new Node(old_nei->val,vector<Node*>(0,nullptr));
                    mymap[old_nei]=clone;
                    myqueue.push(old_nei);
                }   
                mymap[old_ptr]->neighbors.push_back(mymap[old_nei]);
            }    
        }
        return mymap[node];
    }
};
// @lc code=end


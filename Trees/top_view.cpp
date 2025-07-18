/*
Top View of Binary Tree

You are given a binary tree, and your task is to return its top view. The top 
view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Return the nodes from the leftmost node to the rightmost node.
If two nodes are at the same position (horizontal distance) and are 
outside the shadow of the tree, consider the leftmost node only. 

struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int>v;
        if(!root) return v;
        map<int,int>m;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* tree=it.first;
            int line=it.second;
            if(m.find(line)==m.end()) m[line]=tree->data;
            if(tree->left) q.push({tree->left,line-1});
            if(tree->right) q.push({tree->right,line+1});
            
        }for(auto it:m){
            v.push_back(it.second);
        }return v;
        
    }
};
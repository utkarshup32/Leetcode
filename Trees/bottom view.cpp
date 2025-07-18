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
            m[line]=tree->data;                             //only difference with top view
            if(tree->left) q.push({tree->left,line-1});
            if(tree->right) q.push({tree->right,line+1});
            
        }for(auto it:m){
            v.push_back(it.second);
        }return v;
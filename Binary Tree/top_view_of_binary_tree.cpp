 // problem link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
    // just like in right and left view binary tree we did level order traversal
    // similarly we will do vertical order traversal for top and bottom view
    // refer vertical sum and vertical traversal questions
    

  
  void verticalTraversal(Node* root, map<int, int> &mp)
    {
        queue<pair<Node *, int>> q; // node as key and horizontal dist from root as value
        q.push({root, 0});
        
        while(q.size() != 0)
        {
            int count = q.size();
            for(int i=0; i<count; i++)
            {
                auto top = q.front();
                Node* curr = top.first;
                int horizontalDist = top.second;
                if(mp.find(horizontalDist) == mp.end()) 
                {
                    //cout<<horizontalDist<<endl;
                    mp[horizontalDist] = curr->data;
                    //cout<<"hi"<<mp[horizontalDist]<<endl;
                }
                q.pop();
                
                if(curr -> left) q.push({curr->left, horizontalDist - 1});
                if(curr -> right) q.push({curr->right, horizontalDist + 1});
            }
            
        }
    }
    
    vector<int> topView(Node *root)
    {
        map<int, int> mp;
        verticalTraversal(root, mp);
        
        vector <int> ans;
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
    
    }
